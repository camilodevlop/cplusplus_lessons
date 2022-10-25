/* Program that reads binary and converts it to text. The program reads from 
"mydata_binary_119" and writes in "mydata_output_119".*/

#include <iostream>
#include <fstream>
#include <vector>
#include <span>

#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

int main ()
{
    try
    {
        cout << "\n\n\tProgram that converts a binary into a text file.\n\t";

        // Open the input file.
        ifstream ifs{"mydata_binary_119",ios_base::binary};
        if (!ifs) error("\n\n\tCan't open the input file.\n\t");

        ifs.exceptions(ifs.exceptions()|ios_base::badbit);

        // Open the output file.
        ofstream ofs{"mydata_output_119"};
        if (!ofs) error("\n\n\tCan't open the output file.\n\t");

        ofs.exceptions(ofs.exceptions()|ios_base::badbit); 
        
        vector<char> c;
        for(char x; ifs.read(as_bytes(x),sizeof(char)); )
            c.push_back(x);

        for(char x:c)
            ofs << x;

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
