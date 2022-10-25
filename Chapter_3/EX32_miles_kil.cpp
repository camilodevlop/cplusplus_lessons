/* Programa que convierte a kilómetros la cantidad de millas que es ingresada por el usuario.  */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

	double num_miles = 0;
	cout << "Favor ingresar el numero de Millas para convertirlas en Kilometros:  ";
	cin >> num_miles;
	cout << "\nLa cantidad de Kilometros es:   " << num_miles * 1.609 << " Km" << endl;

	return 0;
}