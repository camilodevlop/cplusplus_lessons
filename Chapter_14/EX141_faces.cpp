/*Define two classes Smiley and Frowny from Circle (have two eyes and mouth).
 Next derive from Smiley and Frowny which add an appropiate hat to each.*/

#include <iostream>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class Smiley : public Circle
{
	public:
		Smiley(Point pp,int rr) : Circle{pp,rr} {}
		void draw_lines() const;
};

//------------------------------------------------------------------------------

void Smiley::draw_lines() const 
{
	Circle::draw_lines(); 			// Draw a circle.
	
	int r{radius()}; 				// radius() of the Circle class.
	Point pc{center()}; 			// center() of the Circle class.

	// Used to draw the mouth and eyes.
	int inc{static_cast<int>(1.0/2 * r)};
	int inc2{static_cast<int>(1.0/4 * r)};

	// Draws the happy mouth.
	if(color().visibility())
		fl_arc(pc.x-inc,pc.y,2*inc,inc,180,360);

	// Draws the eyes.
	fl_line(pc.x-inc,pc.y-inc,pc.x-inc,pc.y-inc+inc2);
	fl_line(pc.x+inc,pc.y-inc,pc.x+inc,pc.y-inc+inc2);

	return;
}

//------------------------------------------------------------------------------

struct Hat_smiley : Smiley
{
	Hat_smiley(Point pp,int rr) : Smiley{pp,rr} {}
	void draw_lines() const;
};

//------------------------------------------------------------------------------

void Hat_smiley::draw_lines() const
{
	// Activate if you want to draw the face from a Hat_smiley object.
	//Circle::draw_lines();
	//Smiley::draw_lines();

	int r{radius()};
	Point pc{center()}; 			// center() of the Circle class.

	// Used to draw the happy face hat.
	int inc{static_cast<int>(1.0/2 * r)};
	int inc2{static_cast<int>(1.0/4 * r)};

	// Draws the happy face hat.
	if(color().visibility())
	{
		fl_arc(pc.x-3*inc,pc.y-3*inc,6*inc,inc,180,360);
		fl_arc(pc.x-inc,(pc.y-2*inc-inc2),2*inc,inc,0,180);
	}
}

//------------------------------------------------------------------------------

class Frowny : public Circle
{
	public:
		Frowny(Point pp,int rr) : Circle{pp,rr} {}
		void draw_lines() const;
};

//------------------------------------------------------------------------------

void Frowny::draw_lines() const 
{
	//Circle::draw_lines(); 			// Draw a circle.
	
	int r{radius()}; 				// radius() of the Circle class.
	Point pc{center()}; 			// center() of the Circle class.

	// Used to draw the mouth and eyes.
	int inc{static_cast<int>(1.0/2 * r)};
	int inc2{static_cast<int>(1.0/4 * r)};

	// Draws the happy mouth.
	if(color().visibility())
		fl_arc(pc.x-inc,pc.y+inc2,2*inc,inc,0,180);

	// Draws the eyes.
	fl_line(pc.x-inc,pc.y-inc,pc.x-inc,pc.y-inc+inc2);
	fl_line(pc.x+inc,pc.y-inc,pc.x+inc,pc.y-inc+inc2);

	return;
}

//-----------------------------------------------------------------------------

struct Hat_frowny: Frowny
{
	Hat_frowny(Point pp,int rr) : Frowny{pp,rr} {}
	void draw_lines() const;
};

//------------------------------------------------------------------------------

void Hat_frowny::draw_lines() const
{
	// Using the inherited functions.
	Circle::draw_lines();
	Frowny::draw_lines();

	int r{radius()};
	Point pc{center()}; 			// center() of the Circle class.

	// Used to draw the happy face hat.
	int inc{static_cast<int>(1.0/2 * r)};
	int inc2{static_cast<int>(1.0/4 * r)};

	// Draws the happy face hat.
	if(color().visibility())
	{
		fl_arc(pc.x-3*inc,pc.y-2*inc,6*inc,inc,0,180);
		fl_arc(pc.x-inc,(pc.y-2*inc-inc2),2*inc,inc,0,180);
	}
}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;

	int sw = 1000; 					// Size width.
	int hw = 800; 					// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,hw,"Chapter 14 - EX141"};

	//Circle cr{Point{500,500},200};
	//win.attach(cr);
	//Circle cr2{Point{700,700},200};
	//cr2 = cr;

	Smiley sm{Point{300,400},100};
	win.attach(sm);
	Hat_smiley hs{Point{300,400},100};
	win.attach(hs);

	// No es necesario fr porque usamos Circle's and Frowny's draw_lines()
	// in Hat_frowny::Drawlines().
	//Frowny fr{Point{550,400},100};
	//win.attach(fr);
	Hat_frowny hf{Point{550,400},100};
	win.attach(hf);

	win.wait_for_button();

	return 0;
}

//------------------------------------------------------------------------------
