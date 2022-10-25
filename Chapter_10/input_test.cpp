/*Program that the input objects.*/
// camiloalejandrocastillobenavides@MacBook-Pro-de-Camilo

#include <iostream>
#include <fstream>
#include <string>

#include "std_lib_facilities.h"
using namespace std;

ifstream ist;

//------------------------------------------------------------------------------
// End of standard input loop.

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


char test1(istream& is)
{
    while (is)
    {
        char ch;
        is >> ch;

        switch (ch)
        {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return ch;
        
        default:
            if (isprint(ch))
            {
                string s;
        		s += ch;
                
                while (is.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;

                is.putback(ch);
                if (s == "help")
                    return 'h';

                if (s == "from")
                    return 'f';
                
                if (s == "EF")
                    return 'e';

                if (s == "quit")
                    return 'q';

                return 'n';                 // No token;
            }
        }
    }
}
// camb es un texto de prueba. Palabras adicionales para la prueba.
//------------------------------------------------------------------------------

void operate(istream& is)
{
    char ch;

    while (true)
    {
        ch = test1(is);

        if (isdigit(ch))
        {
            cout << "\n\tEntered number = " << ch << "\n\t";
            continue;
        }
            
        if (ch == 'h')
        {
            cout << "\n\n\tThis is the help.\n\t";
            continue;
        }
            
        if (ch == 'f')
        {
            // Opening the file.
            
            cout << "\n\n\tNumbers from file:\n\t";
            
            ifstream ist("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_intput_test");
            if (!ist) error("\n\n\tCan't output the input file.\n\n\t");
            ist.exceptions(ist.exceptions()|ios_base::badbit);      // Make ist throw if it goes bad.

            operate(ist);                                           // Operating the file data.
            ist.close();

            cout << "\n\n\tNumbers from console emulator:\n\t";
            continue;
        }

        if (ch == 'e' || ch == 'q')
            return;
    }
}

//------------------------------------------------------------------------------

int main ()
{   
    try
    {
        cout << "\n\n\tEnter the numbers:\n\t";
        
        while (true)
            {
                operate(cin);
                return 0;
            }
    }
    catch(exception& e)
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
