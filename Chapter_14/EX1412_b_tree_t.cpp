/* Modify Binary_tree to draw its nodes using a virtual function. Derive a new
class from Binary_tree that overrides that virtual function to use a different
representation for a node (e.g. a triangle).

- In this case Binary tree inherits from Shape. Shape has the virtual function
draw_lines(). The new Binary_tree_t  class overrides draw_lines().

- The radius r is used to fix the triangle height.*/

#include <iostream>
#include <cmath>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class Binary_tree : public Shape
{
    public:
        Binary_tree(int ll, int rr);
        void draw_lines() const;

    protected:
        int lv;                             // Number of levels.
        int r;                              // Node radius.
};

//------------------------------------------------------------------------------

Binary_tree::Binary_tree(int ll, int rr) : lv{ll}, r{rr}
{
    int circles{1};
    int inc_x;
    int x_coordinate;
    int y_coordinate{0};

    for(int i=1; i<=lv; ++i)
    {
        inc_x = 1500/pow(2,i);              // 1500 pixels wide.
        x_coordinate = inc_x;
        for(int j=1; j<=circles; ++j)
        {
            add(Point{x_coordinate,y_coordinate});
            x_coordinate += (2*inc_x);
        }
        
        y_coordinate+=(6*r);
        circles*=2;
    }
}

//------------------------------------------------------------------------------

void Binary_tree::draw_lines() const
{
    if(lv > 0) 
    {
        // Drawing the initial circle.
        fl_arc(point(0).x,point(0).y,2*r,2*r,0,360);
        if(lv > 1)
        {
            // Drawing the connections of the initial circle.
            fl_line(point(0).x+r,point(0).y+(2*r),point(1).x+r,point(1).y);
            fl_line(point(0).x+r,point(0).y+(2*r),point(2).x+r,point(2).y);

            for(int i=1; i<lv; ++i)
            {
                int nlp = pow(2,i+1) - 1;   // Starting point of the next level.
                for(int j=pow(2,i)-1; j<=2*(pow(2,i)-1); ++j)
                    if(color().visibility())
	                {
                        // Drawing the circles.
		                fl_arc(point(j).x,point(j).y,2*r,2*r,0,360);
                        if(i<lv-1)      // The condition prevents drawing the last level connections.
                        {
                            fl_line(point(j).x+r,point(j).y+(2*r),point(nlp).x+r,point(nlp).y);
                            fl_line(point(j).x+r,point(j).y+(2*r),point(nlp+1).x+r,point(nlp+1).y);
                            nlp+=2;
                        }
	                }
            }
        }
    }else
        cout << "\n\n\tThe number of levels is equal to zero.\n\t";

    return;
}

//------------------------------------------------------------------------------

struct Binary_tree_t : Binary_tree
{
    Binary_tree_t(int ll,int rr):Binary_tree{ll,rr} {}
    void draw_lines() const;
};

//------------------------------------------------------------------------------

void Binary_tree_t::draw_lines() const
{
    if(lv > 0) 
    {
        // Drawing the initial triangle.
        fl_line(point(0).x+r,point(0).y,point(0).x,point(0).y+2*r);
        fl_line(point(0).x+r,point(0).y,point(0).x+2*r,point(0).y+2*r);
        fl_line(point(0).x,point(0).y+2*r,point(0).x+2*r,point(0).y+2*r);

        if(lv > 1)
        {
            // Drawing the connections of the initial circle.
            fl_line(point(0).x+r,point(0).y+(2*r),point(1).x+r,point(1).y);
            fl_line(point(0).x+r,point(0).y+(2*r),point(2).x+r,point(2).y);

            for(int i=1; i<lv; ++i)
            {
                int nlp = pow(2,i+1) - 1;   // Starting point of the next level.
                for(int j=pow(2,i)-1; j<=2*(pow(2,i)-1); ++j)
                    if(color().visibility())
	                {
                        // Drawing the circles.
                        fl_line(point(j).x+r,point(j).y,point(j).x,point(j).y+2*r);
                        fl_line(point(j).x+r,point(j).y,point(j).x+2*r,point(j).y+2*r);
                        fl_line(point(j).x,point(j).y+2*r,point(j).x+2*r,point(j).y+2*r);

                        if(i<lv-1)      // The condition prevents drawing the last level connections.
                        {
                            fl_line(point(j).x+r,point(j).y+(2*r),point(nlp).x+r,point(nlp).y);
                            fl_line(point(j).x+r,point(j).y+(2*r),point(nlp+1).x+r,point(nlp+1).y);
                            nlp+=2;
                        }
	                }
            }
        }
    }else
        cout << "\n\n\tThe number of levels is equal to zero.\n\t";

    return;
}

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;  

    int sw{1500}; 				// Size width. 
	int sh{800}; 				// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,sh,"Chapter 14 - EX1411"};

    Binary_tree_t btt{5,20};
    win.attach(btt);

    /*Binary_tree bt{8,20};
    win.attach(bt);*/

    win.wait_for_button();
    return 0;
}

//------------------------------------------------------------------------------
