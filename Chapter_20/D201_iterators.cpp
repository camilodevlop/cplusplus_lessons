/*Drill proposed in chapter 20.*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

//--------------------------------------------------------------------

// Array initializer.

template<typename T>
void arr_initializer(const T* arr, T* arr2, int sz)
{
   for(int i=0; i<sz; ++i) arr2[i] = arr[i];
}

//--------------------------------------------------------------------

// Print operation.

template<typename Iterator>
void print_out(Iterator first, Iterator last)
{
    for(Iterator p = first; p != last; ++p) cout << *p << ' ';
}

//--------------------------------------------------------------------

// Increasing the values. 

template<typename Iterator>
void incrementer(Iterator first, Iterator last, int inc)
{
    for(Iterator p = first; p != last; ++p) *p += inc;
}

//--------------------------------------------------------------------

// copy() operation.

template<typename Iter1, typename Iter2>
// Requires input_iterator<iter1>() && output_iterator<iter2>()
Iter2 cpy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 p=f1; p!=e1; ++p) { *f2 = *p; ++f2; }

    return f2;
}

//--------------------------------------------------------------------

int main()
{
    int sz{10};
    int arr_int[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> vtr_int { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> lst_int { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Copying the fist array, vector, and list.

    int arr_int2[sz];
    arr_initializer(&arr_int[0], &arr_int2[0], sz);
    vector<int> vtr_int2 {vtr_int};
    list<int> lst_int2 {lst_int};

    // Increasing the values.

    cout << "\n\n\tIncreasing the values:\n\tArray\n\t";
    incrementer(&arr_int[0], &arr_int[10], 2);
    print_out(&arr_int[0], &arr_int[10]);

    cout << "\n\tVector\n\t";
    incrementer(vtr_int.begin(), vtr_int.end(), 3);
    print_out(vtr_int.begin(), vtr_int.end());

    cout << "\n\tList\n\t";
    incrementer(lst_int.begin(), lst_int.end(), 5);
    print_out(lst_int.begin(), lst_int.end());

    // cpy(): copy operation.

    cout << "\n\n\tcopy() operation:\n\tArray 2\n\t";
    auto it1 = cpy(&arr_int[0], &arr_int[10], &arr_int2[0]);
    print_out(&arr_int2[0], &arr_int2[10]);

    cout << "\n\tVector 2\n\t";
    auto it2 = cpy(vtr_int.begin(), vtr_int.end(), vtr_int2.begin());
    print_out(vtr_int2.begin(), vtr_int2.end());

    cout << "\n\tList 2\n\t";
    auto it3 = cpy(lst_int.begin(), lst_int.end(), lst_int2.begin());
    print_out(lst_int2.begin(), lst_int2.end());

    // Using cpy(): array into vector, list into array.

    cout << "\n\n\tcpy(): array into vector:\n\t";
    auto it4 = cpy(&arr_int[0], &arr_int[10], vtr_int.begin());
    for(int x  : vtr_int) cout << x << ' ';

    cout << "\n\n\tcpy(): list into array:\n\t";
    auto it5 = cpy(lst_int.begin(), lst_int.end(), &arr_int[0]);
    for(int x  : arr_int) cout << x << ' ';

    // Using the standard library find().
    
    auto it6 = find(&arr_int[0], &arr_int[10],3);
    cout << "\n\n\tArrays don't use iterators: " << *it6;

    vector<int>::iterator it7 = find(vtr_int.begin(), vtr_int.end(),8);
    if( it7 == (vtr_int.begin() + 6) ) cout << "\n\t8 was found.";

    list<int>::iterator it8 = find(lst_int.begin(), lst_int.end(),27);
    if(it8 == lst_int.end()) cout << "\n\tThe value wasn't found.";

    return 0;
}

//--------------------------------------------------------------------

