// Program to illustrate the getopt()
// function in C
#include <iostream>
#include <getopt.h>
#include <stdio.h> 
#include <unistd.h> 

using namespace std;

void display_uppercase_string(string text) {
    char ch;
    int text_length = text.length();

    cout << "The uppercase version of \"" << text << "\" is " << endl;

    for (int i = 0; i <= text_length; i++) {

        // convert str[i] to uppercase
        ch = toupper(text[i]);


        cout << ch;
    }
    cout << endl;
}

void display_lowercase_string(string text) {
    char ch;
    int text_length = text.length();
    cout << "The lowercase version of \"" << text << "\" is " << endl;

    for (int i = 0; i <= text_length; i++) {

        // convert str[i] to uppercase
        ch = tolower(text[i]);


        cout << ch;
    }
    cout << endl;
}

void display_string(string text) {

    cout << "Entered string is" << endl;
    cout << text << endl;
}

void display_help() {
    cout << "Parameters:" << endl
    << "   -h, --help        display this information and exit" << endl
    << "   -p, --print       print string" << endl
    << "   -u, --upper       upercase given string" << endl
    << "   -l, --lower       lowercase given string" << endl
    << endl;
}

void display_command_result(bool help, bool print, string print_arg, bool uppercase, string upper_arg, bool lowercase, string lower_arg) {

    if (help) {
        display_help();
    }
    if (print) {
        display_string(print_arg);
    }
    if (uppercase) {
        display_uppercase_string(upper_arg);
    }
    if (lowercase) {
        display_lowercase_string(lower_arg);
    }
}

int main(int argc, char *argv[]) 
{
    int opt;
    int index = 0;
    string inFile = "";
    string outFile = "";
    
    bool h_used = false;
    bool p_used = false;
    bool u_used = false;
    bool l_used = false;

    string p_arg = "";
    string u_arg = "";
    string l_arg = "";

    const struct option longopts[] =
    {
        {"help", no_argument, 0, 'h'},
        {"print", required_argument, 0, 'p'},
        {"upper", required_argument, 0, 'u'},
        {"lower", required_argument, 0, 'l'},
        {0,0,0,0}
    };

    while((opt = getopt_long(argc, argv, "hp:u:l:", longopts, &index)) != -1) 
    { 
        switch(opt) 
        { 
            case 'h':
                h_used = true;
                break;
            case 'p':
                p_used = true;
                p_arg = optarg;
                break;
            case 'u':
                u_used = true;
                u_arg = optarg;
                break; 
            case 'l':
                l_used = true;
                l_arg = optarg;
                break;
            case '?': 
                printf("Unknown option: %c\n", optopt);
                break; 
        }

    }

    display_command_result(h_used, p_used, p_arg, u_used, u_arg, l_used, l_arg);

    for(; optind < argc; optind++){     
        printf("Extra arguments: %s\n", argv[optind]); 
    }
      
    return 0;
}