/*What cases do you need to consider (and test) if we want to convince
ourselves that this resize() is correct?*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------

namespace v
{

class vector
{
    int sz;         // The size.
    double* elem;   // Pointers to the elements (or 0).
    int space;      // Number of elements plus number of free slots.
    
public:
    // Constructors.
    vector() : sz{0}, elem{nullptr}, space{0}{}
    explicit vector(int s) : sz{s}, elem{new double[sz]}, space{s}
    {
        for(int i=0; i<sz; ++i) elem[i] = 0;
    }
    
    vector(const v::vector&);               // Copy constructor.
    vector& operator=(const vector&);       // Copy assignment.

    vector(vector&&);                     // Move constructor.
    vector& operator=(vector&&);          // Move assignment. 
    
    ~vector() { delete[] elem; }         // Destructor. 

    double& operator[](int n){ return elem[n]; }
    const double& operator[](int n)const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void resize(int newsize);
    void push_back(double d);
    void reserve(int newalloc);
};

//--------------------------------------------------------------------

// Copy constructor.

vector::vector(const v::vector& arg)
       :sz{arg.sz}, elem{new double[arg.sz]}
{
    copy(&arg[0],&arg[sz],elem);
}

// Copy assignment.

vector& vector::operator=(const vector& a)
{
    double* p = new double[a.sz];
    copy(a.elem,a.elem+a.sz,p);
    delete[] elem;
    elem = p;
    sz = a.sz;

    return *this;
}

//--------------------------------------------------------------------

// Move constructor.

vector::vector(vector&& a) : sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

// Move assignment.

vector& vector::operator=(vector&& a)
{
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;

    return *this;
}

//--------------------------------------------------------------------

void vector::reserve(int newalloc)
{
    if(newalloc <= space) return;        // Never decrease allocation.
    double* p = new double[newalloc];
    for(int i=0; i<sz; ++i) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

//--------------------------------------------------------------------

void vector::resize(int newsize)
{
    reserve(newsize);
    for(int i=0; i<newsize; ++i) elem[i] = 0;
    sz = newsize;
}

//--------------------------------------------------------------------

void vector::push_back(double d)
{
    if(space == 0)
        reserve(8);
    else if(sz == space)
        reserve(2*space);

    elem[sz] = d;
    ++sz;
}

//--------------------------------------------------------------------

}       // End of namespace "v";

//--------------------------------------------------------------------

int main()
{
    v::vector t1{10};
    t1[9] = 77;

    cout << "\n\n";
    for(int i=0; i<t1.size(); ++i)
        cout << "\t" << t1[i];
   
    cout << "\n\n\t" << t1.size() << "\n\t";
    
    t1.resize(15);
    for(int i=0; i<t1.size(); ++i)
        cout << "\t" << t1[i];

    cout << "\n\n\t" << t1.size() << "\n\t";

    t1.push_back(5.6);
    for(int i=0; i<t1.size(); ++i)
        cout << "\t" << t1[i];

    cout << "\n\n\t" << t1.size() << "\n\t";


    /*v::vector t2{5};
    t2[3] = 99;
    for(int i=0; i<t2.size(); ++i)
        cout << "\t" << t2[i];


    t2 = t1; 
    for(int i=0; i<t2.size(); ++i)
        cout << "\t" << t2[i];*/

    return 0;
}
