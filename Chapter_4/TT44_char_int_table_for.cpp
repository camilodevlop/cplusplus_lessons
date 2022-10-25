/*  Uso de la instrucción "for" para imprimir una tabla de caracteres formado por dígitos y el abecedario en mayúsculas y minúsculas. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	char letra = ' ';
	cout << '\t' << "Caracter" << "\tEntero" << endl;

	// Instrucción "for" para imprimir dígitos.
	
	letra = 48;
	for (int i = 0; i <= 9; ++i)
		cout << '\t' << char(letra + i) << "\t        " << int(letra + i) << endl;

	
	// Instrucción "for" para imprimir el abecedario en mayúsculas.

	letra = 65;
	for (int i = 0; i <= 25; ++i)
		cout << '\t' << char(letra + i) << "\t        " << int(letra + i) << endl;

	// Instrucción "for" para imprimir el abecedario en minúsculas.

	letra = 97;	
	for (int i = 0; i <= 25; ++i)
		cout << '\t' << char(letra + i) << "\t        " << int(letra + i) << endl;

	return 0;
}