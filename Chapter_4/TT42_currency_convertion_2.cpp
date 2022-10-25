/*  Uso de la isntrucción "switch" para la conversión de monedas. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	const double yen_per_dollar = 119.79;
	const double euro_per_dollar = 0.8949;
	const double pounds_per_dollar = 0.6488;
	const double yuan_per_dollar = 6.2711;
	const double kroner_per_dollar = 7.7931;

	double cantidad = 1;
	char moneda = ' ';

	cout << "Favor ingresar la cantidad y el tipo de moneda (Yen: y, Euro: e, Pound: p, Yuan: c, Kroner: k): " << endl;
	cin >> cantidad >> moneda;

	switch (moneda)
	{
		case 'y':
			cout << "\n- " << cantidad << " Yenes equivalen a " << cantidad / yen_per_dollar << " dolares." << endl;
			break;
		case 'e':
			cout << "\n- " << cantidad << " Euros equivalen a " << cantidad / euro_per_dollar << " dolares." << endl;
			break;
		case 'p':
			cout << "\n- " << cantidad << " Pounds equivalen a " << cantidad / pounds_per_dollar << " dolares." << endl;
			break;
		case 'c':
			cout << "\n- " << cantidad << " Yuanes equivalen a " << cantidad / yuan_per_dollar << " dolares." << endl;
			break;
		case 'k':
			cout << "\n- " << cantidad << " Kroner equivalen a " << cantidad / kroner_per_dollar << " dolares." << endl;
			break;
		default:
			cout << "\nLa unidad seleccionada no es valida." << endl;
			break;
	}

	return 0;
}