/*Design and implement a rational number class, Rational. Member values numerator and denominator.
Provide assignment, addition, substraction, multiplication, division, and equality operators.*/

//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class Rational
{
    public:
        class den_zero{};           // To throw as exception.
        
        Rational()                  // Constructor 0 / 1.
            :num(0),den(1){}

        // Nonmofifying operations.
        int numerator() const {return num;}
        int denominator() const {return den;}
        
        // Modifying operations.
        void assignment(int,int);

    private:
        int num;                    // Numerator.
        int den;                    // Denominator.
};

//------------------------------------------------------------------------------
void Rational::assignment(int n,int d)
{
    d != 0 ? den = d : throw den_zero();
    num = n;
}

//------------------------------------------------------------------------------
// Least Common Multiple (LCM).

int lcm(int a,int b)
{
    if (a == 0 || b == 0)
        return 0;

    //--------------------
    
    int i = 2;                      // Varying the divider.
    int mult_a = 1;                 // Saving the product of the multiples.
    int mult_b = 1;
    
    while (a > 1 || b > 1)
    {
        while (a % i == 0 && b % i == 0)        // Common multiples.
        {
            mult_a *= i;
            a /= i;
            b /= i;
        }
        
        while (a % i == 0)
        {
            mult_a *= i;
            a /= i;
        }

        while (b % i == 0)
        {
            mult_b *= i;
            b /= i;
        }
        
        ++i;
    }
    
    return mult_a * mult_b;
}

//------------------------------------------------------------------------------

Rational addition(const Rational& rat_1,const Rational& rat_2)
{
    Rational sum;
    
    // Denominator of the sum is the lcm of the arguments.
    int d_sum = lcm(rat_1.denominator(),rat_2.denominator());
    
    // Calculating the numerator of the sum.
    int n_sum = (d_sum / rat_1.denominator() * rat_1.numerator())
            + (d_sum / rat_2.denominator() * rat_2.numerator());
    
    sum.assignment(n_sum,d_sum);

    return sum;
}

//------------------------------------------------------------------------------

Rational subtraction(const Rational& rat_1,const Rational& rat_2)
{
    Rational sub;
    
    // Denominator of the subs is the lcm of the arguments.
    int d_sub = lcm(rat_1.denominator(),rat_2.denominator());
    
    // Calculating the numerator of the subs.
    int n_sub = (d_sub / rat_1.denominator() * rat_1.numerator())
            - (d_sub / rat_2.denominator() * rat_2.numerator());
    
    sub.assignment(n_sub,d_sub);

    return sub;
}

//------------------------------------------------------------------------------

Rational multiplication(const Rational& rat_1,const Rational& rat_2)
{
    Rational mul;
    
    // Calculating the Numerator
    int n_mul = rat_1.numerator() * rat_2.numerator();

    // Calculating the Denominator.
    int d_mul = rat_1.denominator() * rat_2.denominator();
    
    mul.assignment(n_mul,d_mul);

    return mul;
}

//------------------------------------------------------------------------------

Rational division(const Rational& rat_1,const Rational& rat_2)
{
    Rational div;
    
    if (rat_2.numerator() == 0)
        error("\n\n\tError: División by zero.\n\t");
    
    // Calculating the Numerator
    int n_div = rat_1.numerator() * rat_2.denominator();

    // Calculating the Denominator.
    int d_div = rat_1.denominator() * rat_2.numerator();
    
    div.assignment(n_div,d_div);

    return div;
}

//------------------------------------------------------------------------------

// Equality operators.

bool operator==(const Rational& rat_1, const Rational& rat_2)
{
    return (rat_1.numerator() == rat_2.numerator())
        && (rat_1.denominator() == rat_2.denominator());
}

bool operator!=(const Rational& rat_1, const Rational& rat_2)
{
    return !(rat_1 == rat_2);
}

//------------------------------------------------------------------------------

double conv2double(const Rational& rat)
{
    return double(rat.numerator()) / rat.denominator();
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        Rational rat_num, rat_num2, rat_num3, suma, resta, mult, divi;
        
        rat_num.assignment(3,5);
        rat_num2.assignment(3,5);
        rat_num3.assignment(6,4);

        suma = addition(rat_num,rat_num2);
        resta = subtraction(rat_num,rat_num2);
        mult = multiplication(rat_num,rat_num2);
        divi = division(rat_num,rat_num3);

        cout << "\n\n\tNum = " << suma.numerator() << "\tDen = " << suma.denominator() << "\n\n\t";
        cout << "\n\n\tNum = " << resta.numerator() << "\tDen = " << resta.denominator() << "\n\n\t";
        cout << "\n\n\tNum = " << mult.numerator() << "\tDen = " << mult.denominator() << "\n\n\t";
        cout << "\n\n\tNum = " << divi.numerator() << "\tDen = " << divi.denominator() << "\n\n\t";

        if(rat_num == rat_num2)
            cout << "\n\n\tRational numbers are equal.\n\n\t";
        
        if (rat_num != rat_num3)
            cout << "\n\n\tRational numbers are different.\n\n\t";

        cout << "\n\n\tConv2double\n\t" << rat_num3.numerator() << " / "
             << rat_num3.denominator() << " = " << conv2double(rat_num3);
        

        return 0;    
    }
    catch(Rational::den_zero)
    {
        cerr << "\n\n\tDenominator zero. Rational number is not defined.\n\n\t";
        return 1;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 2;
    }
    catch(...)
    {
         cerr << "\n\n\tSomething is wrong." << "\n\t";
         return 3;
    }
}

//------------------------------------------------------------------------------