/*Modify reserve to use the vector_base solution.*/

#include<iostream>
#include<algorithm>

using namespace std;

//--------------------------------------------------------------------

namespace v
{ 

// vector_base is used for manage memory.

template<typename T,typename A>
struct vector_base
{
    A alloc;
    T* elem;
    int sz;
    int space;                      // Ammount of allocated space.

    vector_base(const A& a, int n)
        : alloc{a}, elem{alloc.allocate(n)}, sz{n}, space{n} {} 

    ~vector_base() {}
};

//--------------------------------------------------------------------

template<typename T, typename A = allocator<T>>
class vector : private vector_base<T,A>
{
    A alloc;
    int sz;
    T* elem;
    int space;

public:
    vector() : sz(0), elem{nullptr}, space{0} {}
    explicit vector(int s, T val = T()) : sz{s},
        elem{alloc.allocate(s)}, space{s}, vector_base<T,A>{alloc,s}
    {
        for(int i=0; i<=sz; ++i) alloc.construct(&elem[i],val);
    }

    vector(const vector&);                  // Copy constructor.
    vector& operator=(const vector&);       // Copy assignment.
  
    vector(vector&&);                       // Move constructor.
    vector& operator=(vector&&);             // Move assignment.

    ~vector() { delete[] elem; }            // Destructor. 

    T& operator[](int n){ return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

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

// Copy constructor.

template<typename T, typename A>
vector<T,A>::vector(const vector& arg) : sz{arg.sz}
             ,elem{alloc.allocate(arg.sz)}, space{arg.sz}
             , vector_base<T,A>{alloc,arg.capacity()}
{
    for(int i=0; i<sz; ++i) alloc.construct(&elem[i],arg[i]);
}

// Copy assignment.

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& a)
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
    alloc.deallocate(elem,space);
    space = sz = a.sz;
    elem = p;

    return *this;
}


//--------------------------------------------------------------------

// Move constructor.

template<typename T, typename A>
vector<T,A>::vector(vector&& a) : sz{a.sz}, elem{a.elem}
             , space{a.space}, vector_base<T,A>{alloc,a.space}
{
    a.space = a.sz = 0;
    a.elem = nullptr;
}

// Move assignment.

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& a)
{
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

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if(newalloc <= capacity()) return;
    vector_base<T,A> b{this->alloc,newalloc};
    uninitialized_copy(this->elem,this->elem+size(),b.elem);
    for(int i=0; i<size(); ++i)
        this->alloc.destroy(&this->elem[i]);

    elem = b.elem;
    space = b.space;
    
    b.elem = nullptr;
    b.space = b.sz = 0;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
    if(space == 0) reserve(8);
    else if(sz == space) reserve(2*space);
    this->alloc.construct(&this->elem[sz],val);
    ++sz;
}


} // Close namespace "v".

//--------------------------------------------------------------------

// This function checks the Move function.

template<typename T, typename A>
v::vector<T,A> test(int n)
{
    v::vector<int> t{n,n};
    return t;
}

//--------------------------------------------------------------------

int main()
{
    // Checking copy and push_back.

    cout << "\n\n\tChecking copy and push_back.\n\t";
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

    cout << "\n\n\tChecking move and resize.\n\t";

    v::vector<int> t3{10,7};
    for(int i=0; i<t3.size(); ++i)
        cout << "\n\t" << t3[i] << "\t";

    t3 = test<int,allocator<int>>(5);          
    t3.resize(10,77);
    for(int i=0; i<t3.size(); ++i)
        cout << "\n\t" << t3[i] << "\t";

    return 0;
}    

//--------------------------------------------------------------------
