/*Create a vector of Fibonacci numbers by a function fibonacci(x,y,v,n). v is a vector, n is the number of elements
to put in v, and v[0] will be x and v[1] will be y.

4. Fibonacci (47)*/

#include <iostream>
#include <string>
#include <vector>

#include "std_lib_facilities.h"

using namespace std;

void fibonacci(int, int, vector<int>&, int);
void print(string, vector<int>&);

int main()
{
    vector<int> vf;
    
    fibonacci(0, 1, vf, 47);
    print("Vector_prueba:", vf);
    return 0;
}

//------------------------------------------------------------------------------
// Fibonacci numbers.

void fibonacci(int x, int y, vector<int>& v, int n)
{
    v.push_back(x);
    v.push_back(y);

    for (int i = 2; i < n; i++)
    {
        v.push_back(x + y);
        x = y;
        y = v[i];
    }
    
    return;
}

//------------------------------------------------------------------------------
// Print a vector.

void print(string s, vector<int>& v)
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