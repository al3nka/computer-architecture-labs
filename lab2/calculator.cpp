#include "calculator.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace std;

double Calculator::Add (double a, double b)
{
	return a + b;
}

double Calculator::Sub (double a, double b)
{
    return Add (a, -b);
}

double Calculator::Mul (double a, double b)
{
    return a * b;
}

double Calculator::Div (double a, double b)
{
    if (b == 0) {
        cerr << "Division by zero" << endl;
        throw std::exception();
    }
    return a / b;
}

double Calculator::Pow (double a, double b)
{
    return pow(a, b);
}
