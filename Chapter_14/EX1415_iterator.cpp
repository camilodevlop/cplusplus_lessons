/* Define a class Iterator with a pure virtual function next() that returns a
double*. Now derive Vector_iterator and List_iterator from Iterator so that
next() for a Vector_iterator yields a pointer to the next element of
vector<double> and List_iterator does the same for a list<double>. */

#include<iostream>
#include<vector>
#include<list>

using namespace std;

//------------------------------------------------------------------------------

class Iterator_d
{
    public:
        virtual double* next()=0;
};

//------------------------------------------------------------------------------

// In this class the memory addresses of the vector elements are returned.

struct Vector_iterator : Iterator_d
{
    Vector_iterator(vector<double> vvdd) : vd{vvdd} {}

    double* next() {
                        if(vd.size()==0 || vd.size() < id) return NULL;
                        else return &vd[id++];
                    }

    private:
        vector<double> vd;
        int id = 0;
};

//------------------------------------------------------------------------------

// Returns the pointer to a double variable. The variable temporarily stores a 
// value from the list. The iterator it cannot be returned as a pointer to 
// double.

class List_iterator : public Iterator_d
{
    public:
        List_iterator(list<double> lldd) : ld{lldd} {}
        double* next();

    private:
        list<double> ld; 
        list<double>::iterator it{ld.begin()};
        double var{0};
        bool flag{false};                           // Used to finish printing.
};

//------------------------------------------------------------------------------

// Returns the pointer to a double variable. The variable temporarily stores a 
// value from the list. The iterator it cannot be returned as a pointer to 
// double.

double* List_iterator::next()
{
    if(ld.size()==0 || flag)
    {
        return NULL;
    }
    else
    {
        var = *it;
        ++it;
        if(it == ld.end())
            flag = true;
            
        return &var;
    }
}

//------------------------------------------------------------------------------

// Prints the vector elements.

void print(Iterator_d& vi)
{
    double* id = vi.next();
    while(id != NULL)               // If the pointer is NULL, the print ends.
    {
        cout << "\n\n\tElement address:\t" << id
             << "\n\tElement value:\t" << *id;
        id = vi.next();
    }
        
    return;
}

//------------------------------------------------------------------------------

int main()
{
    // Printing the elements of a vector<double>.
    vector<double> vd{vector<double>{1.3, 4.6, 3.9}};
    Vector_iterator vi{vd};
    cout << "\n\n\tElements of a vector<double>\n\t";
    print(vi);

    // Printing the elements of a list<double>.
    list<double> ld{1.2, 3.4, 6.7};
    List_iterator li{ld};
    cout << "\n\n\n\tElements of a list<double>\n\t";
    print(li);

    return 0;
}

//------------------------------------------------------------------------------
