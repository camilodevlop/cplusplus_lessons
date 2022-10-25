/* Programa que permite visualizar el efecto de los operadores presentados en el capítulo. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

int a,b;
double f;

cout << "Para evaluar las operaciones favor ingresar dos valores enteros (a, b):" << endl;
cin >> a >> b;

f = a;
cout << "Producto: a*b = " << a*b
<< "\nDivision: a/b = " << a/b
<< "\nRemainder: a mod b = " << a%b
<< "\nDivision entera: a/b * b + a%b == a " << a/b * b + a%b
<< "\nsqrt(a) = " << sqrt(f) << endl;
return 0;

}