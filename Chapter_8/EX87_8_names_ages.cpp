/*Read names into a vector<string> name and the ages in a vector<double> age. Sort the names. The
tricky part here is to get the age vector in the correct order to match the sorted name vector.*/

#include <iostream>
#include <vector>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

void print(vector<string>, vector<double>);
void age_ordered(const vector<string>&, const vector<string>&, vector<double>&);
int find_names(string, const vector<string>&);

//------------------------------------------------------------------------------

int main()
{
    try
    {
        vector<string> name;
        vector<string> name_copy;
        vector<double> age;

        string n;                                   // Catch the current name.
        int a;                                      // Catch the current age.

        cout << "\n\n\tEnter name and age (type Ctrl + D to finish):\n\n\t";
        while (cin >> n >> a)
        {
            name.push_back(n);
            age.push_back(a);
            cout << '\t';
        }
        
        print(name,age);
        name_copy = name;
        
        sort(name.begin(),name.end());
        age_ordered(name, name_copy, age);

        print(name,age);
        
        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
}

//------------------------------------------------------------------------------

void age_ordered(const vector<string>& n, const vector<string>& nc, vector<double>& a)
{
    vector <double> aux;
    int pos;

    int i = 0;
    while (i < n.size())
    {
        for (int j = 0; j < nc.size(); j++)
            if (n[i] == nc[j])                      // It does not prevent repeated names.
                aux.push_back(a[j]);
        
        ++i;
    }
    
    a = aux;
    
    return;
}

//------------------------------------------------------------------------------

void print(vector<string> n, vector<double> a)
{
    
    cout << "\n\n\tNames\t\tAges\n\n\t";
    
    for (int i = 0; i < n.size(); i++)
        cout << n[i] << "\t\t" << a[i] << "\n\t";
    
    return;
}