#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg; //{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    msg.push_back("hola");
    msg.push_back("mundo");

    for (int i = 0; i < 10; ++i)
    {
        cout << msg[0] << msg[1] << " ";
    }
    cout << endl;
}