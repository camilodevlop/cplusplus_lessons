/*Design and implement a Money class. Use the 4/5 rounding rule for cents.
Represent a monetary amount as a number of cents in a long int.*/

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Money
{
    public:
        class neg_money{};               // To throw as exception.
        Money()
            : cents(0){}
        Money(long int c, string ccy)
            : cents(c), currency(ccy) {}
        Money(double c, string ccy)
            : cents(round(c)), currency(ccy) {}
        
        // Nonmodifying opetations.
        long int n_cents() const {return cents;}
        string t_currency() const {return currency;}
        
        // Modifying operations.
        void assignment(double);

    private:
        long int cents;                 // Monetary amount as cents.
        string currency;
        long int round(double&);
};

//------------------------------------------------------------------------------

void Money::assignment(double m)
{
    if (m == 0)
        {cents = 0; return;}
    
    if (m > 0)
        {cents = round(m); return;}

    throw neg_money();
}

//------------------------------------------------------------------------------

long int Money::round(double& m)
{
    long int c = m * 1000;
    int dollars = c / 1000;
    int cents = c % 1000;

    if (cents % 10 >= 5)             // Should be rounded up?
    {   
        cents += 10;                   // Add ten cents.
        cents -= (cents % 10);         // Remove last digit;
    }
    else
    {
        if (cents % 10 < 5)          // Should be rounding down?
            cents -= (cents % 10);     // Remove last digit;
    }
    
    cents /= 10;                       // Make cents a factor of 100.
    if (cents >= 100)
    {
        ++dollars;
        cents -= 100;
    }

    c = (dollars * 100) + cents;
    return c;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Money& m)
{
    string ccy;
    double mney;

    is >>  ccy >>  mney;
    
    if(!is)
        return is;
    
    m = Money(mney,ccy);
    return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Money& m)
{
    return os << m.t_currency() << m.n_cents();
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        Money mny;
        cout << "\n\n\tInput the currency and the value (e.g., Dollar 2435.78):\n\n\t";
        cin >> mny;
        cout << "\n\n\t" << mny << "\n\t";

        return 0;

    }
    catch(Money::neg_money)
    {
        cerr << "\n\n\tNegative amounts are not allowed.\n\t";
        return 3;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 2;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\n\t";
        return 3;
    }
    
}

//------------------------------------------------------------------------------
