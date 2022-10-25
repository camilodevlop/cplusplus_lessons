/* Program that finds a mode of a set of positive integers.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int input_number = 0;
vector<int> numbers;
int i = 0;                  // Vector subscript.
int counter = 1;            // Rep counter.
int mode = 0;               // Mode value.
int mode_counter = 1;

void print_vector(vector<int>);

int main (){

    // Collecting values.
    cout << "\n\tEnter the numbers to evaluate please:\n\t";
    while (cin >> input_number){
        cout << "\t";
        numbers.push_back(input_number);
    }
    print_vector(numbers);
    
    // Sorting the vector.
    sort(numbers.begin(),numbers.end());
    print_vector(numbers);
    
    while (i < numbers.size()){
        while ((i+1) < numbers.size() && numbers[i] == numbers[i+1]){
            ++counter;
            ++i;
        }

        if (counter > mode_counter){
            mode = numbers[i];
            mode_counter = counter;
        }
        
        counter = 1;
        ++i;
    }
    
    cout << "\n\tmode = " << mode << "\tmode_counter = " << mode_counter << "\n";
    return 0;


}

// Function to print vectors of integers.
void print_vector(vector<int> x){

    for (int i = 0; i < x.size(); ++i){
        if (i % 10 == 0)
            cout << "\n";
        cout << x[i] << "\t";
    }
}