/*Memory exhaustion: write a program with an infinite loop that allo-
cates but never deallocates (use new)*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

int main()
{
    double count{0};

    cout << "\n\n\t";
    while(true)
    {
        double* test = new double[900000];
        count += 1;
        cout << ' ' << count;
    }

    return 0;
}

//--------------------------------------------------------------------
