/*Class definition drill. 
Warning: the >> operator does not compile correctly. Therefore, the Person
objects are individually typed using the constructor.
*/

#include<iostream>
#include<string>
#include<vector>
#include"GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Person
{
	Person(string name, string l_name, int age);

	bool is_inv_char(char c);
	string name() const {return nm;}
	string l_name() const {return l_nm;};
	int age() const {return a;}

	private:
		string nm; 				// Name.
		string l_nm; 			// Last name.
		int a; 					// Age.
		string invalid_char{";:\"\'[]*&^%$#@!"}; 	// Invalid characters in names.
};

//------------------------------------------------------------------------------

Person::Person(string name, string l_name, int age)
			   :nm{name}, l_nm{l_name}, a{age}
{
	// Checking the age range.
	if(age<0 || age>150)
		error("\n\tThe age is not in the range 0<age<150: \n\t");
	
	// Searching for the invalid characters.
	for(char ch:nm)
		if(is_inv_char(ch))
			error("\n\tAn invalid character was detected.\n\t");
	
	for(char ch:l_nm)	
		if(is_inv_char(ch))
			error("\n\tAn invalid character was detected.\n\t");
}

//------------------------------------------------------------------------------

bool Person::is_inv_char(char c)
{
	for(char w:invalid_char)
		if(c==w) return true;
	
	return false;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is,Person& p)
{
	string name;
	string l_name;
	int age;
	char ch1,ch2,ch3,ch4;
	
	//Person pp;

	if(is>>ch1>>name>>ch2>>age>>ch3>>l_name>>ch4)
	{
		if(ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')')
		{
			is.clear(ios_base::failbit);
			return is;
		}
	}else
		return is;
	
	p = Person{name,l_name,age};
	return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os,const Person& p)
{
	return os << '(' << p.name() << ',' << p.l_name() << ',' << p.age() << ')';
}

//------------------------------------------------------------------------------

int main()
{
	try
	{
		Person pr{"Goofy","G1",100};
		Person pr2{"G2","LG2",2};
		Person pr3{"G3","LG3",3};
		Person pr4{"G4","LG4",4};
		Person pr5{"G5","LG5",5};
		Person pr6{"G6","LG6",6};

		vector<Person> prs;
		cout << "\n\n\tEnter the objects of type Person:\n\t";

		//while(cin>>pr)
			prs.push_back(pr);
			prs.push_back(pr2);
			prs.push_back(pr3);
			prs.push_back(pr4);
			prs.push_back(pr5);
			prs.push_back(pr6);

		for(Person p:prs)
			cout << p << "\n\t";

		return 0;
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\t';
		return 1;
	}
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\n\t";
        return 1;
    }
}

//------------------------------------------------------------------------------
