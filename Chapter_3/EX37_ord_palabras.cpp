/* Programa que ordena tres palabras */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string var_str_1 = "?";
	string var_str_2 = "?";
	string var_str_3 = "?";
	string var_aux;

	cout << "Favor ingrese tres cadenas para ser ordenadas:  ";
	cin >> var_str_1 >> var_str_2 >> var_str_3;

	if (var_str_1 > var_str_2)
	{
		var_aux = var_str_1;
		var_str_1 = var_str_2;
		var_str_2 = var_aux;
	}
	if (var_str_2 > var_str_3)
	{
		var_aux = var_str_2;
		var_str_2 = var_str_3;
		var_str_3 = var_aux;

		if (var_str_1 > var_str_2)
		{
			var_aux = var_str_1;
			var_str_1 = var_str_2;
			var_str_2 = var_aux;
		}
	}

	cout << "Las cadenas se ordenan como sigue:  " << var_str_1 << ", " <<  var_str_2 << ", " << var_str_3 << "." << endl;

	return 0;
}