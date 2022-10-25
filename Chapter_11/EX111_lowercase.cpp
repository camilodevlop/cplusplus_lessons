/*Program that reads a text file and converts its input to all lower
case.*/

#include <fstream>
#include <iostream>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main ()
{
    cout << "\n\n\tProgram that reads a text file and converts its input to all lowercase.\n\t";

    // Open the input file.
    ifstream ist{"mydata_input_111"};
    if (!ist) error("\n\n\tCan't open the input file.\n\t");

    ist.exceptions(ist.exceptions()|ios_base::badbit);

    // Open the output file.
    ofstream ost{"mydata_output_111"};
    if (!ost) error("\n\n\tCan't open the output file.\n\t");

    ost.exceptions(ost.exceptions()|ios_base::badbit); 


    try
    {

        for(string s ; ist>>s; ) 
        {
            for(char& c : s)
                if(isupper(c)) c = tolower(c);
            
            ost << ' ' << s;
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
