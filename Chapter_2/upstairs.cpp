// Programa que describe el proceso para encontrar el baño de una casa teniendo en cuentta las limitaciones de una computadora.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

  cout << "\nDescripción Inicial\n\n";
  cout << "1. El hombre de las cavernas se encuentra sentado en la esquina inferior izquierda de la habitación en dirección norte.\n";
  cout << "2. Existen escaleras en la esquina superior derecha de la habitación.\n";
  cout << "3. Hay diez escaleras.\n";
  cout << "4. A mano derecha se encuentra el baño.\n\n";

  cout << "Proceso\n\n";
  cout << "Se dota a la computadora de las siguientes acciones: levantarse, caminar, girar derecha, girar izquierda, detenerse, abrir, subir escalera.\n";
  cout << "\nSe ejecuta la ruta:\n";
  cout << "\tLevantarse.\n\tCaminar.\n\tDetenerse al llegar a la pared.\n\tGirar a la derecha.\n\tCaminar.\n\tDetenerse al llegar a la escalera.\n\tGirar a la izquierda.\n\tSubir escalera.\n\tDetenerse al llegar al tope de la escalera.\n\tGirar a la derecha.\n\tAbrir puerta del baño.\n\n";

return 0;

}
