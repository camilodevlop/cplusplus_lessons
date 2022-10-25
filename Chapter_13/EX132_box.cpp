/*Draw a box with rounded corners. Define a class Box, consisting of four lines
and four arcs.*/

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Box : public Lines
{
	Box(Point pp, int ww, int hh);
	
	// Nonmodifying functions.
	void draw_lines() const;

	private:
		int w;
		int h;
		Point p;
};

//------------------------------------------------------------------------------

Box::Box(Point pp, int ww, int hh) : p{pp}, w{ww}, h{hh}
{
	// Minimum size.
	if(w <= 65 || h <= 65)
		error("\n\n\tBad rectangle: non positive side.\n\t");

	// Vertical lines points.
	Lines::add(Point{p.x,p.y + 15},Point{p.x,p.y + h - 15});
	Lines::add(Point{p.x + w,p.y + 15},Point{p.x + w,p.y + h - 15});

	// Horizontal line points.
	Lines::add(Point{p.x + 15,p.y},Point{p.x + w - 15,p.y});
	Lines::add(Point{p.x + 15,p.y + h},Point{p.x + w - 15,p.y + h});
	
	draw_lines();
}

//------------------------------------------------------------------------------

void Box::draw_lines() const
{
	Lines::draw_lines();

	if(color().visibility())
	{
		fl_arc(p.x,p.y,31,31,90,180);
		fl_arc(p.x,p.y + h - 30,31,31,180,270);
		fl_arc(p.x + w -30,p.y,31,31,0,90);
		fl_arc(p.x + w - 30,p.y + h - 30,31,31,270,360);
	}
}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;
	
	int sw = 1000; 					// Size width.
	int hw = 800; 					// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,hw,"Chapter 13 - EX132"};

	Box by{Point{200,200},500,200};
	win.attach(by);

	Box by1{Point{400,500},100,100};
	win.attach(by1);

	win.wait_for_button();
	return 0;
}

//------------------------------------------------------------------------------
