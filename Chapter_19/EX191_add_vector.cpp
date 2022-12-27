/*Write a template function that adds the elements of one vector<T> to
 the elements of another.*/

#include<iostream>
#include<vector>

using namespace std;

//--------------------------------------------------------------------

template<typename T>
void f(vector<T>& v1, vector<T>& v2)
{
    if(v1.size() <= v2.size())
        for(int i=0; i<v1.size();++i)
            v1[i]+=v2[i];
    else
        cout << "\n\n\tThe size of v1 is not suitable\n\t";
}

//--------------------------------------------------------------------

int main()
{
    vector<int> vec_1{0,1,2,3,4};
    vector<int> vec_2{5,6,7,8,9};

    f(vec_1,vec_2);

    cout << "\n\tVec_1 contains the sums results.\n\t";
    for(int i=0; i<vec_1.size(); ++i)
        cout << vec_1[i] << '\t';

    return 0;
}

//--------------------------------------------------------------------
