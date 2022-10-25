/* Programa que obtiene el nombre y la edad en años. Entonces se multiplica la edad en años por doce y se obtienen la edad en meses. Al final 
se despliegan los resultados  */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

  cout << "Por favor ingrese su primer nombre y su edad\n";
  string first_name = "???";
  double age = -1;
  
  cin >> first_name >> age;
  cout << "Hello " << first_name << "(age_Meses = " << age * 12 << ")\n\a";
  return 0;

}