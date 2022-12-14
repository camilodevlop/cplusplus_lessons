/*In this set of exercises all the improvements to the calculator developed in chapter 6 are implemented.
1. Make the input stream an explicit parameter, rather than simply using cin. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctype.h>

#include "std_lib_facilities.h"

using namespace std;

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
        
        Token get(istream&);                        // get a Token (get() is defined elsewhere)
        void putback(Token t);                      // put a Token back
        void ignore(char c, istream&);              // discard characters up to and including a c.
        bool integers = false;                      // Modifier to operate on ints (only).
        
    private:

        bool full = false;                          // is there a Token in the buffer?
        Token buffer = ('8',0);                     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------
// Symbolic constants

const char number = '8';                            // t.kind == number means that is a number Token.
const string ex = "quit";                           // Used to exit the program.
const char quite = 'x';                             // t.kind == quite means that is a exit Token.
const char print = ';';                             // t.kind == print means that is a print Token.
const string prompt = "> ";                         // used to indicate that what follows is the expresion.
const string result = "= ";                         // used to indicate that what follows is a result.
const char let = 'L';                               // used to define variables in the calculator.
const char name = 'a';                              // used to recognize the name of a variable in its declaration.
const string declkey = "#";                         // Declaration keyword for variables.
const char cons = 'C';                              // Allows the user to define constants in the calculator.
const string declkey_const = "const";               // Declaration keyword for constants.
const string sqr = "sqrt";                          // It allows to recognize the square root function.
const char sqroot = 's';                            // Used to define the square root function in the calculator.
const string pw = "pow";                            // It allows to recognize the power function.
const char pwr = 'p';                               // Used to define the power function in the calculator.
const char help = 'h';                              // Used to define the Token of help.
const string hlp = "help";                          // Keyword to request help from the calculator.
const char integer = 'i';                           // Used to define the Token of Integers.
const string intes = "integers";                    // Keyword to request the use of integers only
const string fromx = "from";                        // Keyword for reading input from a file x.
const char from = '@';                              // Used to use inputs from a file x.
const char end_file = '|';                          // The file contains no further instructions.
const string tox = "to";                            // Keyword for writing outputs to a file x.
const char to = '<';                                // Used to open the output file x.
const string etox = "end_to";                       // Keyword for closing the output file x.
const char end_to = '^';                            // The file x is no longer required to write the outputs.

//------------------------------------------------------------------------------
// The putback() member function puts its argument back into the Token_stream's buffer:

void Token_stream::putback(Token t)
{	
    if (full) error("putback() into a full buffer");
    buffer = t;                                     // copy t to buffer
    full = true;                                    // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get(istream& is)
{
    if (full)
    {                                              // do we already have a Token ready?
        full = false;                              // remove token from buffer
        return buffer;
    }

    char ch;
    do                                             // note that >> skips whitespace (space, newline, tab, etc.) 
    {
        ch = is.get();
        if (ch == '\n')                            // If 'true', the calculator prints the result.
            return Token(print);
    } while (isspace(ch));                   
    
    switch (ch)
    {
        case ',':                                    // Required to deal with pow(double,int) function.
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
        case end_file:                             // End of file x. 
            return Token(ch);                      // let each character represent itself.
        
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            is.putback(ch);                       // put digit back into the input stream
            double val;
            is >> val;                            // read a floating-point number
            
            return Token(number, val);             // let the const number (equal to '8') represent "a number"
        }
        default:
            if (isprint(ch))                       // Is a printable character?
            {
                string s;
                s += ch;
                while (is.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;

                is.putback(ch);

                if (s == declkey)
                    return Token(let);             // Declaration keyword for variables.

                if (s == declkey_const)
                    return Token(cons);            // Declaration keyword for constants.
                
                if (s == sqr)
                    return Token(sqroot);          // Declaration keyword for the square root.

                if (s == pw)
                    return Token(pwr);             // Declaration keyword for the power.

                if (s == hlp)                      // Declaration keyword for help.
                    return Token(help);

                if (s == intes)                     // Declaration keyword for integers.
                    return Token(integer);
                
                if (s == ex)                        // Declaration of keyword for exit from the calculator.
                    return Token(quite);

                if (s == fromx)                     // Declaration of keyword for open the file x.
                    return Token(from);
                
                if (s == tox)                       // Declaration of keyword for open the output file x.
                    return Token(to);
                
                if (s == etox)                      // Declaration of keyword for close the output file x.
                    return Token(end_to);
                
                return Token(name,s);               // Used to manage variables.
            }
            error("Bad token");
    }
}

//------------------------------------------------------------------------------
// discard characters up to and including a c.

void Token_stream::ignore(char c,istream& is)
{
    if (full && c == buffer.kind)                   // First look in the buffer.
    {
        full = false;
        return;
    }
    full = false;

    char ch = 0;                                    // Search inputs.
    
    while (is >> ch)
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
        char type;                                  // 'C' for const and 'L' for variable.
        Variable(string n, double v, char t) : name(n), value(v), type(t) { }
};

//------------------------------------------------------------------------------
// Variable table.
class Symbol_table
{
    public:
        vector<Variable> var_table;
        
        double get_value(string s);
        void set_value(string s, double d);
        bool is_declared(string s);
};

Symbol_table st;                                      // Provides...

//------------------------------------------------------------------------------
// Return the value of the variable named s.

double Symbol_table::get_value(string s)
{
    for(int i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
            return var_table[i].value;

    error("get: undefined variable: ", s);
}

//------------------------------------------------------------------------------
// Set the Variable named s to d.

void Symbol_table::set_value(string s, double d)
{
    for(int i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
        {
            if (var_table[i].type == let)
            {
                var_table[i].value = d;
                return;
            }
            else
            
                error("The referenced variable was declared as a constant: ", var_table[i].name);
        }

    error("det: undefined variable: ", s);
}

//------------------------------------------------------------------------------
// Is var already in var table?

bool Symbol_table::is_declared(string s)
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
// Declaration so that primary() can call expression().

double expression(Token_stream&,istream&);                                

//------------------------------------------------------------------------------
// deal with numbers, commas, and parentheses

double primary(Token_stream& ts,istream& is)
{
    Token t = ts.get(is);
    switch (t.kind) {
    case '(': case '{':   // handle '(' expression ')'
    {
        double d = expression(ts,is);
        t = ts.get(is);
        
        if (t.kind != ')' && t.kind != '}' && t.kind != ',')
            error("')', '}' or ',' expected");
        
        if (t.kind == ',')                              // Used to put ',' in the buffer and handle the pow(double,int) function.
            ts.putback(t);
        
        return d;
    }
    case number:                                        // we use the const number (equal to '8') to represent a number
        if (ts.integers == true)                        // Conversion to integers.
            return narrow_cast<int> (t.value);
        
        return t.value;                                     // return the number's value

    case sqroot:
        {
            double d = primary(ts,is);
            if (d < 0)
                error("\n\n\tThe square root is not defined for real numbers.\n\t");
            else
                return sqrt(d);                                     // Handle "sqrt" '(' expression ')' , i.e., the square root.
        }

    case pwr:                                                         // Cases 'p' (pwr) and ',' handle "pow"'(' expression ')'.
        return pow(primary(ts,is), narrow_cast<int>(primary(ts,is)));      // narrow_cast<int> guarantees an integer exponent.
        
    case ',':
        {
            double d = expression(ts,is);
            t = ts.get(is);
            if (t.kind != ')')
                error("')' expected");
            
            return d;
        }

    case name:
        {
            if (st.is_declared(t.name))
                return st.get_value(t.name);
        }

    case '-':
        return -primary(ts,is);
    
    case '+':
        return primary(ts,is);
    
default:
        error("primary expected");
    } 
}

//------------------------------------------------------------------------------
// deal with "factorial" !

double fact(Token_stream& ts,istream& is)
{
    double left = primary(ts,is);
    Token t = ts.get(is);

    while (true)
    {
        switch (t.kind)
        {
        case '!':
            {
                int d = left;
                left = factorial(d);
                t = ts.get(is);
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

double term(Token_stream& ts,istream& is)
{
    double left = fact(ts,is);
    Token t = ts.get(is);        // get the next token from token stream

    while (true) {
        switch (t.kind){
        case '*':
            left *= fact(ts,is);
            t = ts.get(is);
            break;
        case '/':
        {
            double d = fact(ts,is);
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get(is);
            break;
        }
        case '%':
        {
            double d = fact(ts,is);
            if (d == 0)
                error("%:divide by zero");
            left = fmod(left,d);
            t = ts.get(is);
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

double expression(Token_stream& ts,istream& is)
{
    double left = term(ts,is);      // read and evaluate a Term
    Token t = ts.get(is);        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(ts,is);    // evaluate Term and add
            t = ts.get(is);
            break;
        case '-':
            left -= term(ts,is);    // evaluate Term and subtract
            t = ts.get(is);
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

double declaration(char ty, Token_stream& ts, istream& is)                     // ty is 'C' (constant) or 'L' (variable).
{
    Token t = ts.get(is);
    if (t.kind != name)
        error("name expected in declaration");
    string var_name = t.name;

    if (st.is_declared(var_name))
        error("The variable is already declared: ", var_name);
    
    Token t2 = ts.get(is);
    if (t2.kind != '=')
        error("= missing in declaration of ", var_name);
    
    double d = expression(ts,is);

    if (ty == let)
        st.var_table.push_back(Variable(var_name, d, let));
    else
        st.var_table.push_back(Variable(var_name, d, cons));

    return d;
}

//------------------------------------------------------------------------------
/* Variable assignment: the chosen notation has the form "var_name = expresion;"
*/

