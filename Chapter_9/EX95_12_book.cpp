/*This exercise and the next few require you to design and implement a Book class,
such as you can imagine as part of a library. Class Book should have members for
the ISBN, title, author, and copy right date.*/

//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
// Date manager.

namespace Chrono
{
    bool is_date(int, int, int);
    
    class Date
    {
        public:
            class Invalid{};                // To throw as exception.
            Date(int d, int m, int y);      // Check for valid date and initialize.
            
            int day() const
                {return d;}
            int month() const
                {return m;}
            int year() const
                {return y;}

        private:
            int d, m, y;
    };

    Date::Date(int dd, int mm, int yy)
        :d(dd), m(mm), y(yy)
    {
        if(!(is_date(dd, mm, yy)))
            throw Invalid();
    }

    bool is_date(int d, int m, int y)
    {
        if (d <= 0) return false;
        if (m < 1 || m > 12) return false;

        int days_in_month = 31;             // Most months have 31 days.
        
        switch(m)
        {
            case 2:
                days_in_month = 29;
                break;
            case 4: case 6: case 9: case 11:
                days_in_month = 30;
                break;
        }
        
        if (days_in_month < d)
            return false;

        return true;
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.day() << ',' << d.month() << ',' << d.year() << ')';
    }
}

using Chrono::Date;
using Chrono::is_date;
//using Chrono::operator<<;

//------------------------------------------------------------------------------
// Enumerate type created for the Book class.

enum class Genre
{
    fiction = 1, nonfiction, periodical, biography, children
};
//------------------------------------------------------------------------------

class Book
{
    public:
        Book(string, string, string, bool, Genre);
        
        class Invalid{};            // To throw as exception. 
        string title() const
            {return t;}
        string author() const
            {return a;}
        string isbn() const
            {return ISBN;}
        bool checked() const
            {return ch;}
        Genre genre() const
            {return g;}
        
        void check_out()
            {
                ch ? cout << "\n\n\tCheck out\n\t" : ch = true;
                return;
            }

        void check_in()
            {ch = false; return;}

    private:
        string t;                   // Title.
        string a;                   // Author.
        string ISBN;                // ISBN book.
        bool ch;                    // Is checked out.
        Genre g;                    // Book's genre.
};

//------------------------------------------------------------------------------

bool is_ISBN(string);

Book::Book(string ti, string au, string is, bool che, Genre gn)
    :t(ti), a(au), ISBN(is), ch(che), g(gn)
{
    if (!(is_ISBN(is))) throw Invalid();
}

//------------------------------------------------------------------------------

bool is_ISBN(string is)
{
    // The format of ISBN is n-n-n-x It is checked the '-' characters.
    if (is[1] != '-' || is[3] != '-' || is[5] != '-')
        return false;
    
    // Checking the numbers n, n, n.
    int n1 = is[0]; int n2 = is[2]; int n3 = is[4];
    if ((n1 < 48 || n1 > 57) || (n2 < 48 || n2 > 57) || (n3 < 48 || n3 > 57))
        return false;

    // Checking if x is a number or an alphabet character.
    if (!(isalnum(is[6])))
        return false;
    
    return true;
}

//------------------------------------------------------------------------------

bool operator==(const Book& b1, const Book& b2)
{
    if (b1.isbn() == b2.isbn())
        return true;
    
    return false;
}

//------------------------------------------------------------------------------
bool operator!=(const Book& b1, const Book& b2)
{
    return !(b1 == b2);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Book& b)
{
    vector <string> genres;
    genres.push_back("fiction");
    genres.push_back("nonfiction");
    genres.push_back("periodical");
    genres.push_back("biography");
    genres.push_back("children");

    return os << "\n\tTitle: " << b.title()
              << "\n\tAuthor: " << b.author()
              << "\n\tISBN: " << b.isbn()
              << "\n\tGenre: " << genres[int(b.genre()) - 1];
}

//------------------------------------------------------------------------------
// Class to manage user accounts.

class Patron
{
    public:
        
        // Constructors
        Patron(string uname, int lcnumber)
            : un(uname), lcn(lcnumber), uf(0.0) {}

        Patron(string uname, int lcnumber, double ufees)
            : un(uname), lcn(lcnumber), uf(ufees) {}
        
        
        // Member functions.
        void set_fees(double);
        
        string usr_name () const
            {return un;}
        int lib_card_num() const
            {return lcn;}
        double usr_fees() const
            {return uf;}

    private:
        string un;                  // Contains the user name.
        int lcn;                    // Contains the library card number.
        double uf;                  // Contains the fees of the user.
};

//------------------------------------------------------------------------------

void Patron::set_fees(double new_fees)
{   
    if (new_fees >= 0)
        uf = new_fees;
    else
        cout << "\n\n\tThe fee entered is invalid.\n\t";
    
    return;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Patron& pt)
{
    return os << "\n\tName: " << pt.usr_name()
              << "\n\tLib card number: " << pt.lib_card_num()
              << "\n\tUser fees: " << pt.usr_fees();
}

