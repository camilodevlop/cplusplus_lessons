/*This program accepts two file names and produces a new file that is the content of
the first file followed by the contens of the second.*/

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
    // Open the file of ints.
    ifstream ifi("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_int_108");
    if (!ifi) error("\n\n\tCan't open the file of ints.\n\t");
    
    ifi.exceptions(ifi.exceptions()|ios_base::badbit);

    // Open the file of strings.
    ifstream ifs("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_string_108");
    if (!ifs) error("\n\n\tCan't open the file of strings.\n\t");

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    // Open the output file.
    ofstream ofs("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_output_108");
    if (!ofs) error("\n\n\tCan't open the output file.\n\t");

    try
    {
        // Reading and writing integers.
        for (int i; ifi >> i;)
            ofs << ' ' << i;
            
        end_of_loop(ifi, '|', "\n\n\tBad termination of file 1.\n\t");
        
        // Reading and writing strings.
        ;
        for (string s; ifs >> s;)
            if (s != "|")
                ofs << ' ' << s;
        
        end_of_loop(ifs, '|', "\n\n\tBad termination of file 2.\n\t");

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
        return 2;
    }
}

//------------------------------------------------------------------------------