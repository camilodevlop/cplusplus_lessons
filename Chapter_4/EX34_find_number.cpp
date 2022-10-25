/*This program finds a number between 1 and 100. The program can not answer no more than 7 times.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int number = 0;         // Number to be guessed.
int guess_number = 0;   // Variable for storing the number guessed.
int num_preguntas = 0;  // Counter of questions about the number.
int num_mitad = 50;     // Narrowing number.

bool direction = false;
vector <int> rangos(7);      // Stages for looking a number between 1 and 100.

int main ()
{
    rangos[0] = 25;
    rangos[1] = 12;
    rangos[2] = 6;
    rangos[3] = 3;
    rangos[4] = 1;
    rangos[5] = 1;
    rangos[6] = 1;
    
    cout << "\n\nEnter the number to be gussed: ";
    cin >> number;

    while(guess_number == 0 || num_preguntas <= 6)
    {
        if(number == num_mitad)
            guess_number = num_mitad;
        else
            if(number < num_mitad)
            {
                num_mitad -= rangos[num_preguntas];
                direction = false;
            }else
            {
                num_mitad += rangos[num_preguntas];
                direction = true;
            }

        ++num_preguntas;        
    }

    if(guess_number == 0)
    {
        if(direction)
        {
            guess_number = num_mitad + 1;
        }
        else
        {
            guess_number = num_mitad - 1;
        }
    }

    cout << "\n\nThe guessed number is: " << guess_number << "\n\n";

    return 0;
}