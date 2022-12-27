/*Find and fix the error in the Jack-and-Jill example by using STL
techniques throughout.
The erros are fixed by means of RAII. It lets the deallocation
of resources in case some issue occurs -e.g., an exception-.*/

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

struct Jack_class
{
   int jack_count;
   double* jack_data;
   Jack_class() : jack_count{0}, jack_data{get_from_jack(&jack_count)} {}
   ~Jack_class() { delete[] jack_data; cout << "\n\n\tjack_data deleted\n\t"; }
};

class Jill_class
{
   vector<double>* j_data;

public:
   vector<double>* jill_data() const { return j_data; }
   Jill_class() : j_data{get_from_jill()} {}
   ~Jill_class() { delete j_data; cout << "\n\n\tjill_data deleted\n\t"; }
};

//--------------------------------------------------------------------

void fct()
{
   Jack_class jack;
   double* jd = jack.jack_data;
   Jill_class jill;
   vector<double>* jill_data = jill.jill_data();
   // error("\n\n\tRAII test.\n\t");

   double* jack_high = high(jd,jd+jack.jack_count);
   vector<double>& v = *jill_data;
   double* jill_high = high(&v[0], &v[0] + v.size());

   cout << "\n\tJill's high: " << *jill_high << "\n\tJack's high: "
         << *jack_high << "\n\n\t";

}

//--------------------------------------------------------------------

int main()
{
   try
   {
      fct();
   }
   catch(runtime_error)
   {
      cerr << "\n\n\truntime errors\n\t";
      return 1;
   }
   catch(...)
   {
      cerr << "\n\n\tSomething is wrong\n\t";
      return 1;
   }

   return 0;
}

//--------------------------------------------------------------------
