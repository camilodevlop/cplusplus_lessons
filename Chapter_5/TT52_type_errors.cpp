/*Try this to compile examples of type errors and see how the compiler responds.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int area(int, int);

int main (){
    
    int x0 = arena(7);
    int x1 = area(7);
    int x2 = area("seven",2);
    int x3 = area("7,2");
    int x4 = area("sieben","zwei");
}

int area (int length, int width){
    return length * width;
}