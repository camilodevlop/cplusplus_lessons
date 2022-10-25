/* Programa que permite la detección de palabras adjuntas repetidas. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

string previous = " ";
string current;

while(cin >> current){
cout << "Previous = " << previous << "   Current = " << current << endl;
if(previous == current)
	cout << "repeated word: " << current << endl;
previous = current;
}
return 0;
}