/*Write two functions that reserve the order of elements in a vector<string>. The former leaves the
original vector unchanged. The other should reverse the elements of its vector without using
any other vectors.*/

#include <iostream>
#include <vector>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

vector<string> swap_v(vector<string>);
void swap_vr(vector<string>&);
void print(vector<string>);

int main()
{
    vector<string> vp;
    string s;
    int size = 100;

    for (int i = 33; i < 122; i++)
    {
        s = i;
        vp.push_back(s);
    }
    
    vp.push_back("friend");                                 // A larger string.

    print(vp);
    vp = swap_v(vp);
    print(vp);
    
    swap_vr(vp);
    print(vp);

    return 0;
}

vector<string> swap_v(vector<string> vi)
{
    vector<string> vo;
    
    for (int i = vi.size() - 1; i >= 0; --i)
        vo.push_back(vi[i]);
    
    return vo;
}

void swap_vr(vector<string>& vp)
{
    string aux;
    int sv = vp.size() - 1;
    
    for (int i = 0; i < (vp.size() / 2); i++)
    {
        aux = vp[sv];
        vp[sv] = vp[i];
        vp[i] = aux;
        --sv;
    }

    return;
}

void print(vector<string> v)
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