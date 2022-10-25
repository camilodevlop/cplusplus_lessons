/*Program to manage names and scores by using vectors. The program notifies if a name is entered twice.
You can find particular names or scores.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string name = "";       // Variables to collect de values.
int score = 1;

vector<string> names;   // Vectors to store the values.
vector<int> scores;
vector<string> auxiliar;

int main (){

    cout << "\n\nInput Name and Score. Input NoName and 0 to finish\n\nName\tScore\n";
    while (name != "NoName" && score != 0){
        cin >> name >> score;
        names.push_back(name);
        scores.push_back(score);
    }
    
    // Detecting if a name is repeated.

    int rep_counter = 0;        // Varibale to detect if a name is twice.
    int i = 0;                  // Vector subscript.
    auxiliar = names;
    sort(auxiliar.begin(),auxiliar.end());

    while (rep_counter == 0 && (i+1) < auxiliar.size()){
        if (auxiliar[i] == auxiliar[i+1]){
            ++rep_counter;
            cout << "\n\tThe follow name is repeated:\t" << auxiliar[i];
        }
        ++i;
    }

    // Searching names and scores.
    
    string requested_name;
    i = 0;

    cout << "\n\tEnter the name to search its score: ";
    cin >> requested_name;

    while (i < names.size()){
        if (requested_name == names[i]){
            cout << "\n\tScore\t" << scores[i];
            i = names.size();
        }
        ++i;
    }
    if (i == names.size()){
        cout << "\n\tName not found.\n";
    }

    int requested_score;
    i = 0;

    cout << "\n\tEnter the score to search its name: ";
    cin >> requested_score;

    while (i < scores.size()){
        if (requested_score == scores[i]){
            cout << "\n\tName\t" << names[i];
            i = scores.size();
        }
        ++i;
    }
    if (i == scores.size()){
        cout << "\n\tScore not found.\n";
    }
    return 0;
}