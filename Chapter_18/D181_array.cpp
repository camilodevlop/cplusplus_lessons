/*Exercise arrays.*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

void f(int a[], int s)
{
    int la[10];
    copy(a,a+10,la);

    for(int* p=&la[0]; p<&la[10]; ++p)
        cout << *p << "\n";
    
    int* p = new int[s];
    copy(a,a+s,p);

    for(int* i=p; i<&p[s]; ++i)
        cout << *i << "\n";

    delete[] p;
}

//--------------------------------------------------------------------

int ga[] = {1,2,3,4,5,6,7,8,9,10};

int main()
{
    cout << "\n\nExercise using arrays.\n";
    f(ga,10);

    int aa[] = {1,2*1,3*2*1,4*3*2*1,5*4*3*2*1,6*5*4*3*2*1,
                7*6*5*4*3*2*1,8*7*6*5*4*3*2*1,9*8*7*6*5*4*3*2*1,
                10*9*8*7*6*5*4*3*2*1};
    
    cout << '\n';
    f(aa,10);

    return 0;
}

//--------------------------------------------------------------------
