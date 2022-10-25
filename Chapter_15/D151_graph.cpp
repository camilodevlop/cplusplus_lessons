/*Function graphing drill.*/

#include<iostream>
#include<cmath>
#include"GUI/Simple_window.h"
#include"GUI/Graph.h"
#include"GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------
// One function.
double one(double){return 1;}

//------------------------------------------------------------------------------
// Slope function.
double slope(double x){return x/2;}

//------------------------------------------------------------------------------
// Square function.
double square(double x){return x*x;}

//------------------------------------------------------------------------------
// Sloping cos function.
double sloping_cos(double x){return cos(x)+slope(x);}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;

	constexpr int xmax = 600; 			// Window size.
	constexpr int ymax = 600; 				 
	constexpr int x_orig = xmax/2; 		// Window center (300,300).
	constexpr int y_orig = ymax/2;
	constexpr int xoffset = 100; 		// Spaces around the axes.
	constexpr int yoffset = 100;

	// Axis length and scales.
	constexpr int xlength = xmax - 2*xoffset;
	constexpr int ylength = ymax - 2*yoffset;
	constexpr double x_scala = double(xlength)/20;
	constexpr double y_scala = double(ylength)/20;

	Point tl{100,100};
	Simple_window win{tl,xmax,ymax,"Drill 15-1: Graphing Drill"};

	Axis x{Axis::x,Point{xoffset,y_orig},xlength,int(x_scala),"x"};
	win.attach(x);
	x.set_color(Color::red);
	x.label.move(-140,0);

	Axis y{Axis::y,Point{x_orig,ymax-yoffset},ylength,int(y_scala),"y"};
	win.attach(y);
	y.set_color(Color::red);

	Function s{one,-10,11,Point{x_orig,y_orig},400,x_scala,y_scala};
	win.attach(s);

	Function s1{slope,-10,11,Point{x_orig,y_orig},400,x_scala,y_scala};
	win.attach(s1);
	Text ts1{Point{xoffset-20,ymax-yoffset-100},"x/2"};
	win.attach(ts1);

	Function s2{square,-10,11,Point{x_orig,y_orig},400,x_scala,y_scala};
	win.attach(s2);

	Function s3{cos,-10,11,Point{x_orig,y_orig},400,x_scala,y_scala};
	win.attach(s3);
	s3.set_color(Color::blue);

	Function s4{sloping_cos,-10,11,Point{x_orig,y_orig},400,x_scala,y_scala};
	win.attach(s4);

	win.wait_for_button();
	return 0;
}
//------------------------------------------------------------------------------
