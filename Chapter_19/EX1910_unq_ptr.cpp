/*Implement a simple unique_ptr supporting only a constructor. des-
tructor, ->, *, and release(). */

#include<iostream>
//#include<memory>

using namespace std;

//--------------------------------------------------------------------

template<typename T>
class Unique_ptr
{
    T* elem;

    public:
       // Constructor - destructor. 
       explicit Unique_ptr(T* el) : elem{el} {}
       ~Unique_ptr() { delete[] elem;}

       // releases function. 
       T* release(){ T* aux = elem; elem = nullptr; return aux; }

       // Operators * and ->.
       T operator*();
       Unique_ptr<T>* operator->();

       T* address() { return elem; }

       // Copy prevention.
       Unique_ptr(const Unique_ptr&) = delete;
       Unique_ptr& operator=(const Unique_ptr&) = delete;
};

template<typename T>
T Unique_ptr<T>::operator*()
{
    return *elem;
}

template<typename T>
Unique_ptr<T>* Unique_ptr<T>::operator->()
{
    return this;
}

//--------------------------------------------------------------------

int main()
{
    Unique_ptr<double> p{new double{10}};
    cout << "\n\n\tAddress: " << p->address() << "\tValue: "
         << (*p) << "\n\t";

    // Copy prevention example.
    /*Unique_ptr<double> p2{p};
    cout << "\n\n\tAddress: " << p2->address() << "\tValue: "
         << (*p2) << "\n\t";*/

    return 0;
}

//--------------------------------------------------------------------
