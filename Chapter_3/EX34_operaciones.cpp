/* Programa que recibe dos entetos y determina cuál es el menor, el mayor, la suma, diferencia, el producto y su relación */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

	double val1 = 0;
	double val2 = 1;

	cout << "Favor ingresar los datos para val1 y val2:  ";
	cin >> val1 >> val2;

	if (val1 < val2)
		cout << "\nEl valor mas pequeño es:  " << val1 << "\nEl valor mas grande es:  " << val2 << endl;
	else if (val1 > val2)
		cout << "\nEl valor mas pequeño es:  " << val2 << "\nEl valor mas grande es:  " << val1 << endl;

	cout << "Suma:     " << val1 << "+" << val2 << " = " << val1 + val2 
		 << "\nResta:    " << val1 << "-" << val2 << " = " << val1 - val2
		 << "\nProducto: " << val1 << "*" << val2 << " = " << val1 * val2
		 << "\nRelacion: " << val1 << "/" << val2 << " = " << val1 / val2 << endl;

	return 0;
}