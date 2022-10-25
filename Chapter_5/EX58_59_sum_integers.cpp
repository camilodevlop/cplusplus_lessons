/*Program tha stores a series of integers and then computes the sum of the first N integers. N is previously
assigned by the user. Write out an error if the result cannot be represented as an int*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

int main (){

    try{

        vector<int> numbers;
        int number;
        int N;

        cout << "\n\tEnter the amount N of numbers that must be added:   ";
        cin >> N;

        cout << "\n\tEnter the list of numbers (Press '|' to finish):  \n" ;
        while (cin >> number)
            numbers.push_back(number);
        
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += numbers[i];
        
        cout << "\n\tLa sumatoria es:   " << sum << '\n';
        
        // It show an error if the result cannot be represented as an int.
        int x1 = narrow_cast<int> (sum + 0.1);

        return 0;
    }
    catch (out_of_range){
        cerr << "Oops! Range error.\n";
        return 1;
    }
    catch (exception& e){
        cerr << "\n\tError:   " << e.what() << '\n';
        return 2;
    }
}