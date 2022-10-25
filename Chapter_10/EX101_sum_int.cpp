/*Program that produces the sum of all the numbers in a file of white-spaces integers.*/

#include <iostream>
#include <fstream>
#include <string>

#include "std_lib_facilities.h"
using namespace std;

//------------------------------------------------------------------------------
// End of standard input loop.

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return;
        error(message);
    }
    
}

//------------------------------------------------------------------------------
/*istream& operator=(istream& is1, istream& is2)
{
    return is1;
}*/

//------------------------------------------------------------------------------

int main ()
{   
    // Opening the file.

    ifstream ist("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_101");
    if (!ist) error("\n\n\tCan't output the input file.\n\n\t");

    ist.exceptions(ist.exceptions()|ios_base::badbit);      // Make ist throw if it goes bad.
    
    try
    {
        // Reading and adding the integers.

        int sum = 0;

        for (int i; ist >> i;)
            sum += i;
        end_of_loop(ist,'|',"\n\n\tBad termination of file\n\t");

        // Sum result.
        
        cout << "\n\n\tThe sum of integers is: " << sum << "\n\t";

        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
    }
}

//------------------------------------------------------------------------------
