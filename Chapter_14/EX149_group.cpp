/*Define a Group to be a container of Shapes with suitable operations applied to
 the various members members of the Group. Use a Group to define a checkers (dra-
 ughts) board where pieces can be moved under program control.*/

#include <iostream>
#include <cmath>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

// Alternate colors to draw the board.

void change(int& c1, int& c2)
{
    int aux = c1;
    c1 = c2;
    c2 = aux;

    return;
}

//------------------------------------------------------------------------------

// Draws the board.

void draw_board(Vector_ref<Rectangle>& vr,int color_1,int color_2,Simple_window& w)
{
    for(int j=0; j<8; ++j)
    {
        for(int i=0; i<8; ++i)
        {
           vr.push_back(new Rectangle{Point{i*100,j*100},100,100});
           if((vr.size()-1) % 2 == 0)
               vr[vr.size()-1].set_fill_color(color_1);
           else
               vr[vr.size()-1].set_fill_color(color_2);
            w.attach(vr[vr.size()-1]);
        }
        change(color_1,color_2);
    } 

    return;
}

//------------------------------------------------------------------------------

// Draws the red checkers.

void draw_red_checkers(Vector_ref<Rectangle>& rch, Color cl, Simple_window& w)
{
    int sc{0};                     // Square counter.

    for(int j=0; j<3; ++j)
        for(int i=0; i<8; ++i)
        {
            if((j%2 == 0 && sc%2 == 0) || (j%2 == 1 && sc%2 == 1))
            {
                rch.push_back(new Rectangle{Point{i*100+25,j*100+25},50,50});
                rch[rch.size()-1].set_fill_color(cl);
                w.attach(rch[rch.size()-1]);
            }
            ++sc;
        }

    return;
}

//------------------------------------------------------------------------------

// Draws the white checkers.

void draw_white_checkers(Vector_ref<Rectangle>& wch, Color cl, Simple_window& w)
{
    int sc{0};                     // Square counter.
    for(int j=5; j<8; ++j)
        for(int i=0; i<8; ++i)
        {
            if((j%2 == 0 && sc%2 == 0) || (j%2 == 1 && sc%2 == 1))
            {
                wch.push_back(new Rectangle{Point{i*100+25,j*100+25},50,50});
                wch[wch.size()-1].set_fill_color(cl);
                w.attach(wch[wch.size()-1]);
            }
            ++sc;
        }
    return;
}

//------------------------------------------------------------------------------

// Moves the red checkers.

void move_red_checkers(Vector_ref<Rectangle>& vc)
{
    int dir{1};
    int count{0};
    
    for(int i=0; i<vc.size(); ++i)
    {
        vc[i].move(dir*100,100);

        ++count;
        if(count%4 == 0)
            dir*=(-1);
    } 

    return;
}

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;	

	int sw{1000}; 				// Size width. 
	int sh{800}; 				// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,sh,"Chapter 14 - EX149"};


    // Drawing the board.
    Vector_ref<Rectangle> vr;
    draw_board(vr,56,255,win);

    // Drawing the red checkers.
    Vector_ref<Rectangle> rch;                      // Red checkers.
    draw_red_checkers(rch,Color::red,win);

    // Drawing the white checkers.
    Vector_ref<Rectangle> wch;     // White checkers.
    draw_white_checkers(wch,Color::white,win);
    
    win.wait_for_button();
    //rch[9].move(-100,100);
    move_red_checkers(rch);

    win.wait_for_button();
    return 0;
}

//------------------------------------------------------------------------------
