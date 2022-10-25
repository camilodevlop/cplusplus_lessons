/*Chapter 8 Drill 1: use of header files and cpp files.*/

#include <iostream>
#include "my.h"
#include "std_lib_facilities.h"

using namespace std;

int foo;

void printfoo()
{
    cout << "\n\n\t" << foo << '\n';
    return;
}

void print(int i)
{
    cout << "\n\n\t" << i << '\n';
    return;
}