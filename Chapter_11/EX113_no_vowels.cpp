/*Program that removes all vowels from a file.*/

#include <fstream>
#include <iostream>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main ()
{
    cout << "\n\n\tProgram that removes all vowels from a file.\n\t";

    // Open the input file.
    ifstream ist{"mydata_disemvowels_113"};
    if (!ist) error("\n\n\tCan't open the input file.\n\t");

    ist.exceptions(ist.exceptions()|ios_base::badbit);


    try
    {
        string aux_string = "";

        for(string s ; ist>>s; ) 
        {
            aux_string = "";
            for(char& c : s)
                switch (c)
                {
                    case 'A':
                    case 'a':
                    case 'E':
                    case 'e':
                    case 'I':
                    case 'i':
                    case 'O':
                    case 'o':
                    case 'U':
                    case 'u':
                        break;

                    default:
                        aux_string += c;
                }

            cout << aux_string << ' ';
        }

        cout << "\n\n\tProcess completed successfully.\n\t";
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
        return 1;
    }
}

//------------------------------------------------------------------------------
