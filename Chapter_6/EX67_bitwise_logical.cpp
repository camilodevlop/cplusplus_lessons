/*Write a grammar for bitwise logical expressions. Precedence order: (not !  ~ complement), (and &), (exclusive or ^), (or |).*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
class Token{
public:
    char kind;                          // what kind of token.
    int value;                          // for numbers: a value.
    Token(char ch)                      // make a Token from a char.
        :kind(ch), value(0) { }
    Token(char ch, int val)             // make a Token from two char.
        :kind(ch),value(val) { }
};

//------------------------------------------------------------------------------
class Token_stream {
public:
    Token get();                    // get a Token (get() is defined elsewhere).
    void putback(Token t);          // put a Token back.
    
private:
    bool full = false;              // is there a Token in the buffer?
    Token buffer = ('n',0);         // 'n' refers to number. Here is where we keep a Token put back using putback().
};

//------------------------------------------------------------------------------
// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer.
    full = true;      // buffer is now full.
}
//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback().

//------------------------------------------------------------------------------
Token Token_stream::get()
{
    if (full)               // do we already have a Token ready?
    {       
        full = false;       // remove token from buffer.
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.).

    switch (ch)
    {
        case '=':    // for "print"
        case 'x':    // for "quit"
        case '!': case '~': case '&': case '^': case '|':
            return Token(ch);       // let each character represent itself.

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream.
            double val;
            cin >> val;              // read a floating-point number.
            return Token('n', val);   // let 'n' represent "a number".
        }
        default:
            error("Bad token");
    }
}
//------------------------------------------------------------------------------
int primary ();              // declaration so that primary () can call itself.

// deal with numbers, not (!) and complement (~).
int primary ()
{
    Token t = ts.get();
    switch (t.kind) 
    {
        case '!':
            return !primary();
        case '~':
            return ~primary();
        case 'n':                       // we use 'n' to represent a number.
            return t.value;             // return the number's value.
        default:
            error("primary expected");
    }
}

//------------------------------------------------------------------------------
// deal with not 'and' operation (&).
int and_op ()
{
    int left = primary();
    Token t = ts.get();
    
    while (true)
    {
        switch (t.kind)
        {
            case '&':
                left = left & primary();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
//------------------------------------------------------------------------------
// deal with 'exclusive or' operation (^).
int exclusive_or_op ()
{
    int left = and_op();
    Token t = ts.get();
    
    while (true)
    {
        switch (t.kind)
        {
            case '^':
                left = left ^ and_op();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
//------------------------------------------------------------------------------
// deal with 'or' operation (|).
int or_op()
{
    int left = exclusive_or_op();
    Token t = ts.get();
    
    while (true)
    {
        switch (t.kind)
        {
            case '|':
                left = left | exclusive_or_op();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
//------------------------------------------------------------------------------
int main()
    try
    {
        int val = 0;
        cout << "\n\n\tWelcome to our program for bitwise logical expressions (Press x to exit.)\n\n\n\tEnter the expression:\t";
        
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'x') break; // 'x' for quit
            if (t.kind == '=')        // '=' for "print now"
                cout << "\n\t"<< val << "\n\n\n\tEnter the expression:\t";
            else
                ts.putback(t);
            val = or_op();
        }
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
}
//------------------------------------------------------------------------------