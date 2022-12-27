/* Modify class Link from 17.9.3 to be a template with the type of
value as the template argument.

Modify the Link class from 17.10.1 to hold a value of a struct God.
struct God should have members of type string: name, mythology,
vehicle, and weapon. Write a print_all() function that list gods with
their attributes one per line. Add a member funtion add_ordered()that
places its new element in its correct lexicographical position.*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

struct God
{
    God(const string& n,const string& m,const string& v,
    const string& w) : name{n}, mythology{m}, vehicle{v}, weapon{w} {}

    string name;
    string mythology;
    string vehicle;
    string weapon;
};

//--------------------------------------------------------------------

template<typename T>
class Link
{
    public:
        T god;

        Link(const T& g, Link* p = nullptr, Link* s = nullptr)
             : god{g}, prev{p}, succ{s} {}

        Link* insert(Link<T>* n);   // Insert n before this object.
        Link* add(Link* n);         // Insert n after this object.
        Link* add_ordered(Link* n); // Insert n alphabetically.
        Link* erase();              // Remove this object from list.
        Link* find(const string& s); // Find s in this list.
        const Link* find(const string& s) const;
        Link* advance(int n) const;  // Move n position in list.
        
        Link* next() const { return succ; }
        Link* previous() const { return prev; }

    private:
        Link* prev;
        Link* succ;
};

//--------------------------------------------------------------------

template<typename T>
Link<T>* Link<T>::insert(Link<T>* n)  // Insert n before p; return n.
{
    if(n == nullptr) return this;
    n->succ = this;             // This object comes after n.
    if(prev) prev->succ = n;
    n->prev = prev;           // This object's pred. becomes n's pred.
    prev = n;               // n becomes this object's predecessor.
    
    return n;
}

//--------------------------------------------------------------------

template<typename T>
Link<T>* Link<T>::add(Link<T>* n)       // Insert n after p; return n.
{
    if(n == nullptr) return this;
    n->prev = this;                     // This object comes before n.
    if(succ) succ->prev = n;
    n->succ = succ;           // This object's succ. becomes n's succ.
    succ = n;                    // n becomes this object's successor.
    
    return n;
}

//--------------------------------------------------------------------

template<typename T>
Link<T>* Link<T>::add_ordered(Link<T>* n)
{
    if(n == nullptr) return this;

    Link<T>* p = this;
    int c = 0;      // this contains the pointer to the first element 
                    // of the list. c helps to change the pointer in
                    // case n becomes the pointer to the first
                    // element.

    // Names of the gods.
    string n1{n->god.name};
    string p1{p->god.name};
    
    // Convertion of names to lowercase.
    for(char& x: n1) x = tolower(x);
    for(char& x: p1) x = tolower(x);

    bool ctrl = true;           // ctrl breaks the loop when the list
                                // has no more elements.
    while(ctrl)
    {
        if(n1 < p1)
        {
            p = p->insert(n);

            if(c) return this;
            else return p;      // Now n is the pointer to the first.
        }

        if(n1 == p1) return this;

        ++c;
        
        if(p->next() != nullptr)
        {
            p = p->next();
            p1 = p->god.name;
            for(char& x: p1) x = tolower(x);
        }
        else
            ctrl = false;
    }

    p->add(n);
    return this;
}

//--------------------------------------------------------------------

template<typename T>
Link<T>* Link<T>::erase()
{
    if(succ) succ->prev = prev;
    if(prev) prev->succ = succ;
    return succ;
}

//--------------------------------------------------------------------

template<typename T>
Link<T>* Link<T>::find(const string& s)
{
    Link* p = this;
    while(p)
    {
        if(p->god.name == s) return p;
            p = p->succ;
    }

    return nullptr;
}

//--------------------------------------------------------------------

template<typename T>
Link<T>* Link<T>::advance(int n) const
{
    Link<T>* p = nullptr;

    if(n==0) p = succ->prev;

    if(n>0)
    {
        p = succ;
        while(--n)
        {
            if(p == nullptr)  return nullptr;
            p = p->succ;
        }
    }

    if(n<0)
    {
        p = prev;
        while(++n)
        {
            if(p == nullptr) return nullptr;
            p = p->prev;
        }
    }

    return p;
}

//--------------------------------------------------------------------

void print_all(Link<God>* p)
{
    while(p)
    {
        cout << "\n\tName: " << p->god.name << "\n\tMythology: "
             << p->god.mythology << "\n\tVehicle: " << p->god.vehicle
             << "\n\tWeapon: " << p->god.weapon << "\n";
        p=p->next();
    }
}

//--------------------------------------------------------------------

int main()
{
    // Gods.

    God thor{"Thor","Norse","Two goats","Hammer"};
    God odin{"Odin","Norse","Eight-legged flying horse","Spear"};
    God freia{"Freia","Norse","A chariot drawn by cats", "Sword"};

    God zeus{"Zeus","Greek","","Lightning"};
    God hera{"Hera","Greek","","Magic"};
    God athena{"Athena","Greek","", "Sword"};
    God ares{"Ares","Greek","", "Sword"};
    God poseidon{"Poseidon","Greek","", "Trident"};

    God ra{"Ra","Egyptian","","Spear"};
    God isis{"Isis","Egyptian","","Dagger"};
    God osiris{"Osiris","Egyptian","","Scythe"};
    God horus{"Horus","Egyptian","","Spear"};

    // Gods list.

    Link<God>* gods = new Link{odin};
    //gods = gods->insert(new Link{odin});
    gods = gods->insert(new Link{freia});
    //gods = gods->insert(new Link{zeus});
    gods = gods->insert(new Link{hera});
    gods = gods->insert(new Link{athena});
    gods = gods->insert(new Link{poseidon});
    gods = gods->insert(new Link{ares});
    gods = gods->insert(new Link{poseidon});
    //gods = gods->insert(new Link{ra});
    gods = gods->insert(new Link{isis});
    gods = gods->insert(new Link{osiris});
    gods = gods->insert(new Link{horus});

    cout << "\n\n\tGods list\n";
    print_all(gods);
    cout << "\n";
   
    // Mythologies lists.

    Link<God>* norse_gods = new Link{thor};
    Link<God>* greek_gods = new Link{zeus};
    Link<God>* egyptian_gods = new Link{ra};

    Link<God>* aux = nullptr;
    while(gods)
    {
        aux = gods->next();
        gods->erase();

        if(gods->god.mythology == "Norse")
            norse_gods = norse_gods->add_ordered(gods);
        if(gods->god.mythology == "Greek")
            greek_gods = greek_gods->add_ordered(gods);
        if(gods->god.mythology == "Egyptian")
            egyptian_gods = egyptian_gods->add_ordered(gods);

        gods = aux;
    }

    // Results.
    
    cout << "\n\n\tGods list\n";
    print_all(gods);
    cout << "\n";

    cout << "\n\n\tNorse gods list\n";
    print_all(norse_gods);
    cout << "\n";

    cout << "\n\n\tGreek gods list\n";
    print_all(greek_gods);
    cout << "\n";

    cout << "\n\n\tEgyptian gods list\n";
    print_all(egyptian_gods);
    cout << "\n";

    return 0;
}

//--------------------------------------------------------------------
