/*Write a function maxv() that returns the lasgest element of a vector argument.*/

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

int maxv(const vector<int>&);

int main()
{
    vector<int> values;

    int v;                                   // Catch the current value.

        cout << "\n\n\tEnter value (type Ctrl + D to finish):\n\n\t";
        while (cin >> v)
        {
            values.push_back(v);
            cout << '\t';
        }
    
    cout << "\n\n\tThe largest value is:\t" << maxv(values) << "\n\t";
    
    return 0;
}

int maxv(const vector<int>& ve)
{
    int mv = ve[0];
    
    for (int i = 1; i < ve.size(); i++)
        if (ve[i] > mv)
            mv = ve[i];
    
    return mv;
}