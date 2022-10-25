/*The drill has two parts. The first exercises/builds your under-
standing of free-store-allocated arrays and constrasts arrays with 
vectors.*/

#include <iostream>
#include <vector>

using namespace std;

//--------------------------------------------------------------------

void print_array10(ostream& os, int* a)
{
    os << "\n\n\tValues:";

    for(int i=0; i<10; ++i)
        os << ' ' << a[i];

    os << "\n\n\t";
}

//--------------------------------------------------------------------

void print_array(ostream& os, int* a, int n)
{
    os << "\n\n\tValues:";

    for(int i=0; i<n; ++i)
        os << ' ' << a[i];

    os << "\n\n\t";
}

//--------------------------------------------------------------------

void print_vector(ostream& os, vector<int>& v, int n)
{
    os << "\n\n\tValues:";

    for(int i:v)
        os << ' ' << i;

    os << "\n\n\t";
}

//--------------------------------------------------------------------

int main()
{
    int* elem = new int[10]{0,1,2,3,4,5,6,7,8,9};
    print_array10(cout, elem);
    delete[] elem;

    int* elem2 = new int[11]{100,101,102,103,104,105,106,107,108,109,
                             110};
    print_array(cout, elem2, 11);
    delete[] elem2;

    int* elem3 = new int[20]{100,101,102,103,104,105,106,107,108,109,
                             110, 111, 112, 113, 114, 115, 116, 117,
                             118, 119};
    print_array(cout, elem3, 20);
    delete[] elem3;

    vector<int> v_elem{100,101,102,103,104,105,106,107,108,109};
    print_vector(cout, v_elem, 10);
    vector<int> v_elem2{100,101,102,103,104,105,106,107,108,109,110};
    print_vector(cout, v_elem2, 11);
    //print_array10(cout,&v_elem[0]);


    return 0;
}

//--------------------------------------------------------------------
