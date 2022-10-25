/*The game called "Bulls and Cows" is implemented in this program. The program compares a sequence of four letters.
If there is a letter and position match, the program prints Bull. The program prints Cow if there are no matches.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "std_lib_facilities.h"

using namespace std;
using u32 = uint_least32_t;
using engine = std::mt19937;

//------------------------------------------------------------------------------
class Random_vector
{
public:
    void sequence_creator();
    vector<char> sequence;
};
//------------------------------------------------------------------------------
/*It creates a sequence of four random characters and saves the sequence in 
a vector.*/
void Random_vector::sequence_creator()
{
    random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);                                 // The range was set to convert int to char according
    uniform_int_distribution<u32> distribute(97,122);       //  to the ASCII table.

    for (int i = 0; i < 4; i++)
    {
        sequence.push_back(distribute (generator));         //Internal convertion from 'int' to 'char'.
        cout << sequence[i] << '\n';
    }
}
//------------------------------------------------------------------------------
Random_vector sqce;

//------------------------------------------------------------------------------
// Classification of the entered characters. 
void sequence(int seq_elements)
{
    char c, s;
    
    cin >> c;                   // It deals with characters..
    cin >> s;                   // It deals with ',' and '.'.
    int index = sqce.sequence.size() - seq_elements;

    switch (s)
    {
    case ',': case '.':
        
        if (sqce.sequence[index] == c)              // System char matches with user char.
            cout << sqce.sequence[index] << "\t" << c << "\t\t1 Bull and 1 Cow.\n";
        else
            cout << sqce.sequence[index] << "\t" << c << "\t\tNo match.\n";
        
        if (seq_elements != 1)                      // Ends the review of the sequence.
        {
            sequence(seq_elements - 1);
            return;
        }
        else
            return;
    
    default:
        error("\n\n\tSomething is bad!\n");
    }
}
//------------------------------------------------------------------------------
int main()
{
    try
    {
        sqce.sequence_creator();

        cout << "\n\tEnter four characters in the form X,X,X,X. (e.g., a,g,f,n.)\n\tDon't forget the point because it ends the sequence.";
        cout << "\n\n\tWhen an entered character matches the system sequence,\n\t1 Bull and 1 Cow is printed.\n\n";
        
        sequence(4);
        cout << "\nSystem\tEntered\n";
        return 0;
    }
    catch(exception& e)
    {
        cerr << "\n\tError: "<< e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\tOops: unknown exception!\n";
        return 2;
    }
}