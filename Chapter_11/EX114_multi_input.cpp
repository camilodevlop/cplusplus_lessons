/*Program that prompts the user to enter several integers in any
combination -octal, decimal, or hexadeximal- using the 0 or 0x
base suffixes. Converts to decimal form.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "runtime_errors.h"

using namespace std;

//------------------------------------------------------------------------------

void num_prompter(const string& string_num,const char& base)
{
    istringstream is {string_num};
    int num;

    if(base=='h' && is>>hex>>num)
    {
        cout << hex << num << " hexadeximal converts to "
             << dec << num << " decimal.\n\t";
        return;
    }

    if(base=='o' && is>>oct>>num)
    {
        cout << oct << num << " octal converts to "
             << dec << num << " decimal.\n\t";
        return;
    }

    if(base=='d' && is>>dec>>num)
    {
        cout << dec << num << " decimal converts to "
             << num << " decimal.\n\t";
        return;
    }
    
    error("The number is undefiend: ",string_num);
    return;
}

//------------------------------------------------------------------------------

void num_base(const string& string_num)
{
    switch(string_num[0])
    {
        case '0':
            if(string_num[1]=='x' || string_num[1]=='X')
                num_prompter(string_num,'h');
            else
                num_prompter(string_num,'o');
            break;
        
        default:
            num_prompter(string_num,'d');
            break;
    }

    return;
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        // Accepting and interpreting 0 (oct) and 0x (hex).
        cin.unsetf(ios::dec);
        cin.unsetf(ios::oct);
        cin.unsetf(ios::hex);

        string string_num;
        vector <string> nums;

        // Input the values.
        cout << "\n\n\tInput the values 0 (oct) and 0x (hex),"
         << " Type Ctrl+D to finish.\n\n\t";

        while(cin>>string_num) 
            nums.push_back(string_num);

        // Result output.
        cout << "\n\n\tThe results are:\n\n\t";
        for(int i=0; i<nums.size(); ++i)
            num_base(nums[i]);

        return 0;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
        return 1;
    }
}

//------------------------------------------------------------------------------
