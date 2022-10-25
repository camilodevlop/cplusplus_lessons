/* 1. Define a class B1 with a virtual function vf() and a non-virtual funtion
 f(). Implement each function to output its name (e.g., B1::vf()).
 
2. Derive a class D1 from B1 and override vf().

3. Define a reference to B1 (a B1&) and initialize that to the D1 object you
just defined.

4. Define a function called f() for D1 and repeat 1-3.

5. Add a pure virtual function called pvt() to B1. Explain the result.

6. Define a class D2 derived from D1 and override pvf() in D2.

7. ... 

*/

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class B1
{
    public:
        virtual void pvf() = 0;      // 4.
        virtual void vf() const {cout << "\n\n\tB1::vf()";}
        void f() const {cout << "\n\n\tB1::f()\n\t";}
};

//------------------------------------------------------------------------------

struct D1 : B1
{
    void pvf() override{cout << "\n\n\tD1::pvf()\n\t";}             // 4.
    void vf() const override{cout << "\n\n\tD1::vf()";}
    void f() const {cout << "\n\n\tD1::f()\n\t";}
};

//------------------------------------------------------------------------------

struct D2 : D1
{
    void pvf() override{cout << "\n\n\tD2::pvf()\n\t";}
};

//------------------------------------------------------------------------------

class B2
{
    public:
        virtual void pvf() = 0;
};

//------------------------------------------------------------------------------

struct D21 : B2
{
    void pvf() override{cout << "\n\n\tD21::pvf()\n\t";}
    string data{"\n\n\tString D21\n\t"};
};

//------------------------------------------------------------------------------

struct D22 : B2
{
    void pvf() override{cout << "\n\n\tD22::pvf()\n\t";}
    int n{7};
};

//------------------------------------------------------------------------------

void drill_func(B2& b2)
{
    b2.pvf();
    return;
}

//------------------------------------------------------------------------------

int main()
{
    /*B1 b;
    b.vf();
    b.f();
    //b.pvf();                // 4.*/

    D1 d;
    d.vf();
    d.f();                  // Prints "D1::f()".
    d.pvf();                // 4.

    /*B1& br{d};
    br.vf();
    br.f();*/

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    /*B1& b1{d2};              // Uses the reference to the derived D1 object.
    b1.vf();
    b1.f();                 // Prints "B1::f()".
    b1.pvf();               // 4.*/
    
    D21 d21;
    D22 d22;
    drill_func(d21);
    drill_func(d22);

    return 0;
}

//------------------------------------------------------------------------------
