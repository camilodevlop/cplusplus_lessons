/*Write a program that checks if a sentence is correct according to the "English" grammar in 6.4.1. The program should simply respond
"Ok" or "not Ok". The program execution ends if the user enters " . ".*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
class Word_type
{
    public:
        char kind;                              // What kind of word (noun, verb, article or conjuntion).
        string value;                           // for strings: a string.
        Word_type()                             // Make a Word_type from a char and a string.
            :kind('u'),value("undefined") { }
        Word_type(char ch, string val)          // Make a Word_type from a char and a string.
            :kind(ch),value(val) { }
};
//------------------------------------------------------------------------------
class String_stream
{
    public:
        Word_type get();                // get a Word_type object.
        void put_back(Word_type w);      // Put a Word_type object back.

    private:
        bool full = false;              // is there a Word_type object in the buffer?
        Word_type buffer;
};
//------------------------------------------------------------------------------
// The put_back() member function puts its argument back into the String_stream's buffer:
void String_stream::put_back(Word_type w)
{
    if (full)
        error("put_back() into a full buffer");

    buffer = w;
    full = true;
}
//------------------------------------------------------------------------------
String_stream ss; // provides get() and put_back().
//------------------------------------------------------------------------------
Word_type String_stream::get()
{
    if (full)                           // do we already have a Word_type object ready?
    {
        full = false;
        return buffer;
    }

    string s;
    cin >> s;

    if(s == "the")                                      // article?
        return Word_type('a', s);
    
    if (s == "birds" or s == "fish" or s == "C++")      // noun?
        return Word_type('n', s);
    
    if (s == "rules" or s == "fly" or s == "swim")      // verb?
        return Word_type('v', s);

    if (s == "and" or s == "or" or s == "but")          // conjunction?
        return Word_type('c', s);

    return Word_type('u', s);                           // undefined type of word.
}
//------------------------------------------------------------------------------
// deal wirh articles or nouns.
string article ()
{
    Word_type word = ss.get();

    switch (word.kind)
    {
    case 'a':
        return word.value;
    
    case 'n':
        ss.put_back(word);
        return "";
    
    default:
        error("\n\tNot ok, article or noun expected\n");
    }
}
//------------------------------------------------------------------------------
// deal wirh nouns.
string noun ()
{
    string left = article();
    Word_type word = ss.get();

    switch (word.kind)
    {
    case 'n':
        if (left == "")
            left = word.value;
        else
            left = left + " " + word.value;
        
        word = ss.get();
        ss.put_back(word);
        return left;
    
    default:
        error("\n\tNot ok, noun expected\n");
    }
}
//------------------------------------------------------------------------------
// deal with verbs.
string verb()
{
    string left = noun();
    Word_type word = ss.get();
        
    switch (word.kind)
    {
    case 'v':
        left = left + " " + word.value;
        word = ss.get();
        ss.put_back(word);
        return left; 
    
    default:
        error("\n\tNot ok, verb expected\n");
    }
}
//------------------------------------------------------------------------------
string sentence();              // declaration so that sentence() can call itself.

// deal with conjunctions.
string sentence()
{
    string left = verb();
    Word_type word = ss.get();

    while (true)
    {
        switch (word.kind)
        {
        case 'c':
            left = left + " " + word.value + " " + sentence();
            word = ss.get();
            break;
        
        default:
            ss.put_back(word);
            return left; 
        }        
    }
}
//------------------------------------------------------------------------------
int main ()
{
    try
    {
        string s = " ";
        cout << "\n\tWelcome to a simple English sentence classifier\n\n\tEnter the sentence (Press x to exit):\t";
        
        while (cin)
        {
            Word_type word = ss.get();
            
            if (word.value == "x") break;
            if (word.value == ".")
                if (s == " ")
                    cout << "\tNot Ok, the sentence is incomplete. \n\n\n\tEnter the sentence:\t";
                else
                    cout << "\tOk, " << s << "\n\n\n\tEnter the sentence:\t";
            else
                ss.put_back(word);
            
            s = sentence();
        }
        return 0;
    }
    catch(exception& e)
    {
        cerr << "\n\tError: " << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\tOops: unknown exception!\n";
        return 2;
    }
}