/*Complete the "list of gods" example from 17.10.1 and run it using a
singly-linked list.*/

#include<iostream>

using namespace std;

//--------------------------------------------------------------------

class Link
{
    public:
        string value;

        Link(const string& v, Link* s = nullptr)
             : value{v}, succ{s} {}
        
        Link* insert(Link* p, Link* n);// Insert n before this object.
        Link* add(Link* n);           // Insert n after this object.
        Link* erase(Link* n);        // Remove this object from list.
        Link* find(const string& s); // Find s in this list.
        Link* advance(Link* p, int n) const;  // Move n position in list.
        
        Link* next() const { return succ; }

    private:
        Link* succ;
};

//--------------------------------------------------------------------

// Link* p points to the first element.

Link* Link::insert(Link* p, Link* n)        // Insert n before this. 
{
    if(n == nullptr) return this;
    if(p == this)
    {
        n->succ = this;
        return n;
    }

    while(p->next())
    {
        if(p->next() == this)
        {
           p->succ = n;
           n->succ = this;
        }
        p = p->next();
    }
    
    return n;
}

//--------------------------------------------------------------------

Link* Link::add(Link* n)        // Insert n after this; return n.
{
    if(n == nullptr) return this;

    if(succ) n->succ = succ;
    succ = n;                   // n becomes this object's successor.
    
    return n;
}

//--------------------------------------------------------------------

Link* Link::erase(Link* n)          // n points to the first element.
{
    if(n == nullptr) return this;
    if(n == this)
    {
        n = next();                 // Or n = succ;
        succ = nullptr;
        return n;
    }

    while(n->next())
    {
        if(n->next() == this)
        {
            n->succ = succ;
            succ = nullptr;
            return n;
        }
        n = n->next();
    }

    return this;                    // this element was not found.
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

Link* Link::advance(Link* p, int n) const
{
    if(n==0) return p;

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
        cerr << "\n\n\tError: this option is not available.\n\t";
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
    // Test add() function.

    /*Link* norse_gods = new Link{"Loki"};
    Link* tmp = norse_gods;

    norse_gods = norse_gods->add(new Link{"Thor"});
    norse_gods = norse_gods->add(new Link{"Odin"});
    norse_gods = norse_gods->add(new Link{"Freia"});

    print_all(tmp);
    cout << "\n";

    norse_gods = tmp;
    norse_gods = norse_gods->add(new Link{"Hela"}); // Hela is in
                                                    // norse_gods.

    print_all(tmp);
    cout << "\n";

    //norse_gods->erase(tmp);     // It erases Hela.
    //tmp->erase(tmp);            // It erases Loki.

    Link *tst = tmp->find("Odin");
    tst->erase(tmp);              // It erases Odin.

    print_all(tmp);
    cout << "\n"; */


    // Test insert() function.
    
    Link* norse_gods = new Link{"Loki"};
    norse_gods = norse_gods->insert(norse_gods, new Link{"Thor"});
    norse_gods = norse_gods->insert(norse_gods, new Link{"Odin"});
    norse_gods = norse_gods->insert(norse_gods, new Link{"Freia"});

    print_all(norse_gods);
    cout << "\n";
    
    Link* p2 = norse_gods->find("Odin");
    p2->insert(norse_gods, new Link{"Hela"});
    
    print_all(norse_gods);
    cout << "\n";

    // Test advance() function.

    cout << "\n\t" << norse_gods->advance(norse_gods,0)->value << "\n\t";

    return 0;
}

//--------------------------------------------------------------------
