/*Determine the size of char, int, int*, bool, double and a couple of strings.*/

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
int main()
{
    bool b{true};
    char c{'c'};    
    string s1{"str"};
    string s2{"string 2"};

    int in{1000};
    int* ain{&in};

    double d{1.5};
    double* adb{&d};

    // The sizeof operator.

    cout << "\n\n\t";
    cout << "The size of bool is " << sizeof(bool) << ' ' << sizeof(b) << "\n\t";
    cout << "The size of char is " << sizeof(char) << ' ' << sizeof(c) << "\n\t";
    cout << "The size of string is " << sizeof(string) << ' ' << sizeof(s1)
         << "\n\t";
    cout << "The size of string is " << sizeof(string) << ' ' << sizeof(s2)
         << "\n\t";

    cout << "The size of int is " << sizeof(int) << ' ' << &in << "\n\t";
    cout << "The size of int pointer is " << sizeof(int*) << ' ' << sizeof(ain)
         << "\n\t";

    cout << "The size of double is " << sizeof(double) << ' ' << &d
         << "\n\t";
    cout << "The size of double pointer is " << sizeof(double*) << ' '
         << adb << "\n\t";

    return 0;
}

//------------------------------------------------------------------------------
