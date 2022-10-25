/*Try this to finding the lowest, highest, and average temperature values in a set of data. The program has
logic errors for educational purposes.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

int main() {

    vector<double> temps;
    double sum = 0;
    double high_temp = -273.15;     // Absolute zero.
    double low_temp = 131;          // Temperature recorded in Death Valley (California).
    int no_of_temps = 0;

    for(double temp; cin >> temp;){
        ++no_of_temps;
        sum += temp;

        if (temp > high_temp)
            high_temp = temp;
        if (temp < low_temp)
            low_temp = temp;
    }
    
    cout << "High temperature: " << high_temp << "\n";
    cout << "Low temperature: " << low_temp << "\n";
    
    if (no_of_temps != 0)
        cout << "Average temperature: " << sum / no_of_temps << "\n";

    return 0;
}