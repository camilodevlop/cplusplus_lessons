/*Write a program using a single file containing three namespaces X, Y, and Z. Each namespace needs to define a variable
called var and a function called print that outputs the appropriate var using cout.*/

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

namespace X
{
    int var;
    
    void print()
    {
        cout << "\n\n\tVar X = " << var << '\n';
        return;
    }
}

namespace Y
{
    int var;
    void print()
    {
        cout << "\n\n\tVar Y = " << var << '\n';
        return;
    }
}

namespace Z
{
    int var;
    void print()
    {
        cout << "\n\n\tVar Z = " << var << '\n';
        return;
    }
}


int main()
{
    X::var = 7;
    X::print();                 // Print X's var.

    using namespace Y;
    var = 9;
    print();                    // Print Y's var.

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();                // Print Z's var.
    }

    print();                    // Print Y's var.
    X::print();                 // Print X's var.

    return 0;
}