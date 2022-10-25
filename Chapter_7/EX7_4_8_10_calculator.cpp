/*In this set of exercises all the improvements to the calculator developed in chapter 6 are implemented.
The exercises are 4, 5, 6 , 7 and 8 of the chapter 7.
4. Define a class called Symbol_table with a member var_table of type vector<Variable> and member functions 
get(), set(), is_declared(), and declare(). Functions are defined from previous get_value(), set_value(),
is_declared(), and define_name().
5. Modify Token_stream::get() to return Token(print) when it sees a neewline. You might find the standard library function isspace(ch).
6. Help: have the calculator print some instructions for how to use it.
7. Change the q and h commands to be quit and help, respectively.
8. Fix grammar description in comments.
10. Modify the calculator to operate on ints (only). */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctype.h>
#include "std_lib_facilities.h"

using namespace std;

Destinatario: Martha Lucia Gallego
Celular: 310 828 4807

Ciudad Destino: Manizales
Conjunto Ciprés de Bella Suiza
apartamento 502B Torre B


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
const char integer = 'i';                          // Used to define the Token of Integers.
const string intes = "integers";                     // Keyword to request the use of integers only

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
    do                                             // note that >> skips whitespace (space, newline, tab, etc.) 
    {
        ch = cin.get();
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
            return Token(ch);                      // let each character represent itself.
        
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);                       // put digit back into the input stream
            double val;
            cin >> val;                            // read a floating-point number
            
            if (ts.integers == true)               // Conversion to integers.
                val = narrow_cast<int> (val);
            
            return Token(number, val);             // let the const number (equal to '8') represent "a number"
        }
        default:
            if (isprint(ch))                       // Is a printable character?
            {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;

                cin.putback(ch);
                
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
        char type;                                  // 'C' for const and 'L' for variable.
        //Variable(string n, double v) :name(n), value(v), type('L') { }
        Variable(string n, double v, char t) :name(n), value(v), type(t) { }
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

Symbol_table st;                                    // Provides...

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
    for (int i = 0; i < var_table.size(); i++)
        if (var_table[i].name == s)
            if (var_table[i].type == let)
            {
                var_table[i].value = d;
                return;
            }
            else
                error("The referenced variable was declared as a constant: ", var_table[i].name);

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

double expression();                                // declaration so that primary() can call expression()

//------------------------------------------------------------------------------
// deal with numbers, commas, and parentheses

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

double declaration(char ty)                     // ty is 'C' (constant) or 'L' (variable).
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");
    string var_name = t.name;

    if (st.is_declared(var_name))
        error("The variable is already declared: ", var_name);
    
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ", var_name);
    
    double d = expression();

    if (ty == let)
        st.var_table.push_back(Variable(var_name, d, let));
    else
        st.var_table.push_back(Variable(var_name, d, cons));

    return d;
}

//------------------------------------------------------------------------------
/* Variable assignment: the chosen notation has the form "var_name = expresion;"
*/

double assignment()
{
    Token t = ts.get();
    
    if (st.is_declared(t.name) == false)
        error("det: undefined variable: ", t.name);
    
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in assignment of ", var_name);
    
    double d = expression();
    st.set_value(var_name, d);
    return st.get_value(var_name);
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
        case name:
            ts.putback(t);
            return assignment();
        
        case let: case cons:
            return declaration(t.kind);
        
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
void helpf()
{
    cout << "\tWelcome to Calculator Help.\n\n\t";
    cout << "1. You can perform addition '+', subtraction '-', multiplication '*' and division '/'.\n\t";
    cout << "2. You can perform Factorial '!', power 'pow(a, b)', and square root 'sqrt(a)'.\n\t";
    cout << "3. You can define Variables by the notation: '# name = expression'.\n\t";
    cout << "4. You can define Constants by the notation: 'const name = expression'.\n\n\t";
    cout << "Thanks for using this calculator!.\n\n\t";
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
            
            if (t.kind == help)          // print help.
            {
                helpf();
                continue;
            }
            
            if (t.kind == integer)
            {
                ts.integers = true;
                cout << "\tCalculator will function on ints\n\n\t";
                continue;
            }
            
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
        //var_table.push_back(Variable("k", 1000));

        cout << "\n\n\tWelcome to our simple calculator (Type 'quit' to finish).";
        cout << "\n\n\tType 'help' to print the informaton help.";
        cout << "\n\tType 'integers' to operate on ints (only).\n\n\n\tEnter the expression:\t";
        
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
*/