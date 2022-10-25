/*Program that reads digits and composes them into integers. For example, 123 is read as the caracters 1,2 and 3.
The program should output 123 is 1 hundred and 2 tens and 3 ones.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
class Digits_integers
{
    public:
        void get();                 // Function that obtains the digits.
        void convert_int();         // Function that convert the digits to int.
        void convert_string();      // Function that convert the digits to string.
    
    private:
        int num = 0;                // Contains the integer.
        vector<int> dig_int;        // Contains the separate digits.
};
//------------------------------------------------------------------------------
// Function that obtains the digits.
void Digits_integers::get()
{
    char ch;
    
    while (true)
    {
        cin >> ch;

        switch (ch)
        {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            dig_int.push_back(ch - '0');
            break;

        case ',':
            break;

        case '.':
            return;
        
        default:
            error("\n\tSomething is wrong\n\t");
        }
    }
    
}
//------------------------------------------------------------------------------
// Function that convert the digits to int.
void Digits_integers::convert_int()
{
    int size_vec = dig_int.size();
    int pow_10 = pow(10,size_vec - 1);
    
    for (int i = 0; i < size_vec; i++)
    {
        num += (dig_int[i] * pow_10);
        pow_10 /= 10;
    }
    
    cout << "\n\t" << num << '\t';

    return;
}
//------------------------------------------------------------------------------
// Function that convert the digits to string.
void Digits_integers::convert_string()
{
    int size_vec = dig_int.size();
    int index = 0;
    
    switch (size_vec)
    {
    case 4:
        if (dig_int[index] == 1)
            cout << dig_int[index] << " thousand unit and ";
        else
            cout << dig_int[index] << " thousand units and ";
        
        ++index;
    
    case 3:
        if (dig_int[index] == 1)
            cout << dig_int[index] << " hundred and ";
        else
            cout << dig_int[index] << " hundreds and ";

        ++index;

    case 2:
        if (dig_int[index] == 1)
            cout << dig_int[index] << " ten and ";
        else
            cout << dig_int[index] << " tens and ";

        ++index;

    case 1:
        if (dig_int[index] == 1)
            cout << dig_int[index] << " unit.\n\t";
        else
            cout << dig_int[index] << " units.\n\t";
        return;
    
    default:
        error("\n\tThe vector has no elements.");
        break;
    }
}
//------------------------------------------------------------------------------

Digits_integers di;             // Provides get(), convert_int(), and convert_string().

//------------------------------------------------------------------------------
int main()
{
    try
    {
        cout << "\n\n\tProgram that reads digits and composes them into integers.";
        cout << "\n\tInput the digits as the form 1,2,3,4.\n\tThe maximum number of digits is 4.\n\n\t";

        cout << "Enter the digits:\t";
        
        di.get();
        di.convert_int();
        di.convert_string();
        return 0;
    }
    catch(exception& e)
    {
        cerr << "\n\tError: " << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        "\n\tOops: unknown exception!\n";
        return 2;
    }
}
//------------------------------------------------------------------------------
