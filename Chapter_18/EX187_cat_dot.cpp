/*Write versions of the cat_dot()s from the previous exercises to take
C-style strings as arguments and return a free-store-allocated C-style
string as the result.*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

char* cat_dot(const char* s1, const char* s2, const char* s3)
{
    int sz = strlen(s1) + strlen(s2) + strlen(s3);

    char* r = new char[sz];

    int i{0};
    while(*(s1+i) != '\0')   
    {
        *r = *(s1+i);
        ++r;
        ++i;
    }

    i=0;
    while(*(s3+i) != '\0')   
    {
        *r = *(s3+i);
        ++r;
        ++i;
    }

    i=0;
    while(*(s2+i) != '\0')   
    {
        *r = *(s2+i);
        ++r;
        ++i;
    }

    // r return to the initial position.
    r = r - sz;

    return r;
}

//--------------------------------------------------------------------

int main()
{
    char s1[] = "Camilo";
    char s2[] = "Alejandro";
    char s3[] = "..";

    char* result = cat_dot(s1,s2,s3);

    cout << "\n\n\tThe concatenaded string is:\n\n\t" << result
         << "\n\tCharacters: " << strlen(result) << "\n\n\t";
    
    // Momory deallocation.
    delete[] result;

    return 0;
}

//--------------------------------------------------------------------
