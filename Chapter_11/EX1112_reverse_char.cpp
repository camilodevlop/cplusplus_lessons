/* Program that reverse the order of characters in a text file.*/

#include <fstream>
#include <iostream>
#include <string>

#include "runtime_errors.h"
using namespace std;

//------------------------------------------------------------------------------

int main()
{
   try
   {
       cout << "\n\n\tProgram that reverse the order of characters in a text file.\n\t";
       
       fstream fs{"mydata_1112"};
       if(!fs) error("\n\tCan't open input/output file.\n\t");

       // Reading the information. 
       string s;
       for(string aux; fs>>aux;)
           s+=(aux + ' ');

       // Restart the source state.
       fs.clear();  

       // Writing the characters.
       int sz = s.size() - 1;
       for(int i=0; i <= sz; ++i) 
       {
           fs.seekp(i);
           fs << s[sz-i];
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
