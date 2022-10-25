/*  Programa para el repaso de la temática estudiada en el capítulo 4. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int select_unit(vector<string>, int, string);
void print_vector(vector<double>);

int main()
{
	double double_1;
	double var_aux;					// Almacena los valores ingresados en metros. Sirve de bandera para procesar valores con unidades válidas. 
	double sumatoria = 0;
	double cantidad_val = 0;
	double smallest;
	double largest;

	string user_units = " ";
	vector<string> units(4);
	units[0] = "m";
	units[1] = "cm";
	units[2] = "in";
	units[3] = "ft";

	vector<double> val_metros;		// Vector donde se almacenan los valores convertidos a metros que ingresó el usuario.

	
	cout << "Favor ingrese un valor y su unidad (m, cm, in, ft) (| para terminar):  ";

	while (cin >> double_1 >> user_units)
	{
		var_aux = -1;
		switch (select_unit(units, units.size(), user_units))
		{
			case 0:
				var_aux = double_1;
				cout << "Usted ha ingresado:\t" << double_1 << "m" << endl;
				break;
			case 1:
				var_aux = double_1 / 100.0;
				cout << double_1 << "cm equivalen a " << var_aux << "m." << endl;
				break;
			case 2:
				var_aux = double_1 * (2.54 / 100.0);
				cout << double_1 << "in equivalen a " << var_aux << "m." << endl;
				break;
			case 3:
				var_aux = double_1 * (12 * 2.54 / 100.0);
				cout << double_1 << "ft equivalen a " << var_aux << "m." << endl;
				break;
			default:
				cout << "Usted ha ingresado una unidad incorrecta." << endl;
				break;
		}
		if (var_aux != -1)
		{
			sumatoria += var_aux;
			++cantidad_val;
			val_metros.push_back(var_aux);
			
			if (cantidad_val > 1)			// Registra cuál es el valor más pequeño y el más grande ingresado por el ususario.
			{
				if (var_aux < smallest)
				{
					smallest = var_aux;
				}
				if (var_aux > largest)
				{
					largest = var_aux;
				}
			}else{
				smallest = var_aux;
				largest = var_aux;
			}

		}
		cout << "Favor ingrese un valor y su unidad (m, cm, in, ft) (| para terminar):  ";
	}
	cout << "\n\nLa suma total en metros de los valores ingresados es:\t" << sumatoria << endl;
	cout << "La cantidad de valores ingresados es:      \t" << cantidad_val << endl;
	sort(val_metros.begin(), val_metros.end());
	cout << "El vector de los valores organizados de menor a mayor es:";
	print_vector(val_metros);

	if (cantidad_val >= 1)
	{
		cout << "El menor valor ingresado es:	\t" << smallest << endl;
		cout << "El mayor valor ingresado es:	\t" << largest << endl;
	}
	return 0;
}

int select_unit(vector<string> units, int size, string user_unit)			// Función para elegir la unidad deseada (cm, m, in, ft).
{
	int s_unit = size;
	for (int i = 0; i < size; ++i)
		if (units[i] == user_unit)
			s_unit = i;
	return s_unit;	
}

void print_vector(vector<double> val_mt)									// Función que imprime vector.
{
	for (int i = 0; i < val_mt.size(); ++i)
		cout << "\t" << val_mt[i];
	cout << endl;
}