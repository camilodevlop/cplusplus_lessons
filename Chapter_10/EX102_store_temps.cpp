/*Program that creates a file in the form of the temperature Reading type (Secc. 10.5).
Fill with at least 50 pairs.*/

#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
// Class that generates random ints and doubles.

class Random_values
{
    public:

        // Modifying operations.
        int int_creator(const int&, const int&);
        double dble_creator(const double&, const double&);
};

//------------------------------------------------------------------------------
// Returns a pseudorandom integer. ll: lower limit, ul: upper limit.

int Random_values::int_creator(const int& ll, const int& ul)
{
    using u32 = uint_least32_t;
    using engine = std::mt19937;
    
    random_device os_seed;
    const u32 seed = os_seed();
    engine generator(seed);

    uniform_int_distribution<u32> distribute(ll,ul);
    
    return distribute(generator);
}

//------------------------------------------------------------------------------
// Returns a pseudorandom double. ll: lower limit, ul: upper limit.

double Random_values::dble_creator(const double& ll, const double& ul)
{
    
    using u32 = uint_least32_t;
    using engine = std::mt19937;
    
    random_device os_seed;
    const u32 seed = os_seed();
    engine generator(seed);
    
    uniform_real_distribution<double> distribution(ll,ul);

    return distribution(generator);
}

//------------------------------------------------------------------------------

struct Reading
{
    Reading (int hh, double tt, char ts)
        :hour(hh),temperature(tt),tscale(ts){}
    
    int hour;
    double temperature;
    char tscale;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << '(' << r.hour << ',' << r.temperature << ' ' << r.tscale << ')';
}

//------------------------------------------------------------------------------

int main ()
{
    try
    {
        Random_values rv;
        
        ofstream ost("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/102_raw_temps");
        if (!ost) error("\n\n\tCan't open output file.\n\t");

        
        // The scale (C or F) is chosen by taking advantage of the int_creator() function.
        // -90C and 50C are the lowest and highest temperatures recorded on earth respectively.

        for (int i = 0; i < 50; i++)
            if (rv.int_creator(0,100) % 2 == 0)
                ost << Reading(rv.int_creator(0,23), rv.dble_creator(-90,50), 'C');
            else
                ost << Reading(rv.int_creator(0,23), rv.dble_creator(-130,122), 'F');
        

        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
        return 2;
    }
}

//------------------------------------------------------------------------------