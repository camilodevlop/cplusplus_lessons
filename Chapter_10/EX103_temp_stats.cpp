/*Program that reads a file in the form of the temperature Reading type (Secc. 10.5).
Then calculates the mean and median temperatures in the data set.*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Reading
{
    int hour;
    double temperature;
    char tscale;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Reading& r)
{
    int h;
    double t;
    char ts, ch1, ch2, ch3;

    is >> ch1 >> h >> ch2 >> t >> ts >> ch3;

    if (!is) return is;

    if (ch1 != '(' || ch2 != ',' || ch3 != ')')
    {
        is.clear(ios_base::failbit);
        return is;
    }
    
    r.hour = h;
    r.temperature = t;
    r.tscale = ts;
    
    return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << '(' << r.hour << ',' << r.temperature << r.tscale << ')';
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) 
            error(message);
    }
}

//------------------------------------------------------------------------------
// Celsius to Fahrenheit.

double celsius2fahrenheit(const double& c)
{
    return (9 / 5) * c + 32;
}

//------------------------------------------------------------------------------

int main()
{
    ifstream ist("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/102_raw_temps");
    if(!ist) error("\n\n\tCan't open input file");

    ist.exceptions(ist.exceptions()|ios_base::badbit); // Make ist throw if it goes bad.

    try
    {
        vector<Reading> readings;
        vector<double> temps;
        double mean = 0;
        double median;
        
        Reading r;

        
        // Reading from file.

        for(Reading r; ist >> r;)
        {
            readings.push_back(r);
            cout << "\n\t" << r;
            
            if (r.tscale == 'C')
            {
                r.temperature = celsius2fahrenheit(r.temperature);
                cout << "\t-> " << r.temperature << " F";
            }
            
            temps.push_back(r.temperature);
            mean += r.temperature;
        }
        end_of_loop(ist,'|',"\n\n\tBad termination of file.\n\t");
        
        
        // Calculating the mean and the median.
        
        int st = temps.size();
        
        mean /= st;
        
        sort(temps.begin(),temps.end());
        if (st % 2 == 0)
            median = (temps[st/2] + temps[st/2 - 1]) / 2;
        else
            median = temps[st / 2];
        
        cout << "\n\n\tMean = " << mean << '\t' << "Median = " << median << "\n\t";

        return 0;
    }
    catch(const exception& e)
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
