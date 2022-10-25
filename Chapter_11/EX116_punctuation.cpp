/*Program that replaces puntuation with whitespace. Consider . ; , ? - ' as 
punctuation character. Don't modify characters within a pair of double quotes
"" .*/

#include <iostream>
#include <string>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

class Punct_stream      // Like an istream, but the user adds the punctuation.
{
    public:
        Punct_stream(istream& is)
            :source(is),sensitive(true),quotes_on(false),quote_counter(0) {}

        // Nonmodifying operations.
        bool is_whitespace(char c);     // is c in the punctuation set?
        bool is_case_sensitive(){return sensitive;}
        operator bool();
        void quotes();

        // Modifying operations.
        void whitespace(const string& s){white = s;} // Make s the punctuation.
        void add_white(char c){white += c;}     // Add to the whitespace set.
        void case_sensitive(bool b){sensitive = b;}
        Punct_stream& operator>>(string& s);

    private:
        istream& source;            // Character source.
        istringstream buffer;       // Buffer do the formatting,
        string white;               // Characters considered "whitespaces";
        bool sensitive;             // Is the stream case-sensitive?
        bool quotes_on;             // Quote Manager.
        int quote_counter;          // Warns when marks are opened and closed.
};

//------------------------------------------------------------------------------

Punct_stream& Punct_stream::operator>>(string& s)
{
    while(!(buffer>>s))             // Try to read from buffer.
    {
        if(buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source,line,'"');       // Get a line from source to '"'.

        if(!source.eof())
            quotes();                   // Manages the finding of a quote.
 
        // do character replacement as needed;
        for(char& ch : line)
        {
            if(is_whitespace(ch) && !quotes_on)
                ch = ' ';               // To space.
            else if(!sensitive)
                ch = tolower(ch);       // To lower case.
        }
        
        if(quotes_on)
        {
            line.push_back(' ');        // Allows strings to be inserted
            quotes_on = false;          // through the buffer.
        }

        buffer.str(line);               // Put string into stream.
    }
    return *this;
}

//------------------------------------------------------------------------------

void Punct_stream::quotes()
{
    ++quote_counter;
    if(quote_counter == 2)
    {
        quotes_on = true;           // The line is enclosed in quotation marks. 
        quote_counter = 0;
    } 

    return;
}

//------------------------------------------------------------------------------

bool Punct_stream::is_whitespace(char c)
{
    for(char w : white)
        if(c==w) return true;

    return false;
}

//------------------------------------------------------------------------------

Punct_stream::operator bool()
{
    return !((source.fail()) || source.bad()) && buffer.good();
}

//------------------------------------------------------------------------------

int main()
{
    Punct_stream ps{cin};
    ps.whitespace(".;,?-'");
    ps.case_sensitive(false);

    cout << "\n\n\tPlease enter words"
         << "(Press enter and then Ctrl + D to finish.)\n\t";
    vector <string> vs;

    for(string word ; ps>>word;)
        vs.push_back(word);             // Read words.

    sort(vs.begin(),vs.end());          // Sort in the lexicographical order.
    cout << "\n\n\tThe entered words are:\n\t";
    for(int i=0 ; i < vs.size() ; ++i)  // Write dictionary.
        if(i==0 || vs[i]!=vs[i-1]) cout << vs[i] << "\n\t";

    return 0;
}

//------------------------------------------------------------------------------
