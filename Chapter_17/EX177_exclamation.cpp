/*Write a program that reads characters from cin into a array that
you allocate on the free store. read individual characters until an 
exclamation mark (!) is entered.*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

int main()
{
    char* test = new char[5];
    
    cout << "\n\n\tTest of explamation mark (!)\n";

    int i = 0;
    do
    {
        cout << "\tEnter the character: ";
        cin >> test[i];
    }while(test[i]!='!');

    return 0;
}

//--------------------------------------------------------------------
