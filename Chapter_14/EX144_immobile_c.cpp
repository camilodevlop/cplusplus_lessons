/*Define a class Immobile_Circle, which is just like Circle but can't be move.*/

#include <iostream>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class Immobile_Circle : public Circle
{
    public:
        Immobile_Circle(Point pp, int rr) : Circle{pp,rr} {} 
        void move(int dx, int dy) {cout << "\n\n\tImmobile Circle\n\t";}
};

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;

    int sw = 1000;                              // Size width.
    int sh = 800;                               // Size height.
    Point tl{100,100};
    Simple_window win{tl,sw,sh,"Chapter 14 - EX144"};

    Circle cr{Point{200,200},50};
    win.attach(cr);
    cr.move(100,150);
    
    Immobile_Circle ic{Point{500,500},100};
    win.attach(ic);
    ic.move(50,100);

    win.wait_for_button();
    return 0;
}

//------------------------------------------------------------------------------
