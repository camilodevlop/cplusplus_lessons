/*Design and implement a counted_ptr<T> that is a type that holds a
pointer to an object of type T and a pointer to a "use count" (an int)
shared by all counted pointers to the same object of type T.*/

#include<iostream>
#include<vector>

using namespace std;

//--------------------------------------------------------------------

template<typename T>
struct counted_ptr
{
    // Constructors and destructor.

    explicit counted_ptr(T val = T())
             : elem{new T[1]}, use_count{new int{1}}
    {
        elem[0] = val;
        cout << "\n\tcounted_ptr constructor:" << *use_count;
    }

    counted_ptr(counted_ptr& cp);
    ~counted_ptr();

    // Reading elem and use_count.

    T* obj_ptr() const { return elem; }
    int* use_count_ptr() const { return use_count; }
    
    // Operators * and ->.

    T operator*();
    counted_ptr<T>* operator->();

private:
    T* elem;
    int* use_count;
};

// Secondary constructor: it adds other counter_ptr objects that
// point to T.

template<typename T>
counted_ptr<T>::counted_ptr(counted_ptr& cp)
              : elem{cp->obj_ptr()}, use_count{cp->use_count_ptr()}
{
    ++(*use_count);
    cout << "\n\tcounted_ptr constructor:" << *use_count;
}

// Destructor.

template<typename T>
counted_ptr<T>::~counted_ptr()
{
    --(*use_count);
    cout << "\n\tcounted_ptr destructor:" << *use_count << "\n\t";

    if(*use_count == 0)
    {
        delete[] elem;
        cout << "\n\n\tuse_count = 0 - T object deleted.\n\t";
    }
}

// Operators * and ->.

template<typename T>
T counted_ptr<T>::operator*()
{
    return *elem;
}

template<typename T>
counted_ptr<T>* counted_ptr<T>::operator->()
{
    return this;
}

//--------------------------------------------------------------------

template<typename T>
void print_counted_ptr(counted_ptr<T> cp)
{
    cout << "\n\tcptr elem: " << cp.obj_ptr()
         << "\n\tcptr *elem: " << *cp << "\n\tcptr use count: "
         << *(cp->use_count_ptr()) << "\n\t";
}

//--------------------------------------------------------------------

int main()
{
    vector<counted_ptr<int>> vcptr(5);

    counted_ptr cptr1{vcptr[2]};
    cout << "\n\tcptr1 elem: " << cptr1.obj_ptr()
         << "\n\tcptr1 *elem: " << *cptr1 << "\n\tcptr1 use count: "
         << *(cptr1->use_count_ptr()) << "\n\t";

    print_counted_ptr(cptr1);

    counted_ptr cptr2{cptr1};
    cout << "\n\tcptr2 elem: " << cptr2.obj_ptr()
         << "\n\tcptr2 *elem: " << *cptr2 << "\n\tcptr2 use count: "
         << *(cptr2->use_count_ptr()) << "\n\t";

    return 0;
}

//--------------------------------------------------------------------
