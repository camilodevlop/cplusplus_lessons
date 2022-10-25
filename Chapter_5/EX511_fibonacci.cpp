/*Program that writes out the first so many values of the Fibonacci series. It finds the largest Fibonacci number
that fits in an int.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

int main (){
    try{
       
       int fib1 = 1;
       int fib2 = 1;
       int fib = 0;

       while (true){
           fib = narrow_cast<int> (fib1 + fib2);
           if (fib <= 0)
            error("\n\tOverflow.");
           
           cout << "\t" << fib;
           fib1 = fib2;
           fib2 = fib;
       }
       return 0;
    }
    catch(exception& e){
        cerr << "\n\tError:   " << e.what() << '\n';
        return 1;
    }
}