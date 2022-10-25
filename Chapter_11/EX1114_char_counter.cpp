/*Program that reads a text file and writes out how many characters of each
 character classification are in the file.*/

#include <iostream>
#include <fstream>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

class Char_classifier
{
    public:
        Char_classifier(istream& is):source(is) {}

        // Nonmodifying operations.
        string char_type(int i) const {return c_type[i];}
        int char_type_count(int i) const {return c_type_count[i];}
        int number_types() const {return n_types;}

        // Modifying operations.
        void classify();

    private:
        istream& source;
        const int n_types = 7;        // Number of character types.
        void classifier(const char&);      // Counts chars according to
                                           // their classification.
        
        // Vector of count char type.
        vector<int> c_type_count{0,0,0,0,0,0,0}; 
        // Vector of char type.
        vector<string> c_type{"letters or numbers","letters","uppercases",
                                 "lowercases","numbers","spaces",
                                 "ASCII printable or control chars"};
};

//------------------------------------------------------------------------------

void Char_classifier::classify()
{
    char ch;

    while(source.get(ch))
        classifier(ch);

    return;
}

//------------------------------------------------------------------------------

void Char_classifier::classifier(const char& ch)
{
    if(isalnum(ch))
    {
        ++c_type_count[0];
        if(isalpha(ch))
        {
            ++c_type_count[1];
            isupper(ch)? ++c_type_count[2] :
                         ++c_type_count[3];
        }
        else
            ++c_type_count[4];
    }
    else
    {
        if(isspace(ch))     
            ++c_type_count[5];
        else
            ++c_type_count[6];
    }

    return;
}

//------------------------------------------------------------------------------

int main()
{
   try
   {
       cout << "\n\n\tReads a text and writes out how many characters"
            << " of each character classification are in the file.\n\t";

       ifstream ifs{"mydata_char_counter_1114"};
       if(!ifs) error("\n\n\tCan't open input file.\n\t");

       Char_classifier cl{ifs}; 
       cl.classify();

       cout << "\n\n\tNumber of each character classification:\n\n\t";
       for(int i=0; i < cl.number_types(); ++i) 
           cout << "- " << cl.char_type(i) << " = " << cl.char_type_count(i)
                << "\n\t";

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
