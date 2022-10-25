/* Programa que convierten cadenas que representas valores enteros entre 0 y 4, en su dígito correspondiente */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int digito = 5;
	string cadena_num = "??";

	cout << "Favor ingresar la cadena de caracteres de un numero entre 0 y 4:  ";
	cin >> cadena_num;

	if (cadena_num == "cero")
		digito = 0;
	if (cadena_num == "uno")
		digito = 1;
	if (cadena_num == "dos")
		digito = 2;
	if (cadena_num == "tres")
		digito = 3;
	if (cadena_num == "cuatro")
		digito = 4;

	if (digito != 5)
		cout << "El digito correspondiente a la cadena ingresada es: " << digito << "." << endl;
	else
		cout << "Usted ha ingresado un valor inaceptable." << endl;

	return 0;
}