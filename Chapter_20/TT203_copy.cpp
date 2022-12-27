/*Write a function void copy(int* f1, int* e1, int* f2) that copies
the elements of an array of ints defined by [f1:e1) into another
[f2:f2 +(e1-f1).*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

void copy(int* f1, int* e1, int* f2)
{
    for(int* p=f1; p!=e1; ++p) { *f2 = *p; ++f2; }
}

//--------------------------------------------------------------------

int main()
{
    const int sz{10};

    int arr1[sz] = { 0,1,2,3,4,5,6,7,8,9 };
    int* it1 = &arr1[0];
    int* it2 = &arr1[sz];

    int arr2[sz];
    copy(it1, it2, &arr2[0]);

    cout << "\n\n\t";
    for(int i=0; i<sz; ++i) cout << arr2[i] << '\t';

    return 0;
}

//--------------------------------------------------------------------
