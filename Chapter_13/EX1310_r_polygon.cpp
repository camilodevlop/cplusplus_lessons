/*Define a class Regular_polygon. Use the center, the number of sides (>2)
and the distance from the center to a corner as constructor arguments.*/

#include <iostream>
#include <cmath>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Regular_polygon : Shape
{
	Regular_polygon(Point,int,double);

	private:
		Point c; 		// Polygon center.
		int n_s; 		// Number of sides.
		double r; 		// Radius.
};

//------------------------------------------------------------------------------

Regular_polygon::Regular_polygon(Point center,int n_sides,double rad)
				 				:c{center},n_s{n_sides},r{rad}
{
	if(n_s < 3)	
		error("\n\n\tThe sides are not enough.\n\t");

	double inc_ang{2*M_PI/n_sides};
	double x,y;

	for(int i=1; i <= n_s; ++i)
	{
		x = r * cos(i*inc_ang);
		y = r * sin(i*inc_ang);
		add(Point{static_cast<int>(c.x + x), static_cast<int>(c.y + y)});
	}
	
	add(Point{point(0).x,point(0).y}); 		// Closes the polygon.
}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;	

	int sw{1000}; 				// Size width. 
	int sh{800}; 				// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,sh,"Chapter 13 - EX1310"};

	Point pp{400,400};
	int n_sides{10};
	double radius = 150;
	Regular_polygon rp{pp,n_sides,radius};
	win.attach(rp);

	win.wait_for_button();
	return 0;

}

//------------------------------------------------------------------------------
