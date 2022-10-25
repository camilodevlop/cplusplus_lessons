/*This drill involves getting the sequence of versions of Date to work. For each version
define a Date called today initialized to june 25, 1978. Define Date called tomorrow and give
today and increasing its day by one.*/

#include <iostream>
#include <vector>
#include <string>

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Date
{
    int y, m, d;                  // Year, month, day of month.
    
    Date(int y, int m, int d)
        : y(y),m(m),d(d)
    {
        if (y < 1900 || m < 1 || m > 12 || d < 1 || d > 31)
        cout << "\n\n\tThe date is not valid.\n\t";
    }
    
    void add_day(int n)
    {
        ++d;
    }
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream&, const Date&);

//------------------------------------------------------------------------------

int main()
{
    Date today(1978,6,25);
    
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "\n\n\t" << today;
    cout << "\n\n\t" << tomorrow;
    
    return 0;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

//------------------------------------------------------------------------------