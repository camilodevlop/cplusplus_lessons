/* Programa que le pide al usuario ingresar diferentes valores de monedas de dolar. Se imprime la información de cada moneda y luego muestra el valor
total en centavos y dólares. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	double pennies = 0;
	int nickels = 0;
	int dimes = 0;
	int quarters = 0;
	int half_dollars = 0;
	int dollars = 0;

	cout << "Favor ingresar la cantidad de pennies, nickels, dimes, quarters, half_dollars, dollars:  ";
	cin >> pennies >> nickels >> dimes >> quarters >> half_dollars >> dollars;

	if (pennies == 1)
		cout << "\nYou have 1 pennie." << endl;
	else
		cout << "\nYou have " << pennies << " pennies." << endl;

	if (nickels == 1)
		cout << "You have 1 nickel." << endl;
	else
		cout << "You have " << nickels << " nickels." << endl;

	if (dimes == 1)
		cout << "You have 1 dime." << endl;
	else
		cout << "You have " << dimes << " dimes." << endl;

	if (quarters == 1)
		cout << "You have 1 quarter." << endl;
	else
		cout << "You have " << quarters << " quarters." << endl;

	if (half_dollars == 1)
		cout << "You have 1 half_dollar." << endl;
	else
		cout << "You have " << half_dollars << " half_dollars." << endl;

	if (dollars == 1)
		cout << "You have 1 dollar." << endl;
	else
		cout << "You have " << dollars << " dollars." << endl;

	pennies += (nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + dollars * 100);
	cout << "El valor total en centavos de dolar es: " << pennies << "\nEl valor total en dolares es: " << pennies / 100 << endl;

	return 0;
}