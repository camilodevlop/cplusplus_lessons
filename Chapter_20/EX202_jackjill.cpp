/*Get the Jack-and-Jill example to work. Use input from a couple of
small files to test it.*/

#include<fstream>
#include<iostream>
#include<vector>
#include "runtime_errors.h"

using namespace std;

//--------------------------------------------------------------------

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for(Iterator p = first; p != last; ++p)
        if(*high < *p) high = p;

    return high;
}

//--------------------------------------------------------------------

// Jack and Jill data.

double* get_from_jack( int* count )
{
    // Opening the input file.
    ifstream ist{"data_jack"};
    if(!ist) error("\n\n\tCan't open the input file.\n\t");

    ist.exceptions(ist.exceptions() | ios_base::badbit);

    // Catching the values in a string. 
    string val{""};
    for(string s; ist>>s; ) { val += (s + " "); ++(*count); }

    // Saving the values in an array of doubles.
    istringstream buffer;
    buffer.str(val);
    double d;
    
    double* jack = new double[*count];
    while(buffer >> d) { *jack = d; ++jack; }
    
    return (jack-(*count));      // Jack points back to the beginning.
}

vector<double>* get_from_jill()
{
    // Opening the input file.
    ifstream ist{"data_jill"};
    if(!ist) error("\n\n\tCan't open the input file.\n\t");

    ist.exceptions(ist.exceptions() | ios_base::badbit);

    // Saving the values in a vector of doubles.
    vector<double>* jill = new vector<double>;
    for(double d; ist>>d; ) (*jill).push_back(d);

    return jill;
}

//--------------------------------------------------------------------

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data,jack_data+jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0], &v[0] + v.size());

    cout << "\n\tJill's high: " << *jill_high << "\n\tJack's high: "
         << *jack_high << "\n\n\t";

    delete[] jack_data;
    delete jill_data;
}

//--------------------------------------------------------------------

int main()
{
   fct();

   return 0;
}

//--------------------------------------------------------------------