double assignment(Token_stream& ts,istream& is)
{
    Token t = ts.get(is);
    
    if (!(st.is_declared(t.name)))
        error("det: undefined variable: ", t.name);
    
    string var_name = t.name;

    Token t2 = ts.get(is);
    if (t2.kind != '=')
        error("= missing in assignment of ", var_name);
    
    double d = expression(ts,is);
    st.set_value(var_name, d);
    return st.get_value(var_name);
}

//------------------------------------------------------------------------------

double statement(Token_stream& ts,istream& is)
{
    Token t = ts.get(is);
    switch (t.kind)
    {
        case name:
            ts.putback(t);
            return assignment(ts,is);

        case let: case cons:
            return declaration(t.kind, ts, is);
        
        default:
            ts.putback(t);
            return expression(ts,is);
    }
}

//------------------------------------------------------------------------------

void clean_up_mess(Token_stream& ts,istream& is)
{
    ts.ignore(print,is);
}

//------------------------------------------------------------------------------

void helpf(ostream& os)
{
    os << "\tWelcome to Calculator Help.\n\n\t"
         << "1. You can perform addition '+', subtraction '-', multiplication '*' and division '/'.\n\t"
         << "2. You can perform Factorial '!', power 'pow(a, b)', and square root 'sqrt(a)'.\n\t"
         << "3. You can define Variables by the notation: '# name = expression'.\n\t"
         << "4. You can define Constants by the notation: 'const name = expression'.\n\n\t"
         << "Thanks for using this calculator!.\n\n\t";
}

