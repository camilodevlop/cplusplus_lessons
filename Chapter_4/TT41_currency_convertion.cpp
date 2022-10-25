/* Programa que convierte monedas (yen, euros, pounds) a dólares. */

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
	double cantidad = 1;
	char moneda = ' ';

	cout << "Favor ingresar la cantidad y el tipo de moneda (Yen: y, Euro: e, Pounds: p) para convertirlo a dolares: " << endl;
	cin >> cantidad >> moneda;

	if (moneda == 'y')
	{
		cout << "\n- " << cantidad << " Yenes equivalen a " << cantidad / yen_per_dollar << " dolares." << endl;  
	}else if (moneda == 'e')
	{
		cout << "\n- " << cantidad << " Euros equivalen a " << cantidad / euro_per_dollar << " dolares." << endl;
	}else if (moneda == 'p')
	{
		cout << "\n- " << cantidad << " Libras equivalen a " << cantidad / pounds_per_dollar << " dolares." << endl;
	}else
		cout << "\nLa unidad seleccionada no es valida." << endl;

	return 0;
}