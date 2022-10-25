/*In this program the capabilities of the C++ language to manage exceptions are explored.*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

class Except
{
    public:
        class invalid {};                           // Exception defined by the programmer.
        int division(int& a, int& b)
        {
            if (b == 0) throw (b);
            return a / b;
        }            
};

//------------------------------------------------------------------------------

int main ()
{
    class n_true{};
    Except ext;

    try
    {
        vector<int> test(10);
        
        string x = "hello";
        string y = "Bye";

        /*if (x == "hel")
            throw (x);
        if (y == "Bye")
            throw (y);*/
        
        //if (true)
        //    throw n_true();
        
        // test.at(20) = 100;                   // Out of range vector.

        //int val1 = 1;
        //int val2 = 2;
        //ext.division(val1,val2);                // Exception sent from the Except class.

        error("\n\n\tError test.\n\n\t");

        return 0;
    }
    catch(const string& strx)
    {
        cerr << "\n\n\tBad string\n\t" << strx;
        return 1;
    }
    catch(const int& intx)
    {
        cerr << "\n\n\tBad int\n\t" << intx;
    }
    catch(const out_of_range& e)
    {
        cerr << "\n\n\tOut of range\n\t" << e.what();
        return 1;
    }
    /*catch(const runtime_error& e)
    {
        cerr << "\n\n\tRun time error.\n\t" << e.what();
        return 1;
    }*/
    catch(Except::invalid)
    {
        cerr << "\n\n\tInvalid argument in except class.\n\t";
        return 1;
    }
    catch(n_true)
    {
        cerr << "\n\n\tNo true\n\t";
        return 1;
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