/* Programa que utiliza una función basada en sumas para calcular el cuadrado de un entero. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int square_suma(int x)
{
	int producto = 0;
	for (int i = 0; i < x; ++i)
		producto += x;
	return producto;
}


int main()
{
	int i = 0;
	
	while (i < 100)
	{
		cout << i << '\t' << square_suma(i) << '\n';
		++i;
	}

	return 0;
}