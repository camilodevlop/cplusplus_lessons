/*For each array of char, vector<char>, list<char>, and string, define
one with the value "Hello", pass it to a function as an argument, 
write out the number of characters in the string passed, try to com-
pare it to "Hello" in that function, and compare the argument to
"Howdy" lexicographically.

Do the previous Try this for an array of int, vector<int>, and
list<int> each with the value { 1,2,3,4,5 }. */

#include<iostream>
#include<vector>
#include<list>

using namespace std;

//--------------------------------------------------------------------

template<typename T>
void containers(T t)
{
    T aux {1,2,3,4,5};

    int int_counter{0};
    for(auto x = t.begin(); x != t.end(); ++x)  ++int_counter;
    cout << "\n\n\tInts: " << int_counter << "\n\t";

    // Comparing to {1,2,3,4,5}.
    if(t == aux) cout << "\n\n\t==: true\n\t";

    // Comparing to {1,2,3,4,5}.
    (t > aux) ? cout << ">: true" : cout << ">: false";
}

//--------------------------------------------------------------------

int main()
{
    int ac1[] = {1,2,3,4,5};
    vector<int> ac2 {1,2,3,4,5};
    list<int> ac3 {1,2,3,4,5};

    cout << "\n\n\t";
    containers(ac2);
    cout << "\n\n";

    return 0;
}

//--------------------------------------------------------------------
