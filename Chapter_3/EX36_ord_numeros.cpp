/*  Programa que ordena tres números enteros */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	
	int var_int_1 = 0;
	int var_int_2 = 0;
	int var_int_3 = 0;
	int var_aux;

	cout << "Favor ingrese tres valores enteros para ser ordenados:  ";
	cin >> var_int_1 >> var_int_2 >> var_int_3;

	if (var_int_1 > var_int_2)
	{
		var_aux = var_int_1;
		var_int_1 = var_int_2;
		var_int_2 = var_aux;
	}
	if (var_int_2 > var_int_3)
	{
		var_aux = var_int_2;
		var_int_2 = var_int_3;
		var_int_3 = var_aux;
		
		if (var_int_1 > var_int_2)
		{
			var_aux = var_int_1;
			var_int_1 = var_int_2;
			var_int_2 = var_aux;
		}
	}

	cout << "Los valores ordenados son:  " << var_int_1 << ", " << var_int_2 << ", " << var_int_3 << "." << endl;

	return 0;
}