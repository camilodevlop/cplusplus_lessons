/* Programa que genera un modelo de carta de manera automática a partir de las entradas del usuario. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

string first_name = " ";                                            // Primera parte.
cout << "Enter the name of person you want to write to:" << endl;
cin >> first_name;
cout << "Dear " << first_name << ",\n";

cout << "\tHow are you, \nI am fine, I miss you!!!\n\n";            // Segunda parte.

string friend_name = " ";                                          // Tercera parte.
cout << "Enter the name of your friend:" << endl;
cin >> friend_name;
cout << "Have you seen " << friend_name << " lately?\n\n";

char friend_sex = '0';                                            // Cuarta parte.
cout << "Enter m if the friend is male and an f is the friend is female:" << endl;
cin >> friend_sex;
if (friend_sex == 'm')
  cout << "If you see " << friend_name << " please ask him to call me.\n\n";
if (friend_sex == 'f')
  cout << "If you see " << friend_name << " please ask her to call me.\n\n";

int age = 0;                                                      // Quinta parte.
cout << "Enter the age of the recipient:" << endl;
cin >> age;
if (age <= 0 || age >= 110)
  cout << "You are kidding!\n";
 else{
   cout << "I hear you just had a birthday and you are " << age << " years old.\n";
   if (age <= 12)                                                  // Sexta parte.
     cout << "Next year you will be " << age+1 << ".\n";
   if (age == 17)
     cout << "Next year you will be able to vote.\n";
   if (age >= 70)
     cout << "I hope you are enjoying retirement.\n";
}
 cout << "Yours Sincerely\n\nCamilo" << endl;
return 0;

}
