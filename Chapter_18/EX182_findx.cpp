/*Write a function, char* findx(const char* s, const char* x), that
finds the first occurrence of the C-style string x in s. Do not use
subscripting.*/

#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------------------------------

char* findx(const char* s, const char* x)
{
    if(*s=='\0' || *x=='\0')
        return nullptr;

    int i{0};

    // "index" stores the index which can have more than a digit.
    string index{""};

    while(s)
    {
        int j{0};
        while(*(s+i+j) == *(x+j))
        {
            // First occurrence of the string.
            if(*(x+i) == '\0')
            {
                index = to_string(i) + '\0';
                char* ind_ptr = new char[index.size()];
                for(char c:index)
                {
                    *ind_ptr = c;
                    ind_ptr++;
                }
                return ind_ptr - index.size();
            }

            // s is shorter than x.
            if(*(s+i) == '\0')
                return nullptr;
        }
        i+=j+1;
    }
    
    // s was not found.
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
        for(char* aux = ch; *aux!='\0'; ++aux)
            index += *aux;

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
