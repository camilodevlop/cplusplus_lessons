/*Define a class Arc. */

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Arc:Shape
{
	Arc(Point p, int w, int h, int ang_0, int ang_f);

	// Nonmodifying functions.
	void draw_lines() const;
	Point center() const;

	private:
		int w;
		int h;
		int ang_0;
		int ang_f;
};

//------------------------------------------------------------------------------

Arc::Arc(Point p, int ww, int hh, int a_0, int a_f)
	:w{ww}, h{hh}, ang_0{a_0}, ang_f{a_f}
{
	add(Point{p.x-w,p.y-h});
}

//------------------------------------------------------------------------------

Point Arc::center() const
{
	return {point(0).x+w,point(0).y+h};
}

//------------------------------------------------------------------------------

void Arc::draw_lines() const
{
	if(color().visibility())
		fl_arc(point(0).x,point(0).y,w+w,h+h,ang_0,ang_f);
}

//------------------------------------------------------------------------------

int main()
{
	
	using namespace Graph_lib;
	
	int sw = 800; 					// Size width.
	int hw = 1000; 					// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,hw,"Chapter 13 - EX131"};

	Arc ac{Point{400,400},60,30,0,90};
	win.attach(ac);

	Arc ac1{Point{300,400},60,30,90,180};
	win.attach(ac1);

	win.wait_for_button();
	return 0;
}

//------------------------------------------------------------------------------
