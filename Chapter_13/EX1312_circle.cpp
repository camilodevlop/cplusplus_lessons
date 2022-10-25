/*Draw a circle. Move a mark around on the circle (let it move a bit each time
 you hit the "Next" button.)*/

#include <iostream>
#include <cmath>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;	

	int sw{1000}; 				// Size width. 
	int sh{800}; 				// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,sh,"Chapter 13 - EX1312"};

	// Circle.
	Circle c{Point{200,400},150};
	win.attach(c);
	Point center = c.center();
	//cout << "\n\n\tCenter =   " << center.x << "\t" << center.y << "\n\t";
	int rad = c.radius();
	//cout << "\n\n\tRadius =   " << rad << "\n\t";

	// Mark.
	int inc = 12; 					// Angle increment.
	double inc_ang{2*M_PI/inc};
	Point ip{center.x + rad,center.y};
	Mark m{ip,'x'};
	win.attach(m);

	int n_x;
	int n_y;

	for(int i=1; i<=inc; ++i)
	{
		win.wait_for_button();
		n_x = center.x + rad*cos(i*inc_ang);
		n_y = center.y - rad*sin(i*inc_ang); 
		m.move(n_x - ip.x, n_y - ip.y);
		ip = {n_x,n_y};
	}

	win.wait_for_button();
	return 0;
}

//------------------------------------------------------------------------------
