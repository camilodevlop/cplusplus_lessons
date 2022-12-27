/*A simple text editor.*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;
using Line = vector<char>;

//--------------------------------------------------------------------

// Keep track of line and character position within a line.

class Text_iterator
{
    list<Line>::iterator ln;
    Line::iterator pos;

public:
    // Start the iterator at line ll's character position pp:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
                 : ln{ll}, pos{pp} {}

    char& operator*(){ return *pos; }
    Text_iterator& operator++();

    bool operator==(const Text_iterator& other) const
        { return ln == other.ln && pos == other.pos; }
    bool operator!=(const Text_iterator& other) const
        { return !(*this == other); }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if(pos == (*ln).end())      // vector<char>'s final.
    {
        ++ln;
        pos = (*ln).begin();
    }

    return *this;
}

//--------------------------------------------------------------------

struct Document
{
    list<Line> line;
    Document() { line.push_back(Line{}); }

    // First character of first line.
    Text_iterator begin()
        { return Text_iterator(line.begin(), (*line.begin()).begin());}

    // One beyond the last character of the last line.

    Text_iterator end()
    {
        auto last = line.end();
        --last;
        return Text_iterator(last, (*last).end());
    }
};

//--------------------------------------------------------------------

istream& operator>>(istream& is, Document& d)
{
    for(char ch; is.get(ch);)
    {
        d.line.back().push_back(ch);    // Add the character.
        if(ch == '\n')
            d.line.push_back(Line{});
    }
    
    if(d.line.back().size()) d.line.push_back(Line{});

    return is;
}

//--------------------------------------------------------------------

void print(Document& d)
{
    for(auto p : d) cout << p;
}

void erase_line(Document& d, int n)
{
    if(n<0 || d.line.size()-1<=n) return;
    auto p = d.line.begin();
    advance(p,n);
    d.line.erase(p);
}

//--------------------------------------------------------------------

bool match(Text_iterator p, Text_iterator last, const string& s)
{
    for(char c:s)
    {
        if(c != *p || p == last)    return false;
        ++p;
    }
    return true;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last,
                       const string& s)
{
    if(s.size() == 0)   return last;
    char first_char = s[0];

    while(true)
    {
        auto p = find(first, last, first_char);
        if(p == last || match(p,last,s)) return p;
        first = ++p;
    }
}

//--------------------------------------------------------------------

int main()
{
    Document d;
    cout << "\nInput the text:\n";
    cin >> d;
    cout << "\n\n";   print(d);

    auto p = find_txt(d.begin(), d.end(), "dro\ncas");
    if(p == d.end())
        cout << "\n\tNot found.\n";
    else
        cout << "\n\tString found.\n";

    erase_line(d,0);
    cout << "\nLine 0 deleted:\n";   print(d);

    return 0;
}

//--------------------------------------------------------------------
