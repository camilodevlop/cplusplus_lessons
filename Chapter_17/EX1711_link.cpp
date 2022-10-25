/*Complete the "list of gods" example from 17.10.1 and run it.*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

class Link
{
    public:
        string value;

        Link(const string& v, Link* p = nullptr, Link* s = nullptr)
             : value{v}, prev{p}, succ{s} {}
        
        Link* insert(Link* n);      // Insert n before this object.
        Link* add(Link* n);         // Insert n after this object.
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

Link* Link::insert(Link* n)     // Insert n before p; return n.
{
    if(n == nullptr) return this;
    n->succ = this;             // This object comes after n.
    if(prev) prev->succ = n;
    n->prev = prev;         // This object's pred. becomes n's pred.
    prev = n;               // n becomes this object's predecessor.
    
    return n;
}

//--------------------------------------------------------------------

Link* Link::add(Link* n)        // Insert n after p; return n.
{
    if(n == nullptr) return this;
    n->prev = this;             // This object comes before n.
    if(succ) succ->prev = n;
    n->succ = succ;         // This object's succ. becomes n's succ.
    succ = n;               // n becomes this object's successor.
    
    return n;
}

//--------------------------------------------------------------------

Link* Link::erase()
{
    if(this==nullptr) return nullptr;
    if(succ) succ->prev = prev;
    if(prev) prev->succ = succ;
    return succ;
}

//--------------------------------------------------------------------

Link* Link::find(const string& s)
{
    Link* p = this;
    while(p)
    {
        if(p->value == s) return p;
            p = p->succ;
    }

    return nullptr;
}

//--------------------------------------------------------------------

Link* Link::advance(int n) const
{
    Link* p = nullptr;

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

void print_all(Link* p)
{
    cout << "\n\n\t{";
    while(p)
    {
        cout << p->value;
        if(p=p->next()) cout << ", ";
    }
    cout << "}";
}

//--------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* p = greek_gods->find("Mars");
    if(p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if(p2)
    {
        if(p2==norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }


    print_all(norse_gods);
    cout << "\n";

    print_all(greek_gods);
    cout << '\n';

    Link* tst = norse_gods->find("Thor");
    if(tst) cout << "\n\n\t" << tst->value << "\n\n\t";
    
    Link* adv = (norse_gods->next())->advance(1);
    cout << "\n\n\t" << adv->value << "\n\n\t";

    return 0;
}

//--------------------------------------------------------------------
