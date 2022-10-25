/*Create a program to find all the prime numbers between 1 to max. Tha value of max is an input. Consider 2 the
first prime.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_numbers = 100;              
vector<int> primes;             // Primes vector.
bool prime(int);                // Function prototype.

int main()
{
    for (int i = 2; i <= max_numbers; i++){
        if (prime(i)){
            primes.push_back(i);
        }
    }

    // Code for printing vectors.
    for (int j = 0; j < primes.size(); ++j)
        cout << primes[j] << "\t";
    
    return 0;
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