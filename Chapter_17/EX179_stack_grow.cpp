/*Which way does the stack grow: up (toward higher addresses) or down
(toward lower addresses)? Which way does the free store initially grow
*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------
// Global variables.

const int ig1{1};
const int ig2{2};
const int ig3{3};
const int ig4{4};

const double dg1{1};
const double dg2{2};
const double dg3{3};
const double dg4{4};

//--------------------------------------------------------------------
// Addition function.

int sum(int n1, int n2, int n3)
{
    int s{n1+n2+n3};

    cout << "\n\n\tSum Addresses:\n\tn1: " << &n1 << "\n\tn2: " << &n2
         << "\n\tn3: " << &n3 << "\n\ts: " << &s;

    return s;
}

//--------------------------------------------------------------------
// Subtraction function.

double subt(double d1, double d2, double d3)
{
    double s{d1-d2-d3};
    cout << "\n\n\tSubt Addresses:\n\td1: " << &d1 << "\n\td2: " << &d2
         << "\n\td3: " << &d3 << "\n\ts: " << &s;

    return s;
}

//--------------------------------------------------------------------

int main()
{
    // Printing the addresses of global variables.
    cout << "\n\n\tAddresses of integer global vars:\n\tig1: "
         << &ig1 << "\n\tig2: " << &ig2 << "\n\tig3: " << &ig3
         << "\n\tig4: " << &ig4;

    cout << "\n\n\tAddresses of double global vars:\n\tdg1: "
         << &dg1 << "\n\tdg2: " << &dg2 << "\n\tdg3: " << &dg3
         << "\n\tdg4: " << &dg4;

    // Printing the addresses of local variables.
    int il1 = 1;
    int il2 = 2;
    int il3 = 3;
    int il4 = 4;

    cout << "\n\n\tAddresses of integer local vars:\n\til1: "
         << &il1 << "\n\til2: " << &il2 << "\n\til3: " << &il3
         << "\n\til4: " << &il4;

    double dl1 = 1;
    double dl2 = 2;
    double dl3 = 3;
    double dl4 = 4;

    cout << "\n\n\tAddresses of double local vars:\n\tdl1: "
         << &dl1 << "\n\tdl2: " << &dl2 << "\n\tdl3: " << &dl3
         << "\n\tdl4: " << &dl4;

    // Using sum and subt function.
    int a = sum(4,6,8);
    double b = subt(20,10,5);

    // Allocating the memory.
    int* ip1 = new int{1};
    int* ip2 = new int{2};
    int* ip3 = new int{3};
    int* ip4 = new int{4};

    cout << "\n\n\tAddresses of integeres in the free store:\n\t"
         << "ip1: " << ip1 << "\n\tip2: " << ip2 << "\n\tip3: "
         << ip3 << "\n\tip4: " << ip4;

    double* dp = new double[10]{1.1,2.2,3.3,4.4,5.5};
    cout << "\n\n\tAddresses of doubles in the free store:";
    for(int i=0; i<10; ++i)
        cout << "\n\tdp[" << i << "]: " << &dp[i];

    return 0;
}

//--------------------------------------------------------------------
