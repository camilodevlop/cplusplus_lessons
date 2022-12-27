/*Write a template function that takes a vector<T> vt and a
vector<U> vu as arguments and returns the sum of all vt[i]*vu[i].*/

#include<iostream>
#include<vector>

using namespace std;

//--------------------------------------------------------------------

template<typename T, typename U>
T& f(const vector<T>& vt, const vector<U>& vu)
{
    T sum = 0;
    if(vt.size() == vu.size())
        for(int i=0; i<vt.size(); ++i)
            sum += (vt[i]*vu[i]);
    else
        cout << "\n\n\tThe size of vectors is not equal\n\t";

    return sum;
}

//--------------------------------------------------------------------

int main()
{
    vector<int> vec_1{0,1,2,3,4};
    vector<int> vec_2{5,6,7,8,9};
    //vector<double> vec_2{5,6,7,8,9};
    //vector<char> vec_2{'a','b','c'};

    int sum{0};
    sum = f(vec_1,vec_2);

    cout << "\n\n\tThe sum is: " << sum << "\n\t";

    return 0;
}

//--------------------------------------------------------------------
