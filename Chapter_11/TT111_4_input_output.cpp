/*This program implements the test proposed in chapter 11 These same exercises are
proposed in the Drill section..

1. Output your birth year in decimal, hexadecimal, and octal form. Now output your
age.
2. Complete the code of Section 11.2.2 to make it into a program.
3. Print the number 1234567.89 three times. Fist using default floats, then fixed,
the scientific.
4. Make a simple table including the last name, first name, telephone number, and
email address (Five subjects). 
*/

#include <iostream>
#include <vector>
#include <iomanip>              // Required to use setw().

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

int main ()
{
    // Try this 1.
    
    cout << "\n\n\t" << 1987 << "\tBirth year\n\t"
         << hex << 1987 << "\tHexadecimal\n\t"
         << oct << 1987 << "\tOctal\n\t"
         << 35 << "\tAge\n\t";

    
    // Try this 2.

    int a, b, c, d;
    
    /*cout << "\n\n\tInput four integer numbers:\n\t";
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << dec << a << '\t' << b << '\t' << c << '\t' << d << "\n\n\n\t";*/

    // Try this 3.

    cout << "Testing floating-point output\n\n\t"
         << 1234567.89 << "\tdefaultfloat\n\t"
         << fixed << 1234567.89 << "\tfixed\n\t"
         << scientific << 1234567.89 << "\tscientific\n\t";

    // Try this 4.

    int s = 25;                            // number of reserved spaces.
    
    cout << "\n\n\tPersonal information table.\n\n\t"
         << setw(25) << "Last name" << setw(25) << "\tFirst name" << setw(25)
         << "\tTelephone number" << setw(40) << "\tEmail address\n\n\t";

    cout << setw(25) << "Castillo" << setw(25) << "Camilo" << setw(30)
         << "3016594535" << setw(37) << "cacastilloben@unal.edu.co" << "\n\t";

    cout << setw(25) << "Castillo" << setw(25) << "Lina" << setw(30)
         << "3016594535" << setw(37) << "licastilloben@unal.edu.co" << "\n\t";

    cout << setw(25) << "Castillo" << setw(25) << "Victor" << setw(30)
         << "3016594535" << setw(37) << "vicastillodo@unal.edu.co" << "\n\t";

    cout << setw(25) << "Benavides" << setw(25) << "Cordula" << setw(30)
         << "3016594535" << setw(37) << "cobenavidesas@unal.edu.co" << "\n\t";

    cout << setw(25) << "Garcia" << setw(25) << "Daniela" << setw(30)
         << "3016594535" << setw(37) << "dagarciama@unal.edu.co" << "\n\n\n\t";

    return 0;
}

//------------------------------------------------------------------------------
