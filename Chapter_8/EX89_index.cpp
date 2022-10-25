/*Write a fumction that given two vectors (price and weight) computes the sum of all
price[i]*weight[i].*/

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

double index(vector<double>&, vector<double>&);

int main()
{
    try
    {
        vector<double> price;
        vector<double> weight;
    
        double pr,we;                                   // Catch the current price and weight.

        cout << "\n\n\tEnter price and weight (type Ctrl + D to finish):\n\n\t";
        while (cin >> pr >> we)
        {
            price.push_back(pr);
            weight.push_back(we);
            cout << '\t';
        }
    
        if (price.size() != weight.size())
            error("\n\n\tThe sizes of the vectors are not equal.");
        else
            cout << "\n\n\tThe sum of all price[i]*weight[i] =\t" << index(price,weight) << '\n';

        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
}

double index(vector<double>& p, vector<double>& w)
{
    double ind = 0;
    
    for (int i = 0; i < p.size(); i++)
        ind += (p[i] * w[i]);
    
    return ind;
}