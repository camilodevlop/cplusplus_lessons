/*Program that performs a very simple calculator.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double number_1 = 0;
double number_2 = 0;
char operation = '0';

int main ()
{
    cout << "Please input: number_1, number 2 and Operation\n";
    cin >> number_1 >> number_2 >> operation;

    cout << "\n\nnumber 1: " << number_1 << "\tnumber 2: " << number_2 << "\tOperation: " << operation << "\n\n";

    switch (operation)
    {
        case '+':
            cout << "The result of sum is:  " << number_1 << " + " << number_2 << " = " <<  number_1 + number_2 << "\n\n";
        break;

        case '-':
            cout << "The result of substract is:  " << number_1 << " - " << number_2 << " = " <<  number_1 - number_2 << "\n\n";
        break;

        case '*':
            cout << "The result of multiplication is:  " << number_1 << " * " << number_2 << " = " <<  number_1 * number_2 << "\n\n";
        break;
        
        case '/':
            cout << "The result of division is:  " << number_1 << " / " << number_2 << " = " <<  number_1 / number_2 << "\n\n";
        break;
        
        default:
            cout << "The entered operation is invalid\n\n";
        break;
    }                                                                     

    return 0;
}