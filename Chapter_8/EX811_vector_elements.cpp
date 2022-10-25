/*Write a function that finds the smallest and the largest element of a vector argument and also
computes the mean and the median. Either return a struct containing the results or pass
them back through reference arguments.*/

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

vector<double> vec_features(vector<double>);
void vec_featuresr(vector<double>&, double&, double&, double&, double&);

//------------------------------------------------------------------------------

int main()
{    
    cout << "\n\n\tGiven a vector, find the smallest and largest element.\n\t";
    cout << "Further, compute the mean and the median.";
    
    vector<double> values;
    vector<double> results;

    // Catch the current value.
    double v;
    cout << "\n\n\tEnter value (type Ctrl + D to finish):\n\n\t";
    while (cin >> v)
    {
        values.push_back(v);
        cout << '\t';
    }

    // Variable declaration.
    double maxv = values[0];
    double minv = values[0];
    double mean = 0;
    double median = 0;

    // Using a vector to return the results.    
    results = vec_features(values);
    cout << "\n\n\tUsing a vector:\t\t";
    cout << results[0] << "\t" << results[1] << "\t" << results[2] << "\t" << results[3] << "\n\t";

    // Using references.
    vec_featuresr(values, maxv, minv, mean, median);
    cout << "\n\n\tUsing references:\t";
    cout << maxv << "\t" << minv << "\t" << mean << "\t" << median << "\n\t";
    
    return 0;
}

//------------------------------------------------------------------------------

vector<double> vec_features(vector<double> val)
{
    vector<double> results;
    int vs = val.size();
    
    double maxv = val[0];
    double minv = val[0];
    double mean = 0;
    double median = 0;

    for (int i = 0; i < vs; i++)
    {
        if (val[i] > maxv)                  // Max value.
            maxv = val[i];
        
        if (val[i] < minv)                  // Min value.
            minv = val[i];
        
        mean += val[i];                     
    }
    
    results.push_back(maxv);
    results.push_back(minv);
    results.push_back(mean / val.size());   // Computing the mean.
    
    sort(val.begin(),val.end());            // Computing the median.
    if (vs % 2 == 0)
        median = (val[vs/2] + val[vs/2 - 1]) / 2;
    else
        median = val[vs / 2];
    
    results.push_back(median);

    return results;
}

//------------------------------------------------------------------------------

void vec_featuresr(vector<double>& val, double& mx, double& mn, double& me, double& med)
{
    int vs = val.size();

    // Max value, min value, and sum of values.
    for (int i = 0; i < vs; i++)
    {
        if (val[i] > mx)                    
            mx = val[i];

        if (val[i] < mn)
            mn = val[i];

        me += val[i];
    }
    
    // Computing the mean.
    me /= vs;

    // Computing the median.
    sort(val.begin(), val.end());
    if (vs % 2 == 0)
        med = (val[vs/2] + val[vs/2 - 1]) / 2;
    else
        med = val[vs / 2];

    return;
}