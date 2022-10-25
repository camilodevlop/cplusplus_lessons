/*Read (day-of-the-week, value, value) pairs from the standar input. Collect all the values for each day of the 
week in a vector<int> and sum them.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "std_lib_facilities.h"

using namespace std;
void sum_vector(vector<int>);

int main (){

    char conti;         // Variable to continue asking for days and numbers
    string day = " ";
    int number = 0;
    int flag_day;       // Variable to verify the validity of the day format.
    
    // Vectors of values for each day.
    vector<int> monday;
    vector<int> tuesday;
    vector<int> wednesday;
    vector<int> thursday;
    vector<int> friday;
    vector<int> saturday;
    vector<int> sunday;

    cout << "\n\tEnter values in the form:      day - number.\n\n\tThe enabled values for days of the week are:\n\tMon or Monday - Tue or tuesday - Wed or ednesday - Thu or thursday\n\tFri or friday - Sat or saturday - Sun or sunday\n";

    do{
        conti = ' ';
        flag_day = 0;
        
        cout << "\n\tIngresar día y número:   ";
        cin >> day >> number;

        if (day == "Mon" || day == "monday"){
            monday.push_back(number);
            flag_day = 1;
        }
        if (day == "Tue" || day == "tuesday"){
            tuesday.push_back(number);
            flag_day = 1;
        }
        if (day == "Wed" || day == "wednesday"){
            wednesday.push_back(number);
            flag_day = 1;
        }
        if (day == "Thu" || day == "thursday"){
            thursday.push_back(number);
            flag_day = 1;
        }
        if (day == "Fri" || day == "friday"){
            friday.push_back(number);
            flag_day = 1;
        }
        if (day == "Sat" || day == "saturday"){
            saturday.push_back(number);
            flag_day = 1;
        }
        if (day == "Sun" || day == "sunday"){
            sunday.push_back(number);
            flag_day = 1;
        }
        if (flag_day == 0){
            cout << "\n\n\tThe day value is invalid.";
        }
        
        while (conti != 'y' && conti != 'n'){
            cout << "\n\tDesea continuar? 'y' or 'n'\n";
            cin >> conti;
        }
    
    } while (conti == 'y');
    
    cout << "\n\n\tMonday: "; sum_vector(monday);
    cout << "\tTuesday: "; sum_vector(tuesday);
    cout << "\tWednesday: "; sum_vector(wednesday);
    cout << "\tThursday: "; sum_vector(thursday);
    cout << "\tFriday: "; sum_vector(friday);
    cout << "\tSaturday: "; sum_vector(saturday);
    cout << "\tSunday: "; sum_vector(sunday);
    
    return 0;
}

// Function to add the elements of an integer vector.

void sum_vector(vector<int> vec){
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i){
        cout << "\t" << vec[i];
        sum += vec[i];
    }
    cout << "\tSum = " << sum << '\n';
    
    return;
}