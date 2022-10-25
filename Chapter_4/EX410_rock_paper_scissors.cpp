/*Write a program that plays the game "Rock, Paper, Scissors"*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> option_machine;
int machine_value;
int user_value;

int main()
{
    //The machine's options are collected.
    cout << "\n\n\tInput the machine's options.\n\tRock = 1, Paper = 2, and Scissors = 3\n\n";
    for (int i = 0; i < 10; ++i)
    {
        cout << "\tInput the value number " << i << ":\t";
        cin >> machine_value;
        option_machine.push_back(machine_value);
    }

    // Playing "Rock, Paper, Scissors".
    for (int i = 0; i < 10; ++i)
    {
        cout << "\nEnter your game, please. \n\tRock = 1, Paper = 2, and Scissors = 3\n";
        cin >> user_value;
        machine_value = option_machine[i];

        switch (machine_value)
        {
        case 1:
            if (user_value == 1)
                cout << "\nTie\n";
            else
                if (user_value == 2)
                {
                    cout << "\nYou win\n";
                }
                else
                {
                    cout << "\nYou lose\n";
                }
            break;
        
        case 2:
            if (user_value == 1)
                cout << "\nYou lose\n";
            else
                if (user_value == 2)
                {
                    cout << "\nTie\n";
                }
                else
                {
                    cout << "\nYou win\n";
                }

            break;
        
        case 3:
            if (user_value == 1)
                cout << "\nYou win\n";
            else
                if (user_value == 2)
                {
                    cout << "\nYou lose\n";
                }
                else
                {
                    cout << "\nTie\n";
                }

            break;
        
        default:
            cout << "\nInvalid option.\n";
            break;
        }

    }
    return 0;
}