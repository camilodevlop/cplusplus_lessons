/*The following program takes in a temperature in Celsius and converts it to Kelvin. Prevent if the temperature
is below to -273.15 C.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;
double ctok(double);

int main (){
    
    double c = -274.0;
    while (c < -273.15){
        cout << "\n\t(consider absolute zero to be -273.15 C)\n\n\tEnter temperature in Celsius:   ";
        cin >> c;
    }
    
    double k = ctok(c);
    cout << "\tThe temperature in Kelvin is:   " << k << '\n';

    return 0;
}

// Celsius to Kelvin function.
double ctok(double c){
    double k = c + 273.15;
    return k;
}