/*Write a function, string cat_dot(const string& s1, const string& s2)
, that concatenates two strings with a string between.*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

string cat_dot(const string& s1, const string& s2, const string& s3)
{
    return s1 + s3 + s2;
}

//--------------------------------------------------------------------

int main()
{
    cout << "\n\n\tThe concatenated string is:\n\t"
         << cat_dot("Camilo","Alejandro","--") << "\n\t";

    return 0;
}

//--------------------------------------------------------------------
