/*Drill of the Chapter 19.*/

#include<iostream>
#include<vector>
#include"runtime_errors.h"

using namespace std;

//--------------------------------------------------------------------

// Function prototype.

template<typename T>
istream& operator>>(istream&, vector<T>&);

//--------------------------------------------------------------------

template<typename T>
struct S
{
    S(T v = T()) : val{v} {}
    ~S(){}
    
    T& get();
    const T& get() const;
    S& operator=(const T& v);
    void read_val(T& v);

private:
    T val;
};

//--------------------------------------------------------------------

template<typename T>
T& S<T>::get()
{
   return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

//--------------------------------------------------------------------

template<typename T>
S<T>& S<T>::operator=(const T& v)
{
    if(val == v) return *this;
    
    val = v;
    return *this;
}

//--------------------------------------------------------------------

template<typename T>
void S<T>::read_val(T& v)
{
    cin >> v;
    val = v;
}

//--------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
   if(ist.fail()) 
   {
       ist.clear();
       ist.unget();
       char ch;
       if(ist>>ch && ch==term) return;  // All is fine.
       error(message);
   }
}

//--------------------------------------------------------------------

// Input operator for vector<T>.

template<typename T>
istream& operator>>(istream& is, vector<T>& s)
{
    // Make ist throw if it goes bad.
    is.exceptions(is.exceptions()|ios_base::badbit);

    char ch;
    T v;

    if(is>>ch && ch!='{')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    for(; is>>v>>ch;) 
    {
        s.push_back(v);
        
        if(ch != ',')
        {
            if(ch == '}')
                is.clear(ios_base::failbit);
            else
                error("\n\n\tFormat Error.\n\t");
        }
    }

    end_of_loop(is,'}',"\n\n\tError\n\t");
    return is;
}

//--------------------------------------------------------------------

// Output operator for vector<T>.

template<typename T>
ostream& operator<<(ostream& os, const vector<T> s)
{
    ostringstream o{};
    for(int i=0; i<s.size(); ++i) o << s[i] << " ";

    return os << "\n\n\t{ " << o.str().c_str() << "}";
}

//--------------------------------------------------------------------

int main()
{
    S<int> s_int{10};
    S<char> s_char{'c'};
    S<double> s_double{10.0};
    S<string> s_str{"Camilo"};
    S<vector<int>> s_vec{vector<int> (5) = {0,1,2,3,4}};


    cout << "\n\n\tStruct S - int value: " << s_int.get() << "\n\t";
    cout << "\n\tStruct S - char value: " << s_char.get() << "\n\t";
    cout << "\n\tStruct S - double value: " << s_double.get() << "\n\t";
    cout << "\n\tStruct S - string value: " << s_str.get() << "\n\t";
    cout << "\n\tStruct S - vector: " << s_vec.get()[0] << "\n\t";

    vector<int> s_v = {6,7,8,9,10,11,12};
    s_vec = s_v;
    cout << "\n\tStruct S - vector: " << s_vec.get() << "\n\t";

    vector<int> v;
    cout << "\n\n\tInput a vector (use the format {v1,v2,...vn}):\n\t";
    s_vec.read_val(v);
    cout << "\tStruct S - vector: " << s_vec.get() << "\n\t";

    S<vector<char>> s_vecc{vector<char> (5) = {'A','L','E','J','X'}};
    vector<char> sv;
    cout << "\n\n\tInput a vector (use the format {v1,v2,...vn}):\n\t";
    s_vecc.read_val(sv);
    cout << "\tStruct S - vector: " << s_vecc.get() << "\n\t";

    /*int i;
    cout << "\n\n\tInput an int value: ";
    s_int.read_val(i);
    cout << "\tStruct S - int value: " << s_int.get() << "\n\t";

    char c;
    cout << "\n\n\tInput a char value: ";
    s_char.read_val(c);
    cout << "\tStruct S - char value: " << s_char.get() << "\n\t";

    double d;
    cout << "\n\n\tInput a double value: ";
    s_double.read_val(d);
    cout << "\tStruct S - double value: " << s_double.get() << "\n\t";

    string s;
    cout << "\n\n\tInput a string value: ";
    s_str.read_val(s);
    cout << "\tStruct S - string value: " << s_str.get() << "\n\t";*/
    return 0;
}

//--------------------------------------------------------------------
