/*Jack and Jill problem. This code expresses the "find the element
with the largest value" problem using STL notion of a sequence. */

#include<iostream>
#include<vector>

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
    double* jack = new double[10]{0,1,2,3,4,5,6,7,8,9};
    *count = 10;
    return jack;
}

vector<double>* get_from_jill()
{
    vector<double>* jill = new vector<double>{0,1,10,2,3,4,5,6,7,8,9};
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
