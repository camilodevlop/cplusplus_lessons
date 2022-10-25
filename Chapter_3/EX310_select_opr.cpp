/* Programa que recibe el operador y los operadores. El operador se almacena en una cadena y los operadores en variables double. Se ejecuta la operación
que se indica en principio. Las operaciones consideradas son +, -, *, y /. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	double operador_1 = 0;
	double operador_2 = 1;
	string operando = "??";

	cout << "Favor ingresar el operando y los dos operadores (Ejemplo: + 3 4):   ";
	cin >> operando >> operador_1 >> operador_2;

	if (operando == "??")
		cout << "Los datos se han ingresado incorrectamente." << endl;
	else
	{
		if (operando == "+")
			cout << "La suma de " << operador_1 << " + " << operador_2 << " = " << operador_1 + operador_2 << endl;
		if (operando == "-")
			cout << "La resta de " << operador_1 << " - " << operador_2 << " = " << operador_1 - operador_2 << endl;
		if (operando == "*")
			cout << "El producto de " << operador_1 << " * " << operador_2 << " = " << operador_1 * operador_2 << endl;
		if (operando == "/")
			cout << "La relacion de " << operador_1 << " / " << operador_2 << " = " << operador_1 / operador_2 << endl;
	}

	return 0;
}
