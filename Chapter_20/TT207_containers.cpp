/*For each array of char, vector<char>, list<char>, and string, define
one with the value "Hello", pass it to a function as an argument, 
write out the number of characters in the string passed, try to com-
pare it to "Hello" in that function, and compare the argument to
"Howdy" lexicographically.*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

//--------------------------------------------------------------------

template<typename T>
void containers(T t)
{
    int char_counter{0};
    for(auto x = t.begin(); x != t.end(); ++x)  ++char_counter;
    cout << "\n\n\tCharacters: " << char_counter << "\n\t";

    // Comparing to "Hello".
    if(t == "Hello") cout << "\n\n\t==Hello: true\n\t";

    // Comparing lexicographically to "Howdy".
    (t > "Howdy") ? cout << ">Howdy: true" : cout << ">Howdy: false";
}

//--------------------------------------------------------------------

int main()
{
    char ac1[] = "Hello";
    vector<char> ac2 {'H','e','l','l','o'};
    list<char> ac3 {'H','e','l','l','o'};
    string ac4{ "Hello" };

    cout << "\n\n\t";
    containers(ac4);
    cout << "\n\n";

    return 0;
}

//--------------------------------------------------------------------
