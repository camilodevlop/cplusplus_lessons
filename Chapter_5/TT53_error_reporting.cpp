/*Try this to test a program with a variety of values. Print out the values of area1, area2, area3, and ratio.
how do you know that you caught all errors?*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

int area(int, int);
int framed_area (int, int);

int main() {

    // Value that activate all errors.
    int x = -1;
    int y = 2;
    int z = 2;
    
    int area1 = area(x, y);
    if (area1 <= 0) error("non-positive area");
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1) / area3;
    
    cout << "\n\t area1 = " << area1 << "\t area2 = " << area2 << "\t area3 = " << area3 << "\t ratio = " << ratio;
    
    return 0;
}

int area (int length, int width){
    return length * width;
}

int framed_area(int x, int y){
    return area(x-2, y-2);
}