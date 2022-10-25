/*Assume that you have a file of temperature readings that has been strctured like this:
{year 2000
            {month feb(1 1 68)(2 3 66.66)(1 0 67.2)}
            {month dec(15 15 -9.2)(15 14 -8.8)(14 0 -2)}
}*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------
// Symbolic constants.

const int not_a_reading = -7777;            // Less than absolute zero.
const int not_a_month = -1;
const int days_of_month = 32;               // "Waste" day 0 to keep the code simple.
const int months_of_year = 12;
const int implausible_min = -200;
const int implausible_max = 200;

vector<string> month_input_tbl{
    "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

//------------------------------------------------------------------------------

struct Reading
{
    int day;
    int hour;
    double temperature;
};


// Read a temperature reading from is to r. Format: (day hour temperatures).

istream& operator>>(istream& is, Reading& r)
{
    char ch1;
    if(is >> ch1 && ch1 != '(')
    {
        is.unget();
        is.clear();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d, h;
    double t;
    
    is >> d >> h >> t >> ch2;

    if (!is || ch2 != ')') error("\n\n\tBad reading.\n\t");
    
    r.day = d;
    r.hour = h;
    r.temperature = t;

    return is;
}

//------------------------------------------------------------------------------
// Is the name of a month?

int month_to_int(string s)
{
    for(int i = 0; i < 12; ++i) 
        if(month_input_tbl[i] == s) return i;
    
    return -1;
}

//------------------------------------------------------------------------------
// is valid the r? (r is an object of type Reading.)

bool is_valid(const Reading& r)
{
    if (r.day < 1 || r.day > 31) return false;
    if (r.hour < 0 || r.hour > 31) return false;
    if (r.temperature < implausible_min || r.temperature > implausible_max) return false;

    return true;
}

//------------------------------------------------------------------------------
// End of the input loop.

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return;
            error(message);
    }
}

//------------------------------------------------------------------------------

struct Day
{
    vector<double> hour{vector<double>(24,not_a_reading)};
};

//------------------------------------------------------------------------------
// A month of temperature readings.

struct Month
{
    int month {not_a_month};                // [0:11] January is 0.
    vector<Day> day{days_of_month};         // [1:31] one vector of readings per day.
};

//------------------------------------------------------------------------------
// A year of temperature readings, organized by month.

struct Year
{
    int year;                               // Positive == A.D.
    vector<Month> month{months_of_year};    // [0:11] January is 0.
};

//------------------------------------------------------------------------------

ostream& print_year(ostream& ofs, Year& y)
{      
    ofs << "\n\n\tYear: " << y.year << '\t' << y.month.size();
    
    for (int k = 0; k < y.month.size(); k++)
        if (y.month[k].month != not_a_month)
        {
            ofs << "\n\n\tMonth: " << y.month[k].month << "\n\t";
        
            for (int j = 0; j < y.month[k].day.size(); j++)
                for (int i = 0; i < y.month[k].day[j].hour.size(); i++)
                    if ( y.month[k].day[j].hour[i] != not_a_reading )
                    {
                        ofs << "Day: " << j << "\n\t";
                        ofs << "Hour: " << i << "  Temperature: " << y.month[k].day[j].hour[i] << "\n\t";
                    }
        }
    return ofs;
}

//------------------------------------------------------------------------------

// Read a month from is into m. Format: {month feb...}.

istream& operator>>(istream& is, Month& m)
{
    char ch = 0;
    if (is >> ch && ch != '{')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    
    string month_marker;
    string mm;

    is >> month_marker >> mm;

    if (!is || month_marker != "month") error("\n\n\tBad start of month\n\t");


    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;

    for (Reading r; is >> r;)
    {
        if (is_valid(r))
        {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++duplicates;
            m.day[r.day].hour[r.hour] = r.temperature; 
        }
        else
            ++invalids;
    }
    
    if (invalids) error("\n\n\tInvalid readings in month.\n\t");
    if (duplicates) error("\n\n\tDuplicate readings in month.\n\t");
    end_of_loop(is,'}',"\n\n\tBad end of month.\n\t");

    return is;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Year& y)
{
    char ch;
    is >> ch;
    if (ch != '{')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year") error("\n\n\tBad start of year\n\t");
    y.year = yy;
    
    while (true)
    {
        Month m;
        if(!(is >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(is, '}', "\n\n\tBad end of year.\n\t");
    
    return is;
}

//------------------------------------------------------------------------------

int main()
{
    ifstream ifs("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_input_105");
    if (!ifs) error("\n\n\tCan't open input file\n\t");

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
        
    ofstream ofs("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata_output_105");
    if (!ofs) error("\n\n\tCan't open input file\n\t");
    
    try
    {
        vector<Year> ys;
        while (true)
        {
            Year y;
            if (!(ifs >> y)) break;
            
            ys.push_back(y);
        }
        
        cout << "\n\n\tRead: " << ys.size() << " years of reading\n";
        
        for (Year y : ys)  print_year(ofs,y);

        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\n";
        return 2;
    }
    
}

//------------------------------------------------------------------------------