//------------------------------------------------------------------------------

struct Transaction
{
    Book bk = Book("title", "author", "0-0-0-A", false, Genre(1));
    Patron ptn = Patron("name",1, 0.0);
    Date dte = Date(1,1,2000);
};

//------------------------------------------------------------------------------

class Library
{
    public:
        class No_user{};            // To throw as exceptions.
        class No_book{};
        class Outstanding_fees{};

        //------------
        
        void add_books(const Book& book)
            {books.push_back(book); return;}
        
        void add_patrons(const Patron& patron)
            {patrons.push_back(patron); return;}
        
        void check_out_books(const Patron&, const Book&, const Date&);
        
        vector<string> name_fees();

        void print_transaction(int i)
            {
                cout << "\n\t------------------------";
                cout << "\n\t" << transactions[i].ptn << "\n\t" << transactions[i].bk << "\n\n\t" << transactions[i].dte;
                return;
            }

        //------------

        Book& check_book(int i)
            {return books[i];}
        Patron& check_patron(int i)
            {return patrons[i];}

    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
};

//------------------------------------------------------------------------------

void Library::check_out_books(const Patron& patron, const Book& book, const Date& date)
{
    // Checking the user.
    int i(0);
    bool is_usr(false);
    while (i < patrons.size())
    {
        if (patron.lib_card_num() == patrons[i].lib_card_num())
        {
            is_usr = true;
            break;
        }
        ++i;
    }
    
    if (!(is_usr)) throw No_user();
    
    // Checking the book and its availability.
    if (book.checked()) throw No_book();

    // // Whether or not the user owes a fee.
    if (patron.usr_fees() > 0) throw Outstanding_fees();
    
    // Creating a transaction.
    Transaction current_transaction;
    current_transaction.dte = date;
    current_transaction.bk = book;
    current_transaction.ptn = patron;

    // Placing the transaction in the Transaction vector.
    transactions.push_back(current_transaction);
}

//------------------------------------------------------------------------------

vector<string> Library::name_fees()
{
    vector<string> nf;
    
    for (int i = 0; i < patrons.size(); i++)
        if (patrons[i].usr_fees() > 0)
            nf.push_back(patrons[i].usr_name());

    return nf;
}

//------------------------------------------------------------------------------

int main ()
{
    try
    {
        Library lb;
        
        // Book list.
                                                        
        Book b1("Lord of the Rings", "J.R.R. Tolkien", "1-1-1-A", false, Genre(1)); 
        lb.add_books(b1);                                        // It can be used Genre gn = Genre::fiction.

        Book b2("Harry Potter", "J.K. Rowling", "1-1-2-A", false, Genre(1)); 
        lb.add_books(b2);

        Book b3("Steve Jobs", "Walter Isaacson", "1-1-3-A", false, Genre(4)); 
        lb.add_books(b3);

        Book b4("Love in the Time of Cholera", "G. Garcia Marquez", "1-1-4-A", false, Genre(2)); 
        lb.add_books(b4);

        Book b5("How to win friends and influency people", "D. Carnegie", "1-1-5-A", false, Genre(2)); 
        lb.add_books(b5);

        // Patron list.
        
        Patron p1("Camilo", 1, 1);
        lb.add_patrons(p1);

        Patron p2("Cordula", 2, 0);
        lb.add_patrons(p2);

        Patron p3("Victor", 3, 0);
        lb.add_patrons(p3);

        Patron p4("Lina", 4, 0);
        lb.add_patrons(p4);

        Patron p5("Martina", 5, 1);
        lb.add_patrons(p5);

        // -----------
        
        Date d(12, 12, 2020);

        // -----------
        vector <string> names_fees;
        names_fees = lb.name_fees();

        cout << "\n\n\t" << names_fees[0] << "\t" << names_fees[1] << "\n\t";
        
        /*lb.check_out_books(p1,b1,d);
        lb.check_out_books(p2,b2,d);
        lb.check_out_books(p3,b3,d);
        lb.check_out_books(p4,b4,d);
        
        lb.print_transaction(0);
        lb.print_transaction(1);
        lb.print_transaction(2);
        lb.print_transaction(3);*/
        
        // p.set_fees(7);

        return 0;
    }
    catch(Chrono::Date::Invalid)
    {
        cerr << "\n\n\tDate format error.\n\t";
        return 1;
    }
    catch(Book::Invalid)
    {
        cerr << "\n\n\tISBN format error.\n\t";
        return 2;
    }
    catch(Library::No_user)
    {
        cerr << "\n\n\tThe user's library card num was not found.\n\t";
        return 3;
    }
    catch(Library::No_book)
    {
        cerr << "\n\n\tThe book was not found.\n\t";
        return 4;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 5;
    }
    catch(...)
    {
        cerr << "error";
        return 6;
    }
}