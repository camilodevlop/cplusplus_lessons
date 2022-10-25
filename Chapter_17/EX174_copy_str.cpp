/*Write a function, char* strdup(const char*), that copies a C-style
string into memory it allocates on the free store.*/

#include<iostream>
#include<string>

using namespace std;

//--------------------------------------------------------------------

char* strdup(const char* s)
{
    // Empty string.
    if(*s == '\0')
        return nullptr;

    // Counting the elements of the string.
    int n{0};
    while(s[++n] != '\0');    

    // Copying the string.
    char* c = new char[n];
    for(int i=0; i<=n; ++i)
        c[i] = s[i];

    return c;

}

//--------------------------------------------------------------------

int main()
{
    string str{"Camilo Alejandro"};

    char* cpy = strdup(&str[0]);
    if(cpy)
        while(*cpy != '\0')
        {
            cout << *cpy;
            ++cpy;
        }
    delete[] cpy;

    return 0;
}

//--------------------------------------------------------------------
