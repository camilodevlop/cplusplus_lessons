/*In this program the capabilities of the C++ language to deal with Vectors are explored.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> v{7.0};

vector<string> month_input_tbl{
    "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

//------------------------------------------------------------------------------

struct Day
{
    vector<double> hour{vector<double>(24,7)};
};

//------------------------------------------------------------------------------

struct Month
{
    int month {-1};                // [0:11] January is 0.
    vector<Day> day{10};        // [1:31] one vector of readings per day.
};

//------------------------------------------------------------------------------

struct Year
{
    int year;
    vector<Month> month{12};
};

//------------------------------------------------------------------------------

int main ()
{
    Day prueba;
    Month mt;
    Year yt;
    
    for (int k = 0; k < yt.month.size(); k++)
    {
        for (int j = 0; j < yt.month[k].day.size(); j++)
        {
            for (int i = 0; i < yt.month[k].day[j].hour.size(); i++)
            {
                cout << yt.month[k].day[j].hour[i];
            }    
    
            cout << "\n";
        }

        cout << "\n\n\n";
    }
    
    return 0;
}