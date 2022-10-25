/*This program calculates the number of permutations or combinations from two integers a and b. The user chooses which
calculation must be executed.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

class Integer_overflow{};

//------------------------------------------------------------------------------
// Function that calculates the factorial and the permutations.
unsigned int factorial(unsigned int x, int diff)
{
    if (diff == 0)
        return 1;
    else
        return x * factorial(x - 1, diff - 1);
}
//------------------------------------------------------------------------------
int main()
{
    try
    {

     cout << "\n\n\tThis program calculates the permutation or combination\n\tfrom two integers a and b.";
     cout << "\n\n\tThe numbers must be positive or zero.\n\tThe number a must be greater than b.";
     
     int a, b;

     // Guarantee that a and b are positive, and a > b.
     do
     {
         cout << "\n\n\tEnter the integers a and b:   ";
         cin >> a >> b;
        
        if (a < 0 && b < 0)
            cout << "\n\tOne or both values are negative.";
        
        if (b > a)
            cout << "\n\tb value is greater than a :( ";
        
    } while ((a < 0 && b < 0) || (b > a));
     
    
    // Choose between permutation and combination.
    char opt = ' ';
    do
    {
      cout << "\n\n\t'p' to select permutation - 'c' to select combination:  ";
      cin >> opt;

      if (opt != 'p' && opt != 'c')
        cout << "\n\tInvalid option.";
      
    } while (opt != 'p' && opt != 'c');

    
    // Final calculation.                           Definir excepción si crece demasiado.
    unsigned int permutation = factorial(a, a-b);
    if (permutation == 0)
        throw Integer_overflow();
    
    unsigned int fact_b = factorial(b, b);

    if (opt == 'p')
        cout << "\n\tThe number of permutations is:  " << permutation << '\n';
    else
    {
        unsigned int combination = permutation / factorial(b, b);
        cout << "\n\tThe number of combinations is:  " << combination << '\n';
    }
        return 0;   
    }
    catch(Integer_overflow)
    {
        cout << "\n\n\tThe number of permutations is too large.\n";
        return 1;
    }    
    catch(exception& e)
    {
        cerr << "\n\n\tError: " << e.what() << '\n';
        return 2;
    }
}