/*Write a function, char* findx(const char* s, const char* x), that
finds the first occurrence of the C-style string x in s. Try not to
use const_cast<>.*/

#include<iostream>
#include<string>

using namespace std;

//--------------------------------------------------------------------

char* findx(const char* s, const char* x)
{
    if(*s=='\0' || *x=='\0')
        return nullptr;

    int i{0};

    // "index" stores the index which can have more than one digit.
    string index = string{""};

    while(s[i] != '\0')
    {
        int j{0};
        while(s[i+j] == x[j])
        {
            ++j;
            // x is in s.
            //if(x[j] == '\0') return const_cast<char*>(&s[i]);
            if(x[j] == '\0')
            {
                index = to_string(i);

                // This reserves spaces of type char according to the
                // length of "index".
                char* ind_ptr = new char[index.size() + 1];

                // Saving the components of "index". 
                for(int i=0; i<=index.size(); ++i)
                {
                    ind_ptr[i] = index[i];
                    if(i == index.size())
                        ind_ptr[i] = '\0';
                }
                
                return ind_ptr;
            }

            // s is shorter than x.
            if(s[i+j] == '\0') return nullptr;
        }
        i+=(j+1);
    }

    // x is not in s.
    return nullptr;
}

//--------------------------------------------------------------------

int main()
{
    string str1{"Camilo Alejandro"};
    string str2{"dro"};

    // This retrieves the index via ch.
    string index{""};
    char* ch = findx(&str1[0],&str2[0]);

    if(ch)
    {
        // Stores the index in "index".
        for(int i=0; ch[i]!='\0'; ++i)
            index += ch[i];

        cout << "\n\n\tThe first occurrence starts at the character:"
             << "\n\t" << str1[stoi(index)] << "\n\t"
             << "the first occurrence occurs at position:"
             << "\n\t" << stoi(index) << "\n\n\t";

        delete[] ch;
    }
    else
        cout << "\n\n\tx is not in s or a string is empty.\n\n\t";

    return 0;
}

//--------------------------------------------------------------------
