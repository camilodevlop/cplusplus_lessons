/*Program that reads strings and for each string outputs the character classi-
 fication of each character. Note that a character can have several classifi-
 cations.*/

#include <iostream>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

void char_classifier(const char& ch)
{
    cout << "\n\n\tThe character '" << ch << "' is:\n\t";

    if(isalnum(ch))
    {
        cout << "- a letter or decimal digit.\n\t";
        if(isalpha(ch))
        {
            cout << "- a letter.\n\t";
            isupper(ch)? cout << "- an uppercase.\n\t" :
                         cout << "- a lowercase.\n\t";
        }
        else
            cout << "- a number.\n\t";
    }
    else
    {
        if(isspace(ch))     
            cout << "- a space";
        else
            cout << "- an ASCII printable or a control char.";
    }

    return;
}

//------------------------------------------------------------------------------

int main()
{
    char ch;

    cout << "\n\n\tEnter the strings (Type Ctrl+D to finish):\n\t";

    while(cin.get(ch))
        char_classifier(ch);

    return 0;
}

//------------------------------------------------------------------------------
