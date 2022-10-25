/*In this drill all the improvements to the calculator developed in chapter 6 are implemented.
Improvements are proposed in chapter 7.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token
{
    public:
        char kind;                                  // what kind of token
        double value;                               // for numbers: a value
        string name;                                // Variable name in a declaration.

        Token()
            :kind(0) { }
        Token(char ch)                              // make a Token from a char
            :kind(ch) { }
        Token(char ch, double val)                  // make a Token from a char and a double
            :kind(ch),value(val) { }
        Token(char ch, string n)                    // Initialize kind and name.
            :kind(ch), name(n) { }
};

//------------------------------------------------------------------------------

class Token_stream
{
    public:
        
        Token get();                                // get a Token (get() is defined elsewhere)
        void putback(Token t);                      // put a Token back
        void ignore(char c);                        // discard characters up to and including a c.
        
    private:
        bool full = false;                          // is there a Token in the buffer?
        Token buffer = ('8',0);                     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------
// Symbolic constants

const char number = '8';                            // t.kind == number means that is a number Token.
const string ex = "exit";                           // Used to exit the program.
const char quite = 'x';                             // t.kind == quite means that is a exit Token.
const char print = ';';                             // t.kind == print means that is a print Token.
const string prompt = "> ";                         // used to indicate that what follows is the expresion.
const string result = "= ";                         // used to indicate that what follows is a result.
const char let = 'L';                               // used to define constants in the calculator.
const char name = 'a';                              // used to recognize the name of a variable in its declaration.
//const string declkey = "let";                       // Declaration keyword.
const string declkey = "#";                       // Declaration keyword.
const string sqr = "sqrt";                          // It allows to recognize the square root function.
const char sqroot = 's';                            // Used to define the square root function in the calculator.
const string pw = "pow";                            // It allows to recognize the power function.
const char pwr = 'p';                               // Used to define the power function in the calculator.

//------------------------------------------------------------------------------
// The putback() member function puts its argument back into the Token_stream's buffer:

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;                                     // copy t to buffer
    full = true;                                    // buffer is now full
}

//------------------------------------------------------------------------------

Token_stream ts;                                    // provides get() and putback() 

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full)
    {                                              // do we already have a Token ready?
        full = false;                              // remove token from buffer
        return buffer;
    }

    char ch;
    cin >> ch;                                     // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
        case print:                                // const "print" (equal to ';') to print the result.
        case ',':                                  // Required to deal with pow(double,int) function.
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '!':
        case '=':
            return Token(ch);                      // let each character represent itself.
        
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);                       // put digit back into the input stream
            double val;
            cin >> val;                            // read a floating-point number
            return Token(number, val);             // let the const number (equal to '8') represent "a number"
        }
        default:
            if (isprint(ch))                       // Is a printable character?
            {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch;
                cin.putback(ch);
                
                if (s == declkey )
                    return Token(let);             // Declaration keyword.

                if (s == sqr)
                    return Token(sqroot);          // Declaration keyword for the square root.

                if (s == pw)
                    return Token(pwr);             // Declaration keyword for the power.

                if (s == ex)
                    return Token(quite);
                
                return Token(name,s);
            }
            error("Bad token");
    }
}

//------------------------------------------------------------------------------
// discard characters up to and including a c.

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)                   // First look in the buffer.
    {
        full = false;
        return;
    }
    full = false;

    char ch = 0;                                    // Search inputs.
    
    while (cin >> ch)
        if (ch == c)
            return;
}

//------------------------------------------------------------------------------
// Class used to define variables in the calculator.

class Variable
{
    public:
        string name;
        double value;
        Variable(string n, double v) :name(n), value(v) { }
};

//------------------------------------------------------------------------------
// Variable table.

vector<Variable> var_table;

//------------------------------------------------------------------------------
// Return the value of the variable named s.

double get_value(string s)
{
    for(int i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
            return var_table[i].value;

    error("get: undefined variable: ", s);
}

//------------------------------------------------------------------------------
// Set the Variable named s to d.

void set_value(string s, double d)
{
    for (int i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
        {
            var_table[i].value = d;
            return;
        }

    error("det: undefined variable: ", s);
}

//------------------------------------------------------------------------------
// Is var already in var table?

bool is_declared(string s)
{
    for(int i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
            return true;
    
    return false;
}

//------------------------------------------------------------------------------

double factorial(int x)
{
    if (x == 0)
        return 1;
    else
        return x * factorial(x - 1);
}

//------------------------------------------------------------------------------

double expression();                                // declaration so that primary() can call expression()

//------------------------------------------------------------------------------
// deal with numbers and parentheses

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': case '{':   // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        
        if (t.kind != ')' && t.kind != '}' && t.kind != ',')
            error("')', '}' or ',' expected");
        
        if (t.kind == ',')                          // Used to put ',' in the buffer and handle the pow(double,int) function.
            ts.putback(t);
        
        return d;
    }
    case number:                                    // we use the const number (equal to '8') to represent a number
        return t.value;                             // return the number's value

    case sqroot:
        {
            double d = primary();
            if (d < 0)
                cout << "\n\n\tThe square root is not defined for real numbers.\n\t";
            else
                return sqrt(d);                     // Handle "sqrt" '(' expression ')' , i.e., the square root.
        }

    case pwr:                                                    // Cases 'p' (pwr) and ',' handle "pow"'(' expression ')'.
        return pow(primary(), narrow_cast<int>(primary()));      // narrow_cast<int> guarantees an integer exponent.
        
    case ',':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                error("')' expected");
            
            return d;
        }

    case '-':
        return -primary();
    
    case '+':
        return primary();

    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------
// deal with "factorial" !

double fact(){
    double left = primary();
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
        case '!':
            {
                int d = left;
                left = factorial(d);
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------
// deal with *, /, and %

double term()
{
    double left = fact();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind){
        case '*':
            left *= fact();
            t = ts.get();
            break;
        case '/':
        {
            double d = fact();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = fact();
            if (d == 0)
                error("%:divide by zero");
            left = fmod(left,d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------
// deal with + and -

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------
/* Variable declaration: the chosen notation has the form "let var = expresion;"
assume we have seen "let". */

double declaration()
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in decalration of ", var_name);
    
    double d = expression();
    var_table.push_back(Variable(var_name,d));
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
        case let:
            return declaration();
        
        default:
            ts.putback(t);
            return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()
{
    while (cin)
    {
        try
        {
            cout << prompt;              // print prompt.
            Token t = ts.get();

            while (t.kind == print)
                t = ts.get();
            
            if (t.kind == quite)
                return;
            
            ts.putback(t);
            cout << '\t' << result << statement() << '\n';
        }
        catch(exception& e)
        {
            std::cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        var_table.push_back(Variable("k", 1000));

        cout << "\n\n\tWelcome to our simple calculator (Type 'exit' to finish.)\n\n\n\tEnter the expression:\t";
        calculate();
        return 0;
    }
    catch (exception& e)
    {
        cerr << "\n\n\terror: " << e.what() << '\n';
        cout << "\t";
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "\n\n\tException!\n";
        cout << "\t";
        keep_window_open("~~");
        return 2;
    }
}

//------------------------------------------------------------------------------