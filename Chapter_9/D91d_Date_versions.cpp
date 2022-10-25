/*This drill involves getting the sequence of versions of Date to work. For each version
define a Date called today initialized to june 25, 1978. Define Date called tomorrow and give
today and increasing its day by one.*/

#include <iostream>
#include <vector>
#include <string>

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, ovt, nov, dec
};

//------------------------------------------------------------------------------

struct Date
{
    public:
        Date(int y, Month m, int d);
        void add_day(int n);
        Month month(){return m;}
        int day(){return d;}
        int year(){return y;}

    private:
        int y, d;                          // Year and day of month.
        Month m;                           // Month; 
};

//------------------------------------------------------------------------------
// Check for a valid day and initialize.

Date::Date(int y, Month mm, int d)
        : y(y),m(mm),d(d)
    {
        int im = int(m);
        if (y < 1900 || im < 1 || im > 12 || d < 1 || d > 31)
            cout << "\n\n\tThe date is not valid.\n\t";
    }

//------------------------------------------------------------------------------
// Increase the day by n days.

void Date::add_day(int n)
{
    if ((d + n) > 31)
    {
        cout << "\n\n\tThe days add up to more than 31.";
        return;
    }

    d += n;
    return;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream&, Date&);

//------------------------------------------------------------------------------

int main()
{
    Date birthday(1970,Month::jun,30);
    
    cout << "\n\n\tEl mes es: " << int(birthday.month());
    cout << "\n\n\t" << birthday;
    
    birthday.add_day(1);
    cout << "\n\n\t" << birthday;
    
    return 0;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Date& d)
{
    return os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << ')';
}

//------------------------------------------------------------------------------