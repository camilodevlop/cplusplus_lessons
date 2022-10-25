/*Below are 25 code fragments. Each is meant to be inserted into a "scaffolding" of code.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

int main (){

    try{
        
        // 1, 2, 3 and 4.
        cout << "Success!\n";
        cout << "Success!\n";
        cout << "Success!" << "!\n";
        cout << "Success!" << '\n';

        // 5.
        string res = "7";
        vector<int> v;
        for (int i = 0; i < 10; i++)
            v.push_back(0);
        v[5] = 5;
        cout << "Success!\n";

        // 6.
        v[5] = 7;
        if (v[5] == 7){
            cout << "Success!\n";
        }

        // 7.
        bool cond = true;
        if (cond)
            cout << "Success!\n";
        else
            cout << "Fail!\n";
        
        // 8.
        bool c = false;
        if (c)
            cout << "Success!\n";
        else
            cout << "Fail\n";

        // 9.
        string s = "ape";
        c = true;
        if (c)
            cout << "Success!\n";
        
        // 10.
        if (s == "fool")
            cout << "Success!\n";
        
        // 11.
        if (s == "fool")
            cout << "Success!\n";
        
        // 12.
        if (c)
            cout << "Success!\n";

        // 13.
        vector<char> vc;
        for (int i = 0; i < 5; i++)
            vc.push_back(' ');
        
        for (int i = 0; i < vc.size(); i++)
            cout << "Success!\n";

        // 14.
        for (int i = 0; i <= vc.size(); i++)
            cout << "Success!!!\n";
        
        // 15.
        s = "Success!\n";
        for (int i = 0; i < 11; ++i)
            cout << s[i];
        
        // 16.
        if (true)
            cout << "Success!\n";
        else
            cout << "Fail!\n";
        
         // 17.
         int x = 50;
         char cp = x;
         if (cp == 50)
            cout << "Success\n";

        // 18.
        s = "Success!\n";
        for (int i = 0; i < 30; ++i)
            cout << s[i];
        
        // 19.
        for (int i = 0; i <= v.size(); ++i)
            cout << "Success\n";
        
        // 20.
        int i = 0;
        int j = 9;
        while (i < 10)
            ++i;
        if (j < i)
            cout << "+++Success!\n";
        
        // 21.
        x = 3;
        double d = 5 / (x-2);
        if (d == 2 * x - 1.0)
            cout << "--Success!\n";
        
        // 22.
        s = "Success!\n";
        for (int i = 0; i <= 10; ++i)
            cout << s[i];
        
        // 23.
        i = 0;
        while (i < 10)
            ++i;
        if (j < i)
            cout << "**Success!\n";
        
        // 24.
        x = 4;
        d = 5 / (x - 2);
        if (d == 2 * x + 0.5)
            cout << "&&Success!\n";

        // 25.
        cin >> s;
                    

        return 0;
    }
    catch (const exception& e){
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...){
        cerr << "Oops: unknown exceptions!\n";
        return 2;
    }
}