/*In this exercise is created a class to manage the the pairs (name, age). The names are saved in
"name" vector and the ages are saved in the "age" vector. The class must contain read_names(),
read_ages(), print(), sort().*/

//------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class Name_pairs
{
    public:
        void read_names();
        void read_ages();
        void sort_op();
        int size() const;
        string name_v (int i) const
            {return name[i];}
        int age_v (int i) const
            {return age[i];}

    private:
        vector<string> name;
        vector<double> age;
};

//------------------------------------------------------------------------------

void Name_pairs::read_names()
{
    string s = "";

    cout << "\n\n\tEnter names (type 'END' to finish):\n\n\t";
    while (cin >> s && s != "END")
    {
        name.push_back(s);
        cout << '\t';
    }
    
    return;
}

//------------------------------------------------------------------------------

void Name_pairs::read_ages()
{
    double a = 0;
    
    cout << "\n\n\tEnter ages (type '-1' to finish):\n\n\t";
    while (cin >> a && a != -1)
    {
        age.push_back(a);
        cout << "\t";
    }
    
    return;
}

//------------------------------------------------------------------------------

int Name_pairs::size() const
{
    return name.size();
}

//------------------------------------------------------------------------------

void Name_pairs::sort_op()
{
    int s = name.size();
    vector<string> n = name;
    vector<double> sa = age;

    sort(name.begin(), name.end());

    int i = 0;
    while (i < s)
    {
        for (int j = 0; j < s; j++)
            if (n[i] == name[j])
                age[i] = sa[j];

        ++i;
    }

    return;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Name_pairs& np)
{
    for (int i = 0; i < np.size(); i++)
        cout << np.name_v(i) << "\t\t" << np.age_v(i) << "\n\t";
    return os;
}

//------------------------------------------------------------------------------

bool operator==(const Name_pairs& np1, const Name_pairs& np2)
{      
    for (int i = 0; i < np1.size(); i++)
        if (np1.name_v(i) != np2.name_v(i) || np1.age_v(i) != np2.age_v(i))
            return false;
    
    return true;
}

//------------------------------------------------------------------------------

bool operator!=(const Name_pairs& np1, const Name_pairs& np2)
{   
    return !(np1 == np2);
}

//------------------------------------------------------------------------------

int main()
{
    try
    {   
        int x = '1';
        cout << "\n\n\t" << x;
        
        // Read names and ages, sort.

        Name_pairs np;
        
        np.read_names();
        np.read_ages();
        
        cout << "\n\n\tName\t\tAges\n\n\t";
        cout << np;

        np.sort_op();
        
        cout << "\n\n\tName\t\tAges\n\n\t";
        cout << np;

        
        // Operator overloading test.
        
        Name_pairs np1, np2;
        
        np1.read_names();
        np1.read_ages();

        np2.read_names();
        np2.read_ages();

        if (np1 == np2)
            cout << "\n\n\tThe objects are equal.\n\t";

        if (np1 != np2)
            cout << "\n\n\tThe objects are different.\n\t";
        
        return 0;
    }
    catch(exception& e)
    {
        cerr << e.what() << " error.\n\n\t";
    }
}

//------------------------------------------------------------------------------