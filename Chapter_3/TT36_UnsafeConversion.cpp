/* Programa que permite evaluar los cambios sufridos por los valores cuando se manipulan diferentes tipos de variables. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

double d = 0;
while (cin >> d){

int i = d;
char c = i;
int i2 = c;
cout << "d == " << d << ", i == " << i << ", i2 == " << i2 << ", char(" << c << ")" << endl;

}
return 0;
}
