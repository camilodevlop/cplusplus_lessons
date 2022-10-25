/*Write a function, int strcmp(const char* s1, const char* s2), that
compares C-style strings. return -1 if s1 is lexicographically before
s2, zero if s1<s2, and 1 if s1 is lexicographically after s2. Use the
deference operator.

It is included a set of lines aimed to partially test the 4th
exercise.*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

int strcmp(const char* s1, const char* s2)
{
    while(tolower(*s1) == tolower(*s2))
    {
        ++s1; ++s2;
        if(*s1=='\0' && *s2=='\0')
            return 0;
    }

    if(tolower(*s1) < tolower(*s2))
        return -1;
    else
        return 1;
}

//--------------------------------------------------------------------

int main()
{
    string s{"Camilo"};
    char c[] = "Cami";
    
    // This lines are used to test partially the 4th exercise.
    /*char* c1 = new char[]{'C','a','m','i'};
    char c1[]={'C','a','m','i'};

    int i=0;
    while(i<5)
    {
        if(c1[i]=='\0')
            cout << "\n\n\tIt has the zero character.\n\t";
        ++i;
    }*/

    switch(strcmp(&s[0],c))
    {
        case 0:
            cout << "\n\n\ts1 equals s2\n\t";
            break;
        
        case -1:
            cout << "\n\n\ts1 is lexicographically before s2\n\t";
            break;

        case 1:
            cout << "\n\n\ts1 is lexicographically after s2\n\t";
            break;

        default:
            cout << "\n\n\tSomething is wrong.\n\t";
    }

    return 0;
}


//--------------------------------------------------------------------
