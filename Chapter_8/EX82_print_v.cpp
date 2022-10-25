/*Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for "labeling" the output
and a vector.*/

#include <iostream>
#include <string>
#include <vector>

#include "std_lib_facilities.h"

using namespace std;

void print(string, vector<int>);

int main()
{
    vector<int> vp;
    int size = 1000;
    for (int i = 0; i < size; i++)
        vp.push_back(i);
    
    print("Vector_prueba:", vp);
    return 0;
}

void print(string s, vector<int> v)
{
    cout << "\n\n\t" << s << "\n\n\t";
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 10 == 0)
            cout << "\n\n\t";
        
        cout << v[i] << ' ';
    }
    
    return;
}