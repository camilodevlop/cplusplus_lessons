/*This program change a numeric value in its spelled version.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int number;                         // Variable stores the numeric value.
string number_s;                    // Variable stores the spelled value.
vector<string> values(10);          // Set of spelled values.

int main()
{
    values[0] = "zero";
    values[1] = "one";
    values[2] = "two";
    values[3] = "three";
    values[4] = "four";                 // Vector initialization.
    values[5] = "five";
    values[6] = "six";
    values[7] = "seven";
    values[8] = "eight";
    values[9] = "nine";

    
    cout << "\n\nTo input a number between 0 and 9, please: ";
    cin >> number;

    while(number >= 0 && number <= 9)
    {
        number_s = values[number];                              // Number to spelled_number.
        cout << "\n\nThe spelled number is: " << number_s;

        for(int i = 0; i < values.size();++i)                   // Spelled_number to Number.
            if(values[i] == number_s)
                cout << "\nThe numeric values of the number is: " << i;

        cout << "\n\nTo input a new number between 0 and 9, please: ";
        cin >> number;
    }

    cout << "\nyou entered a value out of the range. Thanks for using this program.\n\n";
}