//------------------------------------------------------------------------------

void calculate(Token_stream& ts, istream& is, ostream& os)
{
    while(true)
    {
        try
        {
            //--------------------------------------------------------------
            
            cout << "\n\t" << prompt;              // print prompt.
            Token t = ts.get(is);
            
            if (t.kind == print)                   // The print token (';') is discarded.
                t = ts.get(is);

            //--------------------------------------------------------------
            // Changing the destination of the outputs to file x.
            
            if (t.kind == to)
            {   
                clean_up_mess(ts,is);               // Omits the filename after the "to" keyword.
                
                cout << "\n__________________\n"
                     << "The destination of the outputs has been changed."
                     << "\n------------------\n\t";
                
                //ofstream ost("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_calculator_to");
                ofstream ost("mydata_calculator_to");
                if (!ost) error("\n\n\tCan't open the output file.\n\n\t");
                ost.exceptions(ost.exceptions()|ios_base::badbit);      // Make ost throw if it goes bad.

                calculate(ts,is,ost);
                ost.close();

                continue;
            }

            //--------------------------------------------------------------
            // Changing the destination of the outputs to the console.
            
            if (t.kind == end_to)
            {
                cout << "\n__________________\n"
                     << "The destination of the outputs has been changed."
                     << "\n------------------\n\t";
                
                return;
            }  
            
            //--------------------------------------------------------------
            // Print help.

            if (t.kind == help)
            {
                helpf(os);
                continue;
            }

            //--------------------------------------------------------------
            // Changing to ints.
            
            if (t.kind == integer)
            {
                ts.integers = true;
                cout << "\tCalculator will function on ints\n\n\t";
                continue;
            }
            
            //--------------------------------------------------------------

            while (t.kind == print)
                t = ts.get(is);

            //--------------------------------------------------------------
            
            if (t.kind == quite)
                return;
            
            //--------------------------------------------------------------
            // Assigning to the file x the source of the instructions.
            
            if (t.kind == from)
            {
                clean_up_mess(ts,is);               // Omits the filename after the "from" keyword.

                os << "\n__________________\n"
                     << "File Instructions:"
                     << "\n------------------\n\t";
                
                //ifstream ist("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_calculator");
                ifstream ist("mydata_calculator");
                if (!ist) error("\n\n\tCan't output the input file.\n\n\t");
                ist.exceptions(ist.exceptions()|ios_base::badbit);      // Make ist throw if it goes bad.

                calculate(ts,ist,os);
                ist.close();

                os << "\n__________________\n"
                     << "Console Instructions:"
                     << "\n------------------\n\t";
                continue;
            }

            //--------------------------------------------------------------
            // Assigning to the console the source of the instructions.

            if (t.kind == end_file)
                return;
            
            //--------------------------------------------------------------
            // Calculator operations and variable management.
            
            ts.putback(t);
            os << "\n\t" << result << statement(ts,is) << '\n';

            //--------------------------------------------------------------
        }
        catch(exception& e)
        {
            //std::cerr << e.what() << '\n';
            os << e.what() << '\n';
            clean_up_mess(ts,is);
        }
    }
}

