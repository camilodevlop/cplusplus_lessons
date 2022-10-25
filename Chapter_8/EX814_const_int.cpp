/*Declare a non-reference function argument const (e.g., void f(const int);). Try it; write a couple of small
programs to see what works.*/

#include <iostream>
#include <string>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

void f(const int);

//------------------------------------------------------------------------------

int main()
{
    int num = 7;
    f(num);
    return 0;
}

//------------------------------------------------------------------------------

void f(const int i)
{
    cout << "\n\n\tThe const number is: " << i << "\n\t";
    return;
}

//------------------------------------------------------------------------------