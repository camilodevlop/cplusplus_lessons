/*Class Date implementation. Header file Chrono.*/

#include <iostream>
using namespace std;

namespace Chrono
{
    enum class Month
    {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    enum class Day
    {
        sunday = 1, monday, tuesday, wednesday, thusrday, friday, saturday
    };

    class Date
    {
        public:
            class Invalid{};                    // To throw as exception.
            Date(int y, Month m, int d);        // Check for valid date and initialize.
            Date();                             // Default constructor.

           // Nonmodifying operations.
            int day() const {return d;}
            Month month() const {return m;}
            int year() const {return y;}
            int days_month() const;             // Days in the month. 

            // Modifying operations.
            void add_day(int n);
            void add_month(int n);
            void add_year(int n);
        
        private:
            int y;
            Month m;
            int d;
    };

    bool is_date(int y, Month m, int d);        // True for valid date.
    bool leapyear(int y);                       // True if y is a leap year.

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);

    Day day_of_week(const Date& d);             // Day of week of d.
    Day next_workday(const Date&);              // Next work day of the week.
    Date next_Sunday(const Date&);              // Next Sunday after d.
    Date next_weekday(const Date& d);           // Next weekday after d.    
}