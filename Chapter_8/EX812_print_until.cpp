/*Improve the function print_until_s(). What makes a good set of test cases? Give reasons.
Then, write a print_until_ss() that prints until it sees a second occurrence of
its quit argument.*/

#include <iostream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

void print_until_s(const vector<string>&, string);
void print_until_ss(const vector<string>&, string);

//------------------------------------------------------------------------------

int main()
{
    vector<string> strs;
    
    strs.push_back("camilo");
    strs.push_back("alejandro");
    strs.push_back("lina");
    strs.push_back("cordula");
    strs.push_back("\x07");
    strs.push_back("castillo");
    strs.push_back("benavides");
    strs.push_back("\x07");

    cout << "\n\n\tprint_until_s prints until the occurrence of quit argument.";
    cout << "\n\tprint_until_ss prints until the second occurrence of quit argument.\n\n\n";
    
    print_until_s(strs, "\x07");
    print_until_ss(strs, "\x07");
    
    return 0;
}

//------------------------------------------------------------------------------

void print_until_s(const vector<string>& v, string quit)
{
    for (string s : v)
    {
        if (s == quit)
        {
            cout << "\n\t" << s << " was identified as a quit word.\n\n";
            return;
        }
        
        cout << s << '\n';
    }
    
    return;
}

//------------------------------------------------------------------------------

void print_until_ss(const vector<string>& v, string quit)
{
    int aux = 0;

    for (string s : v)
    {
        if (s == quit)
        {
            ++aux;
            if (aux == 2)
            {
                cout << "\n\t" << s << " was identified as a second occurrence quit word.\n\n";
                return;
            }
        }
        
        cout << s << '\n';
    }
    
    return;
}