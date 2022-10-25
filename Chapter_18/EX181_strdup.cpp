/*Write a function, char* strdup(const char*), that copies a C -style
string into memory it allocates on the free store. Use the deference
operator *.*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

char* strdup(const char* c)
{
    int l = strlen(c);
    char* cpy = new char[l];

    while(*c)
    {
        *cpy = *c;
        ++c;
        ++cpy;
    }

    return cpy - l;     // Returns the pointer to the first position.
}

//--------------------------------------------------------------------

int main()
{
    char ch[] = "String";
    char* cpy{strdup(ch)};
    
    for( ;cpy < &cpy[strlen(cpy)]; ++cpy)
        cout << "\n\t" << *cpy;

    cout << "\n\n\t";
    return 0;
}

//--------------------------------------------------------------------
