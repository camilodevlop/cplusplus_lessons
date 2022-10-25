/*Try this to use exceptions.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

class Bad_area{};
int area(int, int);
int framed_area (int, int);

int main() {

    vector<int> ve;
    try{

        // Value that activate all errors.
        int x = 1;
        int y = 3;
        int z = 4;
    
        int area1 = area(x, y);
        int area2 = framed_area(3, z);
        int area3 = framed_area(y, z);
        double ratio = double(area1) / area3;

        cout << "\n\t area1 = " << area1 << "\t area2 = " << area2 << "\t area3 = " << area3 << "\t ratio = " << ratio;

        for(int x; cin >> x;)
            ve.push_back(x);
        for(int i = 0; i < ve.size(); ++i)
            cout << "\nv[" << i << "] = " << ve[i] << "\n";

        int x4 = narrow_cast<int>(2.9);
    }
    catch(Bad_area){
        cerr << "Oops! bad arguments to area()\n";
        return 1;
    }
    catch(out_of_range){
        cerr << "Oops! Range error\n";
        return 2;
    }
    catch(runtime_error){
        cerr << "Oops! run time error\n";
        return 3;
    }
    catch(...){
        cerr << "Something went wrong\n";
        return 4;
    }
}

int area (int length, int width){
    if(length <= 0 || width <= 0)
        throw Bad_area();
    return length * width;
}

int framed_area(int x, int y){
    return area(x-2, y-2);
}