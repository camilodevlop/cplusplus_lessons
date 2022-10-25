/* Program that finds a mode of a set of strings.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string input_string = "";
vector<string> strings;
int i = 0;                  // Vector subscript.
int counter = 1;            // Rep counter.
string mode = "";               // Mode value.
int mode_counter = 1;

void print_vector(vector<string>);

int main (){

    // Collecting strings.
    cout << "\n\tEnter the strings to evaluate please:\n\t";
    while (cin >> input_string){
        cout << "\t";
        strings.push_back(input_string);
    }
    print_vector(strings);
    
    // Sorting the vector.
    sort(strings.begin(),strings.end());
    print_vector(strings);
    
    while (i < strings.size()){
        while ((i+1) < strings.size() && strings[i] == strings[i+1]){
            ++counter;
            ++i;
        }

        if (counter > mode_counter){
            mode = strings[i];
            mode_counter = counter;
        }
        
        counter = 1;
        ++i;
    }
    
    cout << "\n\tmode = " << mode << "\tmode_counter = " << mode_counter << "\n";
    return 0;


}

// Function to print vectors of strings.
void print_vector(vector<string> x){

    for (int i = 0; i < x.size(); ++i){
        if (i % 10 == 0)
            cout << "\n";
        cout << x[i] << "\t";
    }
}