/*Cap. 11 EX. 6 - Program that replaces puntuation with whitespace. Consider . ; , ? - ' as 
punctuation character. Don't modify characters within a pair of double quotes
"" .
Cap. 11 EX. 7 - Modify the program so that it replaces don't with do not, can't
with cannot, etc. Leaves hyphens within words intact.*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

// Allows to replace expressions, for example, Can't by Cannot.

struct Replace_exp
{
    Replace_exp():p_exp(-1) {}

    // Modify operations.
    bool is_exp(string);        // Looks in the vector t_exp for the string s.
    void restart_p_exp() {p_exp = -1;}

    int p_exp;                  // Position of found expression.

    // Target expressions and replace expressions.
    vector <string> t_exp{"don't", "can't", "won't"};
    vector <string> r_exp{"do not","cannot","will not"};
};

// Looks in the vector t_exp for the string s.

bool Replace_exp::is_exp(string s)
{
    size_t found;
    for(int i = 0; i < t_exp.size(); ++i)
    {
        found = s.find(t_exp[i]);
        if(found != string::npos)
        {
            p_exp = i;
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------------

class Punct_stream      // Like an istream, but the user adds the punctuation.
{
    public:
        Punct_stream(istream& is)
            :source(is),sensitive(true),quotes_on(false),quote_counter(0),
             inspect_exp(false) {}

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
        void replace(string&, string&);

    private:
        istream& source;            // Character source.
        istringstream buffer;       // Buffer do the formatting,
        string white;               // Characters considered "whitespaces";
        bool sensitive;             // Is the stream case-sensitive?
        bool quotes_on;             // Quote Manager.
        int quote_counter;          // Warns when marks are opened and closed.
        bool inspect_exp;           // Is it necessary to inspect the word to replace it?
        Replace_exp r;              // An object that manages expression substitutions.
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

        line.insert(0," ");             // Set the start of the string.

        // do character replacement as needed;
        string s = "";
        for(int i = 1; i < line.size(); ++i)
        {
           char& ch = line[i];

           if(is_whitespace(ch) && !quotes_on)
                switch(ch)
                {
                    case '\'':
                       inspect_exp = true;      // Inspect expression.
                       break;
                    case '-':
                       if(!(isalpha(line[i-1]) && isalpha(line[i+1])))
                           ch = ' ';
                       break;
                    default:
                       ch = ' ';                // To space.
                       break;
                }
            else if(!sensitive)
                ch = tolower(ch);               // To lower case.

            s += ch;                    // Break the line into words.
            if(isspace(ch))             // Check if the word finished.
               replace(s,line);         // Replaces an expression. initializes s.
        }
        
        if(quotes_on)
        {
            line.push_back(' ');        // This space allows strings to be 
            quotes_on = false;          // inserted through the buffer.
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

// If 's' contains a target expression (e.g., don't, won't, or can't), it
// replaces in 'line' a replace expresion (e.g., do not, will not, etc.).
// This function restart 's'.

void Punct_stream::replace(string& s,string& line)
{
    if(inspect_exp && r.is_exp(s))
    {
        size_t found = line.find(r.t_exp[r.p_exp]);
        while(found != string::npos)
        {
            line.replace(found,r.t_exp[r.p_exp].size(),r.r_exp[r.p_exp]);
            found = line.find(r.t_exp[r.p_exp],found);
        }
    }  
                
    r.restart_p_exp();      // Position of found expression.
    inspect_exp = false;
    s = "";

    return;
}

//------------------------------------------------------------------------------

int main()
{
    Punct_stream ps{cin};
    ps.whitespace(".;,?-'");
    ps.case_sensitive(false);

    cout << "\n\n\tPlease enter words "
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
