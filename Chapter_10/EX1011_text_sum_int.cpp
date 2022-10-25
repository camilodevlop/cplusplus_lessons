/*This program produces the sum of all whitespace-separated integers in a text file.
For example, "bears: 17 elephants 9 end" should output 26.*/

#include <iostream>
#include <string>
#include <fstream>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    // Open the text file.
    ifstream is("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_text_sum_int_1011");
    if (!is) error("\n\n\tCan't open the text file.\n\t");
    
    is.exceptions(is.exceptions()|ios_base::badbit);

    try
    {
        int num;
        int sum = 0;

        char ch;
    
        cout << "\n\n\tCatched numbers:\t";

        is.get(ch);
        while (is)
        {
            if (ch == '-' || isdigit(ch))
            {
                is.putback(ch);
                is >> num;
                cout << num << '\t';
                sum += num;
            }
            is.get(ch);
        }

        cout << "\n\n\tThe sum of numbers is:\t" << sum << "\n\t";
        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << ("\n\n\tSomething is wrong.\n\t");
        return 1;
    }
}

//------------------------------------------------------------------------------
