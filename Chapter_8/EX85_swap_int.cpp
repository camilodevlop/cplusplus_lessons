/*Write two functions that reserve the order of elements in a vector<int>. The former leaves the
original vector unchanged. The other should reverse the elements of its vector without using
any other vectors.*/

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

vector<int> swap_v(vector<int>);
void swap_vr(vector<int>&);
void print(vector<int>);

int main()
{
    vector<int> vp;
    int size = 100;
    
    for (int i = 0; i < size; i++)
        vp.push_back(i);
    
    print(vp);
    vp = swap_v(vp);
    print(vp);
    
    swap_vr(vp);
    print(vp);

    return 0;
}

vector<int> swap_v(vector<int> vi)
{
    vector<int> vo;
    
    for (int i = vi.size() - 1; i >= 0; --i)
        vo.push_back(vi[i]);
    
    return vo;
}

void swap_vr(vector<int>& vp)
{
    int aux, sv;
    sv = vp.size() - 1;
    
    for (int i = 0; i < (vp.size() / 2); i++)
    {
        aux = vp[sv];
        vp[sv] = vp[i];
        vp[i] = aux;
        --sv;
    }
}

void print(vector<int> v)
{
    cout << "\n\n\t";
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 10 == 0)
            cout << "\n\n\t";
        
        cout << v[i] << ' ';
    }
    
    return;
}