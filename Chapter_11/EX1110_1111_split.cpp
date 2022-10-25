/* -1110 - Function that returns a vector of whitespace-separate substrings
from the argument s.

- 1111 - Function that returns a vector of whitespace-separate substrings
from the argument s, where whitespace is defined as "ordinary whitespace" plus
the characters in w.*/

#include <iostream>
#include <fstream>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

// Response to exercise EX1110.

/*
vector<string> split(const string& s)
{
   vector<string> spl;
   istringstream is {s};
   string aux = " ";

   while(is>>aux)
      spl.push_back(aux);

   return spl;
}
*/

//------------------------------------------------------------------------------

// Classify the whitespaces.

bool is_whitespace(const char c, const string white)
{
   for(char w : white)
      if(c==w) return true;

   return false;
}

//------------------------------------------------------------------------------

// Returns a vector of whitespace-separate substrings.

vector<string> split(const string& s,const string w)
{
   vector<string> spl;
   string aux = "";

   for(char ch : s)
   {
      if(is_whitespace(ch,w))
      {
         if(ch == ' ')
         {
            spl.push_back(aux);
            aux = "";
         }
      }
      else
      {
         aux+=ch;   
         if(ch == s[s.size()-1])          // Includes de last string read.
            spl.push_back(aux);
      }
   }   

   return spl;
}

//------------------------------------------------------------------------------

int main()
{
   try 
   {
      cout << "\n\n\tProgram returns a vector of whitespaces-separate substrings."
         << "Whitespace is defined as \" \" plus other characters.\n\n\t"
         << "Enter the string to be split:\n\t";
      
      string s;
      getline(cin,s);

      vector<string> spl;
      spl = split(s,"&#@\ ;:");

      cout << "\n\n\tThe strings are listed below:\n\n\t";
      for(int i = 0 ; i < spl.size(); ++i)
         cout << "\n\t" << spl[i];

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
