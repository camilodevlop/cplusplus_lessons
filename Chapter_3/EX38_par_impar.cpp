/* Programa que determina si un valor entero es par o impar */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int int_value = 0;

	cout << "Favor ingresar un valor entero:  ";
	cin >> int_value;

	if (int_value % 2 == 0)
		cout << "El valor " << int_value << " es par." << endl;
	else
		cout << "El valor " << int_value << " es impar." << endl;

	return 0;
}