/*Write three functions swap_v(int, int), swap_r(int&, int&), and swap_cr(const int& const int&). Try multiple values.*/

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

void swap_v(int, int);
void swap_r(int&, int&);

int main()
{
    int x = 7;
    int y = 9;

    const int cx = 7;
    const int cy = 9;

    double dx = 7.7;
    double dy = 9.9;

    cout << "\n\n\t" << cx << "\t" << cy << '\n';
    swap_v(7.7,9.9);
    cout << "\n\n\t" << cx << "\t" << cy << '\n';
    
    return 0;
}


// Swap ints.
void swap_v(int a, int b)
{
    cout << "\n\n\t" << a << "\t" << b << '\n';
    
    int temp;
    temp = a;
    a = b;
    b = temp;
    
    cout << "\n\n\t" << a << "\t" << b << '\n';

    return;
}

// Swap references.
void swap_r(int& a, int& b)
{
    //cout << "\n\n\t" << a << "\t" << b << '\n';
    
    int temp;
    temp = a;
    a = b;
    b = temp;

    //cout << "\n\n\t" << a << "\t" << b << '\n';

    return;
}

// Swap const references.
/*void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    return;
}*/