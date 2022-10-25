/*Define a Striped_rectangle where instead of fill, the rectangle is filled by
drawing one-pixel-wide horizontal lines across the inside of the rectangle.*/

//#include <iostream>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

//using namespace std;

//------------------------------------------------------------------------------

struct Striped_rectangle : Rectangle
{
    Striped_rectangle(Point pp,int ww,int hh)
        : w{ww},h{hh},Rectangle{pp,ww,hh} {}
    void draw_lines() const;

    private:
        int w;
        int h;
};

//------------------------------------------------------------------------------

void Striped_rectangle::draw_lines() const
{
    if(color().visibility())
        for(int hh = 1; hh < h; ++hh)
            fl_line(point(0).x,point(0).y+hh,point(0).x+w,point(0).y+hh);
}

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;

    int sw = 1000;                              // Size width.
    int sh = 800;                               // Size height.
    Point tl{100,100};
    Simple_window win{tl,sw,sh,"Chapter 14 - EX145"};

    Striped_rectangle sr{Point{200,300},300,100};
    win.attach(sr);

    win.wait_for_button();
    return 0;
}

//------------------------------------------------------------------------------
