/*Implement an allocator using the basic allocation functions malloc
() and free(). Get vector as defined by the end of 19.4 to work for a
few simple test cases. Hint: look up "placement new" and "explicit
call of destructor" in a complete C++ reference.*/

#include<iostream>
#include<cstdlib>

#include"runtime_errors.h"

using namespace std;

//--------------------------------------------------------------------

namespace A
{

template<typename T>
class allocator
{

public:
    allocator() {}

    T* allocate(int n);
    void deallocate(T* p);
    void construct(T* p, const T& v);
    void destroy(T* p);
};

//--------------------------------------------------------------------

// Allocator member functions.

template<typename T>
T* allocator<T>::allocate(int n)
{
    if(n <= 0) return nullptr;
    return (T*) malloc(n*sizeof(T));
}

template<typename T>
void allocator<T>::deallocate(T* p)
{
    free(p);
}

template<typename T>
void allocator<T>::construct(T* p, const T& v)
{
    new (p) T(v);
}

template<typename T>
void allocator<T>::destroy(T* p)
{
    p->~T();
}

}

//--------------------------------------------------------------------

namespace v
{ 
template<typename T>
class vector
{
    A::allocator<T> alloc;
    int sz;
    T* elem;
    int space;

public:
    vector() : sz(0), elem{nullptr}, space{0} {}
    explicit vector(int s, T val = T())
             : sz{s}, elem{alloc.allocate(s)}, space{s}
    {
        for(int i=0; i<=sz; ++i) alloc.construct(&elem[i],val);
    }

    vector(const vector&);                  // Copy constructor.
    vector& operator=(const vector&);       // Copy assignment.
  
    vector(vector&&);                       // Move constructor.
    vector& operator=(vector&&);            // Move assignment.

    ~vector() { alloc.deallocate(elem);}    // Destructor. 

    T& operator[](int n){ return elem[n]; } // Checked access.
    const T& operator[](int n) const { return elem[n]; }

    T& at(int n);                           // Unchecked access.
    const T& at(int n) const;

    int size() const{ return sz; }          // The current size.
    int capacity() const { return space; }

    void reserve(int newalloc);               // Growth.
    void push_back(const T& d);

    // resize is placed here because default arguments cannot be added
    // to an out-of-line definition of a member of a class template.
    void resize(int newsize, T val = T())
    {
        reserve(newsize);
        for(int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);
        for(int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
        sz = newsize;
    }
};

//--------------------------------------------------------------------

// Unchecked access.

template<typename T>
T& vector<T>::at(int n)
{
    if(n<0 || sz<=n) error("\n\n\tOut of range\n\t");
    return elem[n];
}

template<typename T>
const T& vector<T>::at(int n) const
{
    if(n<0 || sz<=n) error("\n\n\tOut of range\n\t");
    return elem[n];
}

//--------------------------------------------------------------------

// Copy constructor.

template<typename T>
vector<T>::vector(const vector& arg)
       :sz{arg.sz}, elem{alloc.allocate(arg.sz)}, space{arg.sz}
{
    for(int i=0; i<sz; ++i) alloc.construct(&elem[i],arg[i]);
}

// Copy assignment.

template<typename T>
vector<T>& vector<T>::operator=(const vector& a)
{
    if(this == &a) return *this;       // Self-assignment, no work needed.

    if(a.sz <= space)                  // No need for new allocation.
    {
        for(int i=0; i<a.sz; ++i) alloc.construct(&elem[i],a[i]);
        for(int i=a.sz; i<space; ++i) alloc.destroy(&elem[i]);
        sz = a.sz;
        return *this;
    }

    T* p = alloc.allocate(a.sz);
    for(int i=0; i<a.sz; ++i) alloc.construct(&p[i],a[i]);
    for(int i=0; i<space; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem);
    space = sz = a.sz;
    elem = p;

    return *this;
}


//--------------------------------------------------------------------

// Move constructor.

template<typename T>
vector<T>::vector(vector&& a)
           : sz{a.sz}, elem{a.elem}, space{a.space}
{
    a.space = a.sz = 0;
    a.elem = nullptr;
}

// Move assignment.

template<typename T>
vector<T>& vector<T>::operator=(vector&& a)
{
    cout << "\n\n\tFlag :)\n\t";

    for(int i=0; i<space; ++i) alloc.destroy(&elem[i]);
    elem = a.elem;
    sz = a.sz;
    space = a.space;
    
    a.elem = nullptr;
    a.space = a.sz = 0;

    return *this;
}

//--------------------------------------------------------------------

// Growth.

template<typename T>
void vector<T>::reserve(int newalloc)
{
    if(newalloc <= space) return;
    T* p = alloc.allocate(newalloc);
    for(int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]);
    for(int i=0; i<sz; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem);
    elem = p;
    space = newalloc;
}

template<typename T>
void vector<T>::push_back(const T& val)
{
    if(space == 0) reserve(8);
    else if(sz == space) reserve(2*space);
    alloc.construct(&elem[sz],val);
    ++sz;
}

} // Close namespace "v".

//--------------------------------------------------------------------

// This function checks the Move function.

template<typename T>
v::vector<T> test(int n)
{
    v::vector<int> t{n,n};
    return t;
}

//--------------------------------------------------------------------

int main()
{
    try{  
    // Checking copy.

    cout << "\n\n\tChecking copy.\n\t";

    v::vector<int> t1{10,15};
    t1.push_back(300);
    for(int i=0; i<t1.size(); ++i)
        cout << "\n\t" << t1[i] << "\t";

    cout << "\n\n\t";

    v::vector<int> t2{5,7};
    for(int i=0; i<t2.size(); ++i)
        cout << "\n\t" << t2[i] << "\t";
    
    t2 = t1;
    cout << "\n\n\t";
    for(int i=0; i<t2.size(); ++i)
        cout << "\n\t" << t2[i] << "\t";

    // Checking move.

    cout << "\n\n\tChecking move.\n\t";

    v::vector<int> t3{10,7};
    for(int i=0; i<t3.size(); ++i)
        cout << "\n\t" << t3[i] << "\t";

    t3 = test<int>(5);
    t3.resize(10,88);
    for(int i=0; i<t3.size(); ++i)
        cout << "\n\t" << t3[i] << "\t";

    cout << "\n\n\tUnchecked access.\n\t";
        cout << "\n\t" << t3.at(-1) << "\t";
    }

    catch(runtime_error)
    {
        cerr << "\n\n\truntime_errors\n\t";
        return 1;
    }

    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
        return 1;
    }

    /*A::allocator<int> alloc;
    
    int* test = alloc.allocate(3);
    //cout << "\n\n\t" << &test[0] << '\t' << test[1] << '\t' << test[2] << "\n\t";
    cout << "\n\n\t" << *(test) << '\t' << *(test+1) << '\t' << *(test+2) << "\n\t";
    
    alloc.construct(test,1);
    alloc.construct(test+1,2);
    alloc.construct(test+2,3);
    cout << "\n\n\t" << *(test) << '\t' << *(test+1) << '\t' << *(test+2) << "\n\t";

    alloc.destroy(&test[0]);
    alloc.destroy(&test[1]);
    alloc.destroy(&test[2]);
    cout << "\n\n\t" << *test << '\t' << *(test+1) << '\t' << *(test+2) << "\n\t";

    alloc.deallocate(test);
    cout << "\n\n\t" << *(test) << '\t' << *(test+1) << '\t' << *(test+2) << "\n\t";*/

    return 0;
}

//--------------------------------------------------------------------
