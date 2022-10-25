/*Read into a string rather than to memory you put on the free store.
*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

int main()
{
    string test{""};
    
    cout << "\n\n\tEnter the characters (! to finish).\n";
    char c{' '};
    while(cin >> c && c!='!')
        test += c;

    return 0;
}

//--------------------------------------------------------------------
