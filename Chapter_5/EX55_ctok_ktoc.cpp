/*The following program takes in a temperature in Celsius and converts it to Kelvin, or takes in a temperature
in Kelvin and converts it to Celsius. It prevents issues related to absolute zero.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;
double ctok(double);
double ktoc(double);

int main (){
    
    char option = ' ';
    while (option != 'c' && option != 'k'){
        cout << "\nChoose the temperature scale. Type 'c' for Celsius or 'k' for Kelvin:  ";
        cin >> option;
    }
    
    if (option == 'c'){
        
        double c = -274.0;
        while (c < -273.15){
        cout << "\n\t(consider absolute zero to be -273.15 C)\n\n\tEnter temperature in Celsius:   ";
        cin >> c;
        }
    
        double k = ctok(c);
        cout << "\tThe temperature in Kelvin is:   " << k << '\n';
    }
    else{
        double k = -0.1;
        while (k < 0){
            cout << "\n\t(consider absolute zero to be 0 K)\n\n\tEnter temperature in Kelvin:   ";
            cin >> k; 
        }

        double c = ktoc(k);
        cout << "\tThe temperature in Celsius is:   " << c << '\n';
    }
    
    return 0;
}

// Celsius to Kelvin function.
double ctok(double c){
    double k = c + 273.15;
    return k;
}

// Kelvin to Celsius function.
double ktoc(double k){
    double c = k - 273.15;
    return c;
}