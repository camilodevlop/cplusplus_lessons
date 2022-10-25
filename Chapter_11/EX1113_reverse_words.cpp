/*Program that reverses the order of words (defined as whitespace-separated
 strings) in a file.*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
{
   try
   {
       cout << "\n\n\tProgram that reverse the order of words in a text file.\n\t";
       
       fstream fs{"mydata_reverse_words_1113"};
       if(!fs) error("\n\tCan't open input/output file.\n\t");

       // Reading the information. 
       vector<string> st;
       string s;
       while(fs>>s)
        st.push_back(s);

       // Restart the source state.
       fs.clear();
       fs.seekp(0);

       // Writing the characters.
       int sz = st.size() - 1;
       for(int i=0; i <= sz; ++i) 
           fs << st[sz-i] << " ";

       cout << "\n\n\tProcess completed successfully..\n\t";
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