//------------------------------------------------------------------------------

int main()
{
    Token_stream ts;                                    // provides get() and putback()

    try
    {
        cout << "\n\n\tWelcome to our simple calculator (Type 'quit' to finish).";
        cout << "\n\n\tType 'help' to print the informaton help.";
        cout << "\n\tType 'integers' to operate on ints (only).\n\n\n\tEnter the expression:\t";
        
        calculate(ts,cin,cout);
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

/*
Simple calculator

Revision history
Project proposed by Bjarne Stroustrup
Implemented by Camilo Alejandro Castillo Benavides, winter 2022.

This program implements a basic expression calculator.
input from cin; output to cout.
The grammar for input is:

Calculate:
    Prompt
    Help
    Integer Mode
    Print
    Quit
    Statement

Prompt
    >

Help
    helpf()

Print:
    \n

Quit
    'quit'

Statement:
    Assignment
    Declaration
    Expression

Expression:
    Term
    Expression '+' Term
    Expression '-' term
Term:
    Fact
    Term '*' fact
    Term '/' fact
    Term '%' fact
Fact:
    Primary
    Primary'!'
Primary:
    Number;
    (Expression)
    - Primary
    + Primary
Number:
    floating-point-literal

input comes from cin through the Token_stream called ts.

clean_up_mess() and Token_stream::ignore are used to recover from errors.
By means of these the characters are omitted until a 'print' is found.


Example when a set of file instrucctions are used.
4 + 7
2 + 3
2 * pi
# var2 = 100
var = 10
1 + pi * var2 + 3 - var + pow(2,4) + sqrt(9) - 4!
1 + var
quit
|

// Instructions such as "var + 1" or "pi * 3" are not available. You need "0 + var + 1".T
he help command is not available. Remember to previously declare in the terminal "const pi = 3.1416"
and "# var = 100".

*/
