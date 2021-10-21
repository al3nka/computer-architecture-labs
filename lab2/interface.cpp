// UserInterface.cpp

#include <iostream>
#include <stdexcept>
#include <string>

#include "calculator.h"

using namespace std;

void displayMenu();
void displayResult(double, double, char, double);

int main(int argc, char** argv)
{
  bool done = false;
  Calculator calculator;
  while (!done) {
    double a;
    double b;
    char selection;
    displayMenu();
    cin >> a >> selection >> b;
    switch (selection) {
    case '+':
      displayResult(a, b, selection, calculator.Add(a, b));
      break;
    case '-':
      displayResult(a, b, selection, calculator.Sub(a, b));
      break;
    case '*':
      displayResult(a, b, selection, calculator.Mul(a, b));
      break;
    case '/':
      displayResult(a, b, selection, calculator.Div(a, b));      
      break;
    case '^':
      displayResult(a, b, selection, calculator.Pow(a, b));      
      break;
    case 'q':
      done = true;
      cout << "Quiting..."<< endl;
      break;
    default:
      cerr << "Unknown command." << endl;
      throw exception();
    }
  }
  cout << "Bye!"<< endl;
}

void displayMenu()
{
  cout << endl;
  cout << "\nCalculions" << endl;
  cout << "-----------------" << endl;
  cout << "Use: " << endl;
  cout << "+ to add" << endl;
  cout << "- to substract" << endl;
  cout << "* to multiply" << endl;
  cout << "/ to ivide" << endl;
  cout << "^ to exponentiate" << endl;
  cout << "q to quit(write any number before and after 'q')" << endl;
  cout << "Input expression" << endl;
  cout << endl;
  cout << "---> ";
}

void displayResult(double a, double b, char e, double result)
{
  cout << endl;
  cout << "\nResult" << endl;
  cout << "-----------------" << endl;
  cout << to_string(a) << " " << e << " " << to_string(b) << " = " << to_string(result) << endl;
  cout << "-----------------" << endl;
}
