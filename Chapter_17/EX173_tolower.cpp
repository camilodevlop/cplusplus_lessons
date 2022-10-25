/*Write a function, void to_lower(char* s), that replaces all upper-
 case characters in the C-style string s with their lowercase
 equivalents.*/

#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------------------------------

void to_lower(char* s)
{
    while(*s!='\0')
    { 
        if(isupper(*s)) *s = tolower(*s);
        ++s; 
    }
}

//--------------------------------------------------------------------

int main()
{
    string str{"Camilo Alejandro Castillo Benavides"};

    cout << "\n\n\tUppercase string: " << str;
    to_lower(&str[0]);
    cout << "\n\tLowercase string: " << str << "\n\t";

    return 0;
}

//--------------------------------------------------------------------
