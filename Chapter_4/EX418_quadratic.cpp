/*Program to solve quadratic equations.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double a, b, c;            // ax2 + bx + c
double determinant;
double x1, x2;             // Solutions.

int main (){

    cout << "\n\tEnter the numbers that compose the equation, a   b   c:\n\t";
    cin >> a >> b >> c;
    
    determinant = pow(b,2) - (4 * a * c);
    
    if (determinant < 0){
        cout << "\n\tThe equation has not solution in R\n";
    }else{
        x1 = (-b + sqrt(determinant)) / (2 * a);
        cout << "\n\tx1 = " << x1;

        x2 = (-b - sqrt(determinant)) / (2 * a);
        cout << "\n\tx2 = " << x2;
    }
    
    return 0;
}
