/*Define a class Arrow, which draws a line with an arrowhead.*/

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Arrow : Shape 
{
	Arrow(Point,Point);

	private:
		Point p1;
		Point p2;
};

//------------------------------------------------------------------------------

Arrow::Arrow(Point pp1, Point pp2) : p1{pp1}, p2{pp2}
{
	// Useful for determining direction.
	int dx{p2.x-p1.x};
	int dy{p2.y-p1.y};

	// Useful for tracing the arrow triangle.
	int x_aux{p1.x+int(0.95*dx)};
	int y_aux{p1.y+int(0.95*dy)};

	// Useful for assigning the size of the triangle.
	int inc_x = 10;
	int inc_y = 10;

	Point p_right;
	Point p_left;

	// Quadrant 1.
	if(dx>0 && dy<=0)
	{
		p_left.x = x_aux-inc_x;
		p_left.y = y_aux-inc_y;

		p_right.x = x_aux+inc_y;
		p_right.y = y_aux+inc_y;
	
	}

	// Quadrant 2.
	if(dx<=0 && dy<0)
	{
		p_left.x = x_aux-inc_x;
		p_left.y = y_aux+inc_y;

		p_right.x = x_aux+inc_y;
		p_right.y = y_aux-inc_y;
	}

	// Quadrant 3.
	if(dx<0 && dy>=0)
	{
		p_left.x = x_aux+inc_x;
		p_left.y = y_aux+inc_y;

		p_right.x = x_aux-inc_y;
		p_right.y = y_aux-inc_y;
	}
	
	// Quadrant 4.
	if(dx>=0 && dy>0)
	{
		p_left.x = x_aux+inc_x;
		p_left.y = y_aux-inc_y;

		p_right.x = x_aux-inc_y;
		p_right.y = y_aux+inc_y;
	}

	// Tracing the arrow.
	add(p1);
	add(Point{x_aux,y_aux});
	add(p_right);
	add(p2);
	add(p_left);
	add(Point{x_aux,y_aux});
}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;
	
	int sw = 1000; 					// Size width.
	int hw = 1000; 					// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,hw,"Chapter 13 - EX133"};

	Arrow ar{Point{600,600},Point{700,350}};
	win.attach(ar);

	Arrow ar2{Point{600,600},Point{500,350}};
	win.attach(ar2);

	Arrow ar3{Point{600,600},Point{500,850}};
	win.attach(ar3);
	
	Arrow ar4{Point{600,600},Point{700,850}};
	win.attach(ar4);

	win.wait_for_button();
	return 0;
	
}

//------------------------------------------------------------------------------
