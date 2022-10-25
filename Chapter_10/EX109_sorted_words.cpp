/*Program that takes two files containing sorted whitespace-separated words
and merges them, preserving order.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    {
        ist.clear();
        ist.unget();
        char ch;
        
        if (ist >> ch && ch == term) return;
        
        error(message);
    }
    
}

//------------------------------------------------------------------------------

int main ()
{
    // Open the file 1.
    ifstream ist1{"/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_string1_109"};
    if (!ist1) error("\n\n\tCan't open the file 1.\n\t");

    ist1.exceptions(ist1.exceptions()|ios_base::badbit);

    // Open the file 2.
    ifstream ist2{"/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_string2_109"};
    if (!ist2) error("\n\n\tCan't open the file 2.\n\t");

    ist2.exceptions(ist2.exceptions()|ios_base::badbit);

    try
    {
        vector <string> words;

        // Read strings from file 1.
        for (string s; ist1 >> s;)
            if (s != "|")
                words.push_back(s);
        end_of_loop(ist1, '|', "\n\n\tBad termination of file 1.\n\t");

        // Read strings from file 1.
        for (string s; ist2 >> s;)
            if (s != "|")
                words.push_back(s);
            
        end_of_loop(ist2, '|', "\n\n\tBad termination of file 2.\n\t");

        sort(words.begin(),words.end());

        // Print the sorted strings.
        cout << "\n\n\tThe sorted strings are presented below:\n\n\t";
        for (string s : words)
            cout << s << "\n\t";
        
        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
        return 2;
    }
}

 //------------------------------------------------------------------------------