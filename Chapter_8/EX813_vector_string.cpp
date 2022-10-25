/*This program takes a vector<string> argument and returns a vector<int> containing the number of characters
in each string. Find the longest and the shortest string and the lexicographically first and last string.*/

#include <iostream>
#include <string>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

vector<int> numberchar(vector<string>&, string&, string&);

//------------------------------------------------------------------------------

int main()
{
    vector<string> strs;
    vector<int> szs;

    // Catch the strings.
    string s;
    cout << "\n\n\tEnter strings (type Ctrl + D to finish):\n\n\t";
    while (cin >> s)
    {
        strs.push_back(s);
        cout << '\t';
    }

    string lgest = strs[0];
    string shrtest = strs[0];

    cout << "\n\n\tThe string lengths are:\n\t"; 
    szs = numberchar(strs, lgest, shrtest);

    cout << "\n\n\n\tThe longest and shortest strings: " << lgest << '\t' << shrtest;

    sort(strs.begin(),strs.end());
    cout << "\n\n\tLexicographically first and last string: " << strs[0] << '\t' << strs[strs.size() - 1] << "\n\n";
    
    return 0;
}

//------------------------------------------------------------------------------

vector<int> numberchar(vector<string>& v, string& lo, string& sh)
{
    vector<int> nc;
    int lg;                         // Catch the strings' lengths.

    for (int i = 0; i < v.size(); i++)
    {
        lg = v[i].length();
        
        if (lg > lo.length())           // Largest string.
            lo = v[i];
        
        if (lg < sh.length())           // Shortest string.
            sh = v[i];
        
        nc.push_back(lg);               // Catching the strings' lengths.
        cout << lg << '\t';
    }
    
    return nc;
}

//------------------------------------------------------------------------------