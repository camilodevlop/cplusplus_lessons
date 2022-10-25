/*Program to manage names and scores by using vectors. The program notifies if a name is entered twice.
You can find particular names or scores.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Name_value
{   
    public:
        void repeated_Name (vector<Name_value> ns);
  
        string name;
        int   score;
        Name_value(string n, int s)
            :name(n), score(s) { }
};

void Name_value::repeated_Name(vector<Name_value> ns)
{
    vector<string> auxiliar;
    for (int i = 0; i < ns.size(); ++i)
        auxiliar.push_back(ns[i].name);
    
    sort(auxiliar.begin(),auxiliar.end());

    int rep_counter = 0;
    int i = 0;
    
    while(rep_counter == 0 && (i+1) < auxiliar.size())
    {
        if (auxiliar[i] == auxiliar[i+1])
        {
            ++rep_counter;
            cout << "\n\tThe follow name is repeated:\t" << auxiliar[i];
        }
        ++i;
    }
}

vector<Name_value> names_scores;    // Vector Name_value objects to store names and values.

string names = " ";                  // Variables to collect the names and values.
int scores = 1;

int main ()
{
    Name_value obj_name_value(" ",1);
    
    cout << "\n\nInput Name and Score. Input NoName and 0 to finish\n\nName\tScore\n";
    while (names != "NoName" && scores != 0){
        cin >> names >> scores;
        obj_name_value.name = names;
        obj_name_value.score = scores;
        names_scores.push_back(obj_name_value);
    }
    
    obj_name_value.repeated_Name(names_scores);

    return 0;
}