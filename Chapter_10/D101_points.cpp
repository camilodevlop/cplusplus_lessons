/*Definition of the data type Point that has two coordinate members x and y.*/

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Point
{
        int x;
        int y;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Point& p)
{
    int x,y;                            // Point coordinates.
    char ch1, ch2, ch3;

    is >> ch1 >> x >> ch2 >> y >> ch3;

    if (!is) return is;

    if (ch1 != '(' || ch2 != ',' || ch3 != ')')
    {
        is.clear(ios_base::failbit);
        return is;
    }
    
    p.x = x;
    p.y = y;
    
    return is;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

//------------------------------------------------------------------------------

bool operator==(const vector<Point>& p1, const vector<Point>& p2)
{   
    if (p1.size() != p2.size())
        return false;

    for (int i = 0; i < p1.size(); i++)
        if ( (p1[i].x != p2[i].x) || (p1[i].y != p2[i].y))
            return false;
    
    return true;
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if(ist.fail())
    {
        ist.clear();
        char ch;
        ist >> ch;
        cout << "\n\n\t" << ch << "\n\n\t";
        if (ch == term) return;
        error(message);
    }
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        vector<Point> original_points;
        vector<Point> processed_points;
        
        cout << "\n\n\tInput seven points (x,y) points:\n\n\t";
    
        // Input values.
        
        for (Point p; cin >> p;)
        {
            original_points.push_back(p);
        }
        
        // Print values.

        cout << "\n\n\tEntered points\n\t";
        for (int i = 0; i < original_points.size(); i++)
            cout << "\n\t" << original_points[i] << "\n\t";

        // Writing in mydata file.
        
        ofstream ost("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata");
        if (!ost) error("\n\n\tCan't open output file:\n\t");
        
        for (int i = 0; i < original_points.size(); i++)
            ost << '(' << original_points[i].x << ',' << original_points[i].y << ")";
        
        ost.close();        
        
        // Reading from mydata file.

        ifstream ist("/Users/camiloalejandrocastillobenavides/Documents/Programming_C++/Chapter_10/mydata");
        
        Point p;
        while (ist >> p)
            processed_points.push_back(p);

        cout << "\n\n\tProcessed points\n\t";
        for (int i = 0; i < processed_points.size(); i++)
            cout << "\n\t" << processed_points[i] << "\n\t";
        
        // Comparing both vectors original and processed.
        if (original_points == processed_points)
            cout << "\n\n\tPoints Ok.\n\t";
        else
            cout << "\n\n\tSomething's is wrong.\n\t";
        
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
        return 2;
    }
}

//------------------------------------------------------------------------------