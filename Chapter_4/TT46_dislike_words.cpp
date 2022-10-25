/* Programa que impide imprimir palabras que se encuentran almacenadas en un vector. Cuando se detecta una palabra, se imprime la palabra "BLEEP".
El vector de "dislake words" puede crecer. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> dislake_words(1,"Broccoli");
string palabra;
bool bandera = false;		// Indica si se detecto una dislake word en el vector.
char agregar = 'N';

void print_vector_cadena(vector<string> x)
{
	for (int i = 0; i < x.size(); ++i)
		cout << x[i] << "\t";
}


int main()
{
	
	cout << "\n\nPalabras no deseadas: " << endl;
	print_vector_cadena(dislake_words);
	cout << "\n\nPrograma que imprime BlEEP cuando se detecta una palabra no deseada.\n\nIngrese la palabra:";

	while (cin >> palabra)
	{
		for (int i = 0; i < dislake_words.size(); ++i)
			if (palabra == dislake_words[i])
			{
				cout << "\n\nBLEEP\n\a\a" << endl;
				bandera = true;
			}
		if (bandera == false)
		{	
			// Asegura un valor válido para tomar la decisión de agregar una palabra.
			do
			{
				cout << "\nDesea agregar la palabra a la lista de no favoritas: Y/N?   ";
				cin >> agregar;
			} while (agregar != 'Y' && agregar != 'N');
				
			// Agregar palabra al vector.
			if (agregar == 'Y')
			{
				dislake_words.push_back(palabra);
				cout << "Palabras no deseadas:  ";
				print_vector_cadena(dislake_words);
			}
		}
		bandera = false;
		cout << "\n\nIngrese una palabra: ";
	}
	return 0;
}
