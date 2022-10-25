/*The game called "Bulls and Cows" is implemented in this program.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "std_lib_facilities.h"

using namespace std;
using u32 = uint_least32_t;
using engine = std::mt19937;

int main (){
    
    // generating four random numbers between 0 and 9.
    random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    uniform_int_distribution<u32> distribute(0,9);
    
    vector<int> values;
    for (int i = 0; i < 4; i++){
        values.push_back(distribute (generator));
        cout << values[i] << '\n';
    }

    int value;
    int guessed_count = 0;
    char restar = ' ';
    
    do{
        cout << "\n\tEnter four integer values between 0 and 9.\n\tValues are entered one at a time.";
        cout << "\n\n\tIf the entered number matches the system number,\n\t1 Bull and 1 Cow is printed.\n\n";
        
        for (int i = 0; i < 4; ++i){
            cin >> value;
            if (values[i] == value){
                cout << value << "\t1 bull and 1 cow\n";
                ++guessed_count;
            }
            else{
                cout << value << "\tFail\n";
            }
        }

        if (guessed_count != 4){
            restar = ' ';
            while (restar != 'y' && restar != 'n'){
                cout << "\n\tYou lost. Do you want to try again? 'y' or 'n':   ";
                cin >> restar;
            }
            guessed_count = 0;
        }
        else{
            cout << "\n\tYou win!!!\n";
            restar = 'n';
        }
    } while (restar == 'y');

    return 0;
}