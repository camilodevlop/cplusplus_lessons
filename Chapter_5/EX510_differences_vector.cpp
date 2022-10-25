/*Program tha stores a series of integers and then computes the N-1 differences between adjacent values
Write out the vector of differences.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

int main (){

    try{

        vector<double> numbers;
        vector<double> differences;
        double number;
        int N;

        cout << "\n\tEnter the amount N (A vector of N differences will be builded\n\tfrom the adjacent values of a vector):   ";
        cin >> N;

        cout << "\n\tEnter the list of numbers (Press '|' to finish):  \n" ;
        while (cin >> number)
            numbers.push_back(number);
        
        for (int i = 0; i < N; ++i){
            differences.push_back(numbers[i+1] - numbers[i]);
            cout << "\t" << differences[i];
        }

        return 0;
    }
    catch (out_of_range){
        cerr << "\tOops! Range error.\n";
        return 1;
    }
}