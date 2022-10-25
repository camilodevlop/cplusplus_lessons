/*Create a program to find all the prime numbers between 1 to max based on the "Sieve of Eratosthenes". Tha value of max is an input. Consider 2 the
first prime.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_numbers = 200;                    // Number range.
vector<int> numbers(max_numbers);         // Primes vector.
int aux_var;                              // Prime number multiplier.
int producto;                             // Multiples of the evaluated number.

int main(){
    for (int i = 2; i < max_numbers; i++){
        
        // If the number is prime, it is equal to 0 in vector numbers.
        if (numbers[i] == 0){
            cout << i << "\n";
            aux_var = i;
            producto = i;
            
            // The multiples of the prime are discard.
            while (producto <= max_numbers){
                numbers[producto] = producto;
                producto = i * aux_var;
                ++aux_var;
            }
        }
    }

    // Code for printing vectors.
    for (int j = 0; j < numbers.size(); ++j){
        if (j % 20 == 0){
            cout << "\n";
        }
        cout << numbers[j] << "\t";
    }
    return 0;
}