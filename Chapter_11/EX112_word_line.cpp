/*Program that given a file name and a word outputs each line that contains
that word toguether with the line number.*/

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "runtime_errors.h"

using namespace std;

///------------------------------------------------------------------------------

class Word_line
{
    public:
        // Constructor.
        Word_line(istream& is, const string& s)
            :source{is},word{s},line_counter{0} {}

        // Nonmodifying operations.
        void print_lines() const;        // Printing lines that contain the word.

        // Modifying operations.
        void whitespace(const string& s) {word = s;}    // Make 's' the keyword.
        void word_line_search();

    private:
        istream& source;                 // Source file.
        int line_counter;                // Counts the number of lines processed.
        vector <int>lines;               // Lines that contain the word.
        string word;
        istringstream buffer;            // We let buffer do the search.

};

//------------------------------------------------------------------------------

void Word_line::word_line_search()
{
    while(source.good())
    {
        string s,line;

        getline(source,line);
        ++line_counter;

        buffer.str(line);
        while(buffer>>s)
            if(s==word)
            {
                lines.push_back(line_counter);
                break;
            }           
    }

    return;
}

//------------------------------------------------------------------------------

void Word_line::print_lines() const
{
    if(lines.size() == 0)
        cout << "\n\t" << word << " is not found on any lines.\n\t";
    else
        for(int i:lines) cout << i << '\t';

    return;
}

//------------------------------------------------------------------------------

int main()
{
    try
    {

    // Input the file mane and the keyword.
    string file_name, keyword;
    cout << "\n\n\tInput the name of source file and the keyword\n\t";
    cin >> file_name >> keyword;    // file_name = "mydata_input_112" 
                                    // keyword = "test"
    
    // Open the input file.
    ifstream ist{file_name};
    if (!ist) error("\n\n\tCan't open the input file.\n\t",file_name);

    Word_line wl{ist,keyword};
    wl.word_line_search();
    
    cout << "\n\n\tThe word " << keyword << " is in the following lines:\n\t";
    wl.print_lines();

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
