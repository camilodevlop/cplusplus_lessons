/*Calculator based on the exercise 5. It accepts just single-digit numbers written as either digits or spelled out.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n_1 = -1;               // Numbers to be operated.
int n_2 = -2;
char operation = '0';       // Operation select.

string number_1 = "0";
string number_2 = "0";

vector<string> spelled_values(10);      // Set of spelled values.
vector<string> numeric_values(10);      // Set of numeric values.

int main()
{
    spelled_values[0] = "zero";
    spelled_values[1] = "one";
    spelled_values[2] = "two";
    spelled_values[3] = "three";
    spelled_values[4] = "four";                 // Vector initialization.
    spelled_values[5] = "five";
    spelled_values[6] = "six";
    spelled_values[7] = "seven";
    spelled_values[8] = "eight";
    spelled_values[9] = "nine";

    numeric_values[0] = "0";
    numeric_values[1] = "1";
    numeric_values[2] = "2";
    numeric_values[3] = "3";
    numeric_values[4] = "4";                 // Vector initialization.
    numeric_values[5] = "5";
    numeric_values[6] = "6";
    numeric_values[7] = "7";
    numeric_values[8] = "8";
    numeric_values[9] = "9";

    // Input of values.
    cout << "\nPlease input: number_1, number_ and the operation.\nThe numbers can be input as numeric or spelled form from 1 to 9.\n\n";
    cin >> number_1 >> number_2 >> operation;
    cout << "\n\nnumber_1: " << number_1 << "\tnumber_2: " << number_2 << "\tOperation: " << operation << "\n\n";

    // String to number convertion.
    for(int i = 0; i < spelled_values.size(); ++i)
        if(spelled_values[i] == number_1 || numeric_values[i] == number_1)
            n_1 = i;
    
    for (int i = 0; i < spelled_values.size(); ++i)
        if(spelled_values[i] == number_2 || numeric_values[i] == number_2)
            n_2 = i;

    // Operation execution.
    if(n_1 == -1 || n_2 == -1)
        cout << "Numbers entered are not valid.\nRemember, numbers can be input as numeric or spelled form from 1 to 9.\n\n";
    else
        switch (operation)
        {
            case '+':
                cout << "The result of sum is:  " << n_1 << " + " << n_2 << " = " <<  n_1 + n_2 << "\n\n";
            break;

            case '-':
                cout << "The result of substract is:  " << n_1 << " - " << n_2 << " = " <<  n_1 - n_2 << "\n\n";
            break;

            case '*':
                cout << "The result of multiplication is:  " << n_1 << " * " << n_2 << " = " <<  n_1 * n_2 << "\n\n";
            break;
            
            case '/':
                cout << "The result of division is:  " << n_1 << " / " << n_2 << " = " <<  n_1 / n_2 << "\n\n";
            break;
            
            default:
                cout << "The entered operation is not valid\n\n";
            break;
        }
    
    return 0;
}