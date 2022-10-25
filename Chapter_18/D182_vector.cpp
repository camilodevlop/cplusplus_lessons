/*Exercise vectors.*/

#include <iostream>
#include <vector>

using namespace std;

//--------------------------------------------------------------------

void f(vector<int> a)
{
    vector<int> lv(a.size());
    lv = a;

    for(int i=0; i<lv.size(); ++i)
        cout << lv[i] << "\n";

    vector<int> lv2(a.size());
    lv2 = a;

    for(int i=0; i<lv2.size(); ++i)
        cout << lv2[i] << "\n";
}

//--------------------------------------------------------------------

vector<int> gv{1,3,5,7,9,11,13,15,17,19};

int main()
{
    cout << "\n\nExercise using vectors.\n";
    f(gv);

    vector<int> vv{1,2*1,3*2*1,4*3*2*1,5*4*3*2*1,6*5*4*3*2*1,
                7*6*5*4*3*2*1,8*7*6*5*4*3*2*1,9*8*7*6*5*4*3*2*1,
                10*9*8*7*6*5*4*3*2*1};

    cout << '\n';
    f(vv);

    return 0;
}

//--------------------------------------------------------------------
