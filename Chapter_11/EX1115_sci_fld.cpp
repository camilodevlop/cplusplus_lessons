/*Program that reads a file of whitespace-separated numbers and outputs a file
 of numbers using scientific format and precision 8 in four fields of 20 
 characters per line.*/

#include <iostream>
#include <fstream>
#include <iomanip>                      // Required to use setw().

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    try
    {
        cout << "\n\n\tReads a file of whitespace-separated numbers and outputs"
             << " a file of numbers using scientific format and precision 8.\n\t";

        // Opening the input and ouput files.
        ifstream ifs{"mydata_i_scifld_1115"};
        if(!ifs) error("\n\n\tCan't open the input file.\n\t");
        
        ofstream ofs{"mydata_o_scifld_1115"};
        if(!ofs) error("\n\n\tCan't open the output file.\n\t");

        ofs << setprecision(8);
        double d;
        int num_counter = 0;                // If this is 4, skip a line.
        
        while(ifs>>d)
        {
            ofs << setw(20) << scientific << d;
            ++num_counter;
            if(num_counter == 4)
            {
                ofs << '\n';
                num_counter = 0;
            }
        }

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
