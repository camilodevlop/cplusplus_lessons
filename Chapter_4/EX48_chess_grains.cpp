/*One grain of rice for the first square, 2 for the second, 4 for the third, and so on.
Print the secuence and obverve how many squares are required to give the inventor 1000
grains of rice, 1000000, and 1000.000.000.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int current_grain = 1;          // Number of grains for the actual chess square.
int sum_grains = 0;             // Sum of the total grains.

int main()
{
    cout << "\n\nSquare\t\tCurrent square grains\t\tTotal grains\n\n";
    for(int sq = 1; sq <= 5000; ++sq)
    {
        sum_grains += current_grain;
        cout << sq << "\t\t" << current_grain << "\t\t\t\t" << sum_grains << "\n";
        current_grain *= 2;
    }
    return 0;
}