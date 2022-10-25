/*Define a class Octagon to be a regular octagon. Write a test that exercises all
of its functions (as defined by you or inherited from Shape).*/

#include <iostream>
#include <cmath>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Octagon : Shape
{
	Octagon(Point,double);

	private:
		Point c; 		// Octagon center.
		double r; 		// Radius.
};

//------------------------------------------------------------------------------

Octagon::Octagon(Point center,double rad) : c{center}, r{rad}
{
	double inc_ang{2*M_PI/8};
	double x,y;

	for(int i=1; i <= 8; ++i)
	{
		x = r * cos(i*inc_ang);
		y = r * sin(i*inc_ang);
		add(Point{static_cast<int>(c.x + x), static_cast<int>(c.y + y)});
	}
	
	add(Point{point(0).x,point(0).y}); 		// Closes the octagon.
}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;	

	int sw{1000}; 				// Size width. 
	int sh{800}; 				// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,sh,"Chapter 14 - EX148"};

	Point pp{400,400};
	double radius = 150;
	Octagon oc{pp,radius};
	win.attach(oc);
	
	oc.move(200,-200);
	
	oc.set_color(Color::blue);
	cout << "\n\n\tThe color is:    " << oc.color().as_int();
	
	oc.set_style(Line_style::dashdot);
	cout << "\n\n\tThe line style is:    " << oc.style().style();
	
	oc.set_fill_color(Color::yellow);
	//cout << "\n\n\tThe fill color is: "<<oc.fill_color(); // It doesn't work.

	Point ocp{oc.point(1)};
	cout << "\n\n\tx = " << ocp.x << " y = " << ocp.y;
	cout << "\n\n\tThe number of points is: " << oc.number_of_points();

	win.wait_for_button();
	return 0;

}

//------------------------------------------------------------------------------
