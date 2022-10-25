/*Write a program where using base classes and members where you defi-
ne the constructors and destructors to output a line of information.
See how their constructors and destructors are called.*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

class A
{
    public:
        virtual ~A(){}                  // Virtual desctructor. 
        string str() const {return s;}
        int intgr() const {return n;}
    
    protected:
        A() : s{"Class A String"}, n{1} {}

    private:
        string s;
        int n;
};

class A1 : public A
{
    public:
        A1() : sA1{"Class A1 string"}, elem{new double[]{0,1,2,3,4}}
            {cout << "\n\n\tAn object of type A1 was constructed.\n\t";}
        
        string strA1() const {return sA1;}
    
        ~A1() override;        // Overriding the virtual constructor.

    private:
        string sA1;
        double* elem;
};

A1::~A1() 
{
    cout << "Free-store deallocation: deleted values:\n\t";
    for(int i=0; i<5; ++i) 
        cout << elem[i] << '\t';

    delete[] elem;          // Deallocation.
    cout << "\n\tAn object of type A1 was destroyed.\n\t";
}

//--------------------------------------------------------------------

struct B
{
    public:
        virtual void f() = 0;
        virtual ~B() {};

        B() : s{"Class B String"}, n{2} {}

        string str() const {return s;}
        int intgr() const {return n;}

    private:
        string s;
        int n;
};

class B1 : public B
{
    public:
        void f() override {cout << "\n\n\tf() Overriding\n\n\t";}
        B1() : sB1{"Class B1 string"}, p{new int{1}}
            {cout << "\n\n\tAn object of type B1 was constructed.\n\t";}
    
        string strB1() const {return sB1;}

        ~B1() override;

    private:
        string sB1;
        int* p;
};

B1::~B1()
{
    cout << "Free-store deallocation: deleted value:\n\t";
    cout << *p << '\t';
   
    delete p;          // Deallocation.
    cout << "\n\tAn object of type B1 was destroyed.\n\t";
  
}

//--------------------------------------------------------------------

int main()
{
    // The object "a" is only defined inside the block.
    {
        A1 a;
        cout << "\n\tstr()= " << a.str()
             << "\n\tintgr()= " << a.intgr() << "\t(Class A int.)"
             <<  "\n\tstrA1()= " << a.strA1() << "\n\n\t";
    }
    
    // The object "b" is only defined inside the block.
    {
        B1 b;
        cout << "\n\tstr()= " << b.str()
             << "\n\tintgr()= " << b.intgr() << "\t(Class B int.)"
             <<  "\n\tstrA1()= " << b.strB1() << "\n\n\t";
        b.f();
    }

    return 0;
}

//--------------------------------------------------------------------
