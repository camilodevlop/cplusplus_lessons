/*Program thar converts from Celsius to Fahrenheit and from Fahrenheit to Celsius.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

double ctof(double);
double ftoc(double);

int main (){

    char option = ' ';
    do{
        cout << "\nChoose the temperature scale. Type 'c' for Celsius or 'f' for Fahrenheit:  ";
        cin >> option;
    } while (option != 'c' && option != 'f');
        
    if (option == 'c'){
        double c;
        do{
            cout << "\n\t(consider absolute zero to be -273.15 C)\n\tEnter temperature in Celsius:   ";
            cin >> c;
        } while (c < -273.15);
        
        double f = ctof(c);
        cout << "\tThe temperature in Fahrenheit is:  " << f << '\n';
    }
    else{
        double f;
        do{
          cout <<  "\n\t(consider ansolute zero to be -460 F)\n\tEnter temperature in Fahrenheit:   ";
          cin >> f;
        } while (f < -460);

        double c = ftoc(f);
        cout << "\tThe temperature in Celsius is:  " << c << '\n';
    }
    
    return 0;
}

// Celsius to Fahrenheit function.
double ctof(double c){
    double f = (9 * c / 5) + 32;
    return f;
}
// Fahrenheit to Celsius function.
double ftoc(double f){
    double c = (f - 32) * 5 / 9;
    return c;
}