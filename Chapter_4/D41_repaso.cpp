/* Recordatorio de los temas del capítulo 4. */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double typed_value;
string units;
int unit_selector;
int contador_unit;                          // Value counter.

double acumulador = 0;                      // Sum of the values.
double smallest_value = 0; 
double largest_value = 0;

vector <double> distances;

int select_unidad(string);               /*Prototipo de la función para seleccionar la unidad.*/
void print_vector(vector<double>);        // Function Prototype for print a vector.

int main()
{
    cout << "\n\nThis program adds a unit to each double entered.\nTo type one floating point number and its unit (m, cm, in, ft):\n";

    while (cin >> typed_value >> units)
        {
            cout << "\n" << typed_value << " is the value typed and " << units << " is the unit selected.\nConvertions:\n";
            
            unit_selector = select_unidad(units);   /*Llamada a función de selector de unidades.*/

            switch (unit_selector)
            {
                case 1:                             /*Unidades en metros.*/
                    typed_value *= 100;
                    cout << typed_value << " cm\t\t" << typed_value / 2.54 << " in\t" << typed_value / 30.48 << " ft.\n\n";
                    break;

                case 2:                             /*Unidades en centímetros.*/
                    cout << typed_value / 100 << " m\t\t" << typed_value / 2.54 << " in\t" << typed_value / 30.48 << " ft.\n\n";
                    break;
                
                case 3:
                    typed_value *= 2.54;            /*Unidades en pulgadas.*/
                    cout << typed_value / 100 << " m\t\t" << typed_value << " cm\t" << typed_value / 30.48 << " ft.\n\n";
                    break;

                case 4:
                    typed_value *= 30.48;           /*Unidades en pies.*/
                    cout << typed_value / 100 << " m\t\t" << typed_value << " cm\t" << typed_value / 2.54 << " in.\n\n";
                    break;

                default:                            /*Unidades en centímetros.*/
                    cout << "The provided unit is not suitable.\n\n";
                    break;
            }

            if (unit_selector != 0)
            {
                acumulador += typed_value;           // Values sum.
                ++contador_unit;                     // Values counter.
                distances.push_back(typed_value);

                if (typed_value >= largest_value || contador_unit == 1)    // Keeping track the largest value.
                    largest_value = typed_value;

                if (typed_value <= smallest_value || contador_unit == 1)   // Keeping track the smallest value.
                    smallest_value = typed_value;
            }

            cout << "To type one floating point number and its unit (m, cm, in, ft):\n\n";
        }

    cout << "\n\nTotal distance (cm) = " << acumulador << "\nTotal values typed = " << contador_unit
         << "\nLargest value (cm) = " << largest_value << "\nSmallest value (cm) = " << smallest_value << "\n\n";

    sort(distances.begin(),distances.end());
    print_vector(distances);
}

int select_unidad(string unidad)                /*Función para seleccionar la unidad.*/
{
    int var_aux;

    if (unidad == "m" || unidad == " m")
        return var_aux = 1;
    if (unidad == "cm" || unidad == " cm")
        return var_aux = 2;
    if (unidad == "in" || unidad == " in")
        return var_aux = 3;
    if (unidad == "ft" || unidad == " ft")
        return var_aux = 4;

    return var_aux = 0;
}

void print_vector(vector <double> values)
{
    cout << "The vector Values are:\n";

    for (int i = 0; i < values.size(); ++i)
        cout << values[i] << "\t";

    cout << "\n\n";
    return;
} 