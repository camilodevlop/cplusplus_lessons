/*The drill has two parts. This second part focuses on pointers and 
their relation to arrays.*/

#include <iostream>
#include <vector>

using namespace std;

//--------------------------------------------------------------------

void print_array(ostream& os, int* a, int n)
{
    os << "\n\tValues:";

    for(int i=0; i<n; ++i)
        os << ' ' << a[i];

    os << "\n\n\t";
}

//--------------------------------------------------------------------

int main()
{
    int i = 7;
    int* p1 = &i;
    cout << "\n\n\tAddress of p1: " << p1 << "\n\tint value: " << i;

    int* p2 = new int[]{1,2,4,8,16,32,64};
    cout << "\n\n\tAddress of p2: " << p2 << " and p2";
    print_array(cout,p2,7);

    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    cout << "\n\n\tAddress of p1: " << p1 << "\n\tint value: " << *p1;
    cout << "\n\n\tAddress of p2: " << p2 << "\n\tint value: " << *p2;
    delete[] p2;

    p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
    p2 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    for(int el=0; el<10; ++el)
        p2[el] = p1[el];
    cout << "\n\n\tNew values of p2:";
    print_array(cout,p2,10);

    vector<int> vp1{1,2,4,8,16,32,64,128,256,512}; 
    vector<int> vp2{0,1,2,3,4,5,6,7,8,9};
    for(int el=0; el<10; ++el)
        vp2[el] = vp1[el];
    cout << "\n\n\tNew values of vp2:";
    print_array(cout,&vp2[0],10);

    return 0;
}

//--------------------------------------------------------------------
