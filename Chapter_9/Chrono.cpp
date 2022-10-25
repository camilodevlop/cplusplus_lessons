/*Class Date implementation. In this case the "Chrono" namespace is reserved.*/

#include <iostream>
#include <vector>
#include <string>

#include "Chrono.h"
#include "std_lib_facilities.h"

namespace Chrono
{
    // Member funtion definitions.
    Date::Date(int yy, Month mm, int dd)
        :y(yy),m(mm),d(dd)
    {
        if(!is_date(yy,mm,dd)) throw Invalid();
    }
    
    const Date& default_date()
    {
        static Date dd(1970,Month::jan,1); // Starts of 21st century.
        return dd;
    }

    Date::Date()
        :y(default_date().year()),
        m(default_date().month()),
        d(default_date().day()) {}
    
    void Date::add_day(int n)
    {
        int d_month = days_month();

        while (n > 0)
        {
            if (d < d_month)
            {
                ++d;                    // Increasing days.
                --n;
            }
            else
            {
                add_month(1);
                d_month = days_month();
                d = 1;
                --n;
            }
        }
        return;
    }

    void Date::add_month(int n)
    {
        int mth = int(m);
        
        while (n > 0)
        {
            if (mth < 12)
            {
                ++mth;
                m = Month(mth);
                --n;
            }
            else
            {
                add_year(1);
                mth = 1;
                m = Month(mth);
                --n;
            }
            
        }
        
        return;
    }

    void Date::add_year(int n)
    {
        if (m == Month::feb && d == 29 && !leapyear(y + n))
        {
            m = Month::mar;
            d = 1;
        }
        y += n;
    }

    int Date::days_month() const
    {
        int dm = 31;                    // Most months have 31 days.
        switch (int(m))
        {
        case 2:
            dm = leapyear(y) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            dm = 30;
            break;
        default:
            break;
        }

        return dm;
    }
    
    // Helper functions.

    bool is_date(int y, Month m, int d)
    {
        // Assume that y is valid.

        if (d <= 0) return false;
        if (m < Month::jan || m > Month::dec) return false;
        
        int days_in_month = 31;            // Most months have 31 days.

        switch (m)
        {
        case int(Month::feb):
            days_in_month = (leapyear(y)) ? 29 : 28;
            break;
        
        case int(Month::apr): case int(Month::jun): case int(Month::sep): case int(Month::nov):
            days_in_month = 30;
            break;
        
        default:
            break;
        }
        
        if (days_in_month < d) return false;

        return true;
    }

    bool leapyear(int y)
    {
        if ((y % 4) == 0 && ((y % 100) > 0 || (y % 400) == 0))
            return true;

        return false;
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
        return os << '(' << d.year() << ','
                    << int(d.month()) << ','
                    << d.day() << ')';
    }

    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        
        if (!is)
            return is;
        
        if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')        // Oops: format error.
        {
            is.clear(ios_base::failbit);                                // Set the failbit.
            return is;
        }
        
        dd = Date(y, Month(m), d);
        return is;
    }
    
    Day day_of_week(const Date& d)
    {
        Date d_zero;
        long int sum_days = 0;

        // Adding the days of the years.
        int aux = d_zero.year();
        while (aux < d.year())
        {
            leapyear(aux) ? sum_days += 366 : sum_days += 365;
            ++aux;
        }
        
        // Adding the days of the months.
        aux = 1;
        while (aux < int(d.month()))
        {
            switch (aux)
            {
            case 2:
                leapyear(d.year()) ? sum_days += 29 : sum_days += 28;
                break;
            
            case 4: case 6: case 9: case 11:
                sum_days += 30;
                break;

            default:
                sum_days += 31;
                break;
            }
            ++aux;
        }
        
        // Adding the remaining days.
        sum_days += d.day();

        // The zero Date is (1970,1,1). It was thursday (5 in the enum class).
        int day_week = (sum_days % 7) + 4;      // add 4 days and not 5 because Thursday counts 1.
        
        if (day_week > 7)                       // if a week is completed.
            day_week -= 7;
        
        return Day(day_week);
    }

    Day next_workday(const Date& d)
    {
        Day day_week(day_of_week(d));

        switch (int(day_week))
        {
        case 1: case 6: case 7:
            return Day::monday;
        
        default:
            return Day(int(day_week) + 1);
        }
    }
    
    int week_of_year(const Date& d)
    {
        int count = 0;
        int week_count = 0;
        int aux = 1;

        // Adding the days of the months.
        while (aux < int(d.month()))
        {
            switch (aux)
            {
            case 2:
                leapyear(d.year()) ? count += 29 : count += 28;
                break;
            
            case 4: case 6: case 9: case 11:
                count += 30;
                break;

            default:
                count += 31;
                break;
            }
            ++aux;
        }
        
        // Adding the remaining days.
        count += d.day();

        // Calculating the number of the week.
        week_count = count / 7;
        if ((count % 7) > 0)
            ++week_count;
        
        return week_count;
    }
        
    Date next_Sunday(const Date& d)
    {
      //...
    }

    Date next_weekday(const Date& d)
    {
        //...
    }
}

//---------------------------------------------------------

using Chrono::Date;
using Chrono::Month;
using Chrono::Day;
using Chrono::day_of_week;
using Chrono::next_workday;
using Chrono::week_of_year;
//using Chrono::days_month;

int main()
{
    // Return days according to enum class Day{};.
    
    Date dte(1972,Month::feb,25);
    Day day_week(day_of_week(dte));

    Day nd(next_workday(dte));
    //cout << "\n\n\t" << int(nd) << "\n\n\t";

    dte.add_day(365);
    cout << "\n\n\t" << dte << "\n\t";
	
    cin >> dte;
    cout << "\n\n\t" << dte << "\n\t";

    return 0;
}