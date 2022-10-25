/*Run the example of debugging constructors and destructors, i.e., im-
plement the X class. Make sure you understand the results.*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

class Vector
{
    int sz;
    double* elem;

public:
     Vector(int n) : sz{n}, elem{new double[sz]} {}
     double operator[](int n){ return elem[n]; }
};

//--------------------------------------------------------------------

int main()
{
    Vector v(10);
    double x = v[2];
    v[3] = x;

    return 0;
}

//--------------------------------------------------------------------
