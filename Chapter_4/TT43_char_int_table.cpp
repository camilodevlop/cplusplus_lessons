/* Uso de la instrucción "while" para imprimir una tabla de caracteres y sus valores enteros correspondientes. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i = 0;
	char letra = 'a';
	cout << '\t' << "Letra" << '\t' << "Entero" << endl;

	while (i <= 25)
	{
		cout << '\t' << char(letra + i) << '\t' << int(letra + i) << endl;
		++i;
	}

	return 0;
}