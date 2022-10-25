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
    int y;                  // Year.
    int m;                  // month.
    int d;                  // Day of month.
};

void init_day(Date&, int, int, int);
void add_day(Date& dd, int n);
ostream& operator<<(ostream&, const Date&);

//------------------------------------------------------------------------------

int main()
{
    try
    {
        Date today;
        init_day(today, 1978, 6, 25);

        Date tomorrow;
        tomorrow = today;
        add_day(tomorrow, 1);

        cout << "\n\n\t" << today;
        cout << "\n\n\t" << tomorrow;
        
        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
}

//------------------------------------------------------------------------------

void init_day(Date& dd, int y, int m, int d)
{
    // Date validity.
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > 31)
        error("\n\n\tThe date is not valid.\n\t");
    
    dd.y = y; dd.m = m; dd.d = d;
    
    return;
}

//------------------------------------------------------------------------------

void add_day(Date& dd, int n)
{
    init_day(dd, dd.y, dd.m, dd.d + n);
    return;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

//------------------------------------------------------------------------------