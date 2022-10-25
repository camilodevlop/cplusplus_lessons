/*Try this to compile examples of syntax errors and see how the compiler responds.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int area(int, int);

int main (){
    
    int s1 = area(7;
    int s2 = area(7)
    Int s3 = area(7);
    int s4 = area('7');
}

int area (int length, int width){
    return length * width;
}