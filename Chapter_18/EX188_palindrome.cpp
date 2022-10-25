/*Rewrite all the functions in 18.7 to use the approach of making a
backward copy of the string and then comparing; for example, take 
"home", generate "emoh".*/

#include <iostream>
//#include <string>

using namespace std;

//--------------------------------------------------------------------

// Palindrome using string.

bool is_palindrome_str(const string& s)
{
    string cpy{""};
    for(int i = s.size()-1; i >= 0; --i)
        cpy += s[i];

    if(cpy != s) return false;
    return true;
}

//--------------------------------------------------------------------

// Palindrome using arrays.

bool is_palindrome_arr(const char s[], int n)
{
    char cpy[n];
    for(int i=0; i<strlen(s); ++i)
        cpy[i] = s[--n];

    for(int i=0; i<strlen(s); ++i)
        if(cpy[i] != s[i])
            return false;

    return true;
}

istream& read_word(istream& is,char* buffer,int max)
{
    is.width(max);
    is >> buffer;

    return is;
}

//--------------------------------------------------------------------

// Palindromes using pointers.

bool is_palindrome_ptr(const char* first, const char* last)
{
    char cpy[strlen(first)];
    
    int i{0};
    while(i < strlen(first))
    {
        *(cpy+i) = *(last-i);
        ++i;
    }

    for(int i=0; i<strlen(first); ++i)
        if(*(cpy+i) != *(first+i))
            return false;

    return true;
}

//--------------------------------------------------------------------

int main()
{
    // Testing palindrome using string.

    cout << "\n\n\tPalindrome using string."
         << "\n\tInput the string (\"q\" to finish): ";

    for(string s; cin >> s;)
    {
        if(s == "q") break;

        cout << '\t' << s << " is ";
        if(!is_palindrome_str(s)) cout << "not ";
        cout << "a palindrome.";

        cout << "\n\n\tInput the string (\"q\" to finish): ";
    }
    
    // Testing palindrome using array.
    
    constexpr int max = 128;

    cout << "\n\n\tPalindrome using array."
         << "\n\tInput the string (\"q\" to finish): ";

    for(char s[max]; read_word(cin,s,max);)
    {
        if(*s == 'q') break;

        cout << '\t' << s << " is ";
        if(!is_palindrome_arr(s,strlen(s))) cout << "not ";
        cout << "a palindrome.";

        cout << "\n\n\tInput the string (\"q\" to finish): ";
    }

    // Testing palindrome using pointers.

    cout << "\n\n\tPalindrome using pointers."
         << "\n\tInput the string (\"q\" to finish): ";

    for(char s[max]; read_word(cin,s,max);)
    {
        if(*s == 'q') break;

        cout << '\t' << s << " is ";
        if(!is_palindrome_ptr(&s[0],&s[strlen(s)-1])) cout << "not ";
        cout << "a palindrome.";

        cout << "\n\n\tInput the string (\"q\" to finish): ";
    }

    return 0;
}

//--------------------------------------------------------------------
