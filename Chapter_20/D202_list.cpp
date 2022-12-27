/*Representation of the standard library list. This representation has
the operations we have for vector ( except subscripting ), insert, e-
rase and iterators.*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

template<typename Elem>
struct Link
{
    Link* prev;         // Previous link.
    Link* succ;         // Successor (next) link.
    Elem val;
};

//--------------------------------------------------------------------

template<typename Elem>
class list
{
    Link<Elem>* first;
    Link<Elem>* last;

public:
    class iterator;     // Member type: iterator.
    iterator begin();   // iterator to first element.
    iterator end();     // iterator to one beyond last element.

    iterator insert(iterator p, const Elem& v); // Insert v after p.
    iterator erase(iterator p);     // Remove p from the list.
    
    void push_back(const Elem& v);      // Insert v at end.
    void push_front(const Elem& v);     // Insert v at front.
    void pop_front();   // Remove the first element.
    void pop_back();    // Remove the last element.

    Elem& front();      // The first element.
    Elem& back();       // The last element.
};

template<typename Elem>
class list<Elem>::iterator
{
    Link<Elem>* curr;       // Current link.

public:
    iterator(Link<Elem>* p) : curr{p}{}

    iterator& operator++(){ curr = curr->succ; return *this; }
    iterator& operator--(){ curr = curr->prev; return *this; }
    Elem& operator*(){ return curr->val; } // Get value (dereference.)

    bool operator==(const iterator& b){ return curr == b.curr; }
    bool operator!=(const iterator& b){ return curr != b.curr; }

};

//--------------------------------------------------------------------

int main()
{

    return 0;
}


//--------------------------------------------------------------------
