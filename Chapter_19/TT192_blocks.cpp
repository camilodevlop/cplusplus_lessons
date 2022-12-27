/*Add try-blocks to the example to ensure that all resourses are pro-
perly released in all cases where an exception might be thrown.*/

#include<iostream>
#include<vector>

using namespace std;

//--------------------------------------------------------------------

int main()
{
    int s{10};

    int* p = new int[s];
    vector<int> v1(5);
    double* q = new double[s];
    vector<double> v2;

    try
    {
        p[3] = v1.at(3);
        q[3] = v2.at(5);
    }
    catch(out_of_range)
    {
       delete[] p;
       delete[] q;
       cerr << "\n\n\tOoops! Range error!\n\t";
       return 1;
    }
    catch(...)
    {
       delete[] p;
       delete[] q;
       cerr << "\n\n\tOoops! Something is wrong!";
       return 1; 
    }

    delete[] p;
    delete[] q;

    return 0;
}

//--------------------------------------------------------------------
