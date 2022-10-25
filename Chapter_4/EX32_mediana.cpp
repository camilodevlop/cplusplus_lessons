/*Program for determining the median from a vector values. The median is defined as "a number so that exactly as many elements come before
it in the sequence as come after it"*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    vector<double> numbers;
    double number;
    int vector_center;
    
    while (cin >> number)
        numbers.push_back(number);
    
    sort(numbers.begin(),numbers.end());
    vector_center = numbers.size() / 2;
    cout << "\nPosicion mitad del Vector" << vector_center << "\n";
    
    if  (vector_center % 2 == 0)
        cout << "\nLa mediana es: " <<  numbers[vector_center] << "\n";
    else
        cout << "\nLa mediana es: " << (numbers[vector_center] + numbers[vector_center - 1]) / 2 << "\n";
}