/*Create a program that takes an input value n and then finds the first n primes.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int number_primes;
int var_control_primes = 0;              

bool prime(int);                // Function prototype.

int main()
{
    cout << "\n\tEnter the number of prime numbers you want to find:\t";
    cin >> number_primes;
    
    int i = 2;
    while (var_control_primes < number_primes){
        if (prime(i)){
            ++var_control_primes;
            cout << "\t" << i;
        }
        ++i;
    }
}

// Function to determinate if a number is prime. Return true if or false of not.
bool prime(int x)
{
    int integer_div_counter = 0;
    int divider = 1;

    while (integer_div_counter < 2)
    {
        if (x % divider == 0)
        {
            ++integer_div_counter;
        }
        ++divider;
    }
    if (divider > x)
        return true;
    else
        return false;
}