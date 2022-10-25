/* 1. Make a completely new project.
 * 2. Using the facilities of Graph_lib, type in the line-drawing program from 
 16.5 and get it to run.*/

#include <iostream>
#include <string>
#include "GUI/GUI.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window
{
	Lines_window(Point xy,int w,int h,const string& title);

	private:
		Open_polyline lines;
		Button next_button;
		Button quit_button;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu; 				// The menu.
		Button menu_button;
		Menu l_style_menu;

		void next();
		void quit();

		// Actions invoked by callbacks.
		static void cb_red(Address,Address pw) 	  // Callback for red button.
		{reference_to<Lines_window>(pw).red_pressed();}
		static void cb_blue(Address,Address pw)   // Callback for blue button.
		{reference_to<Lines_window>(pw).blue_pressed();}
		static void cb_black(Address,Address pw)  // Callback for black button.
		{reference_to<Lines_window>(pw).black_pressed();}	
		static void cb_menu(Address,Address pw)   // Callback for menu button.
		{reference_to<Lines_window>(pw).menu_pressed();}

		static void cb_solid(Address,Address pw)
		{reference_to<Lines_window>(pw).solid_pressed();}
		static void cb_dot(Address,Address pw)
		{reference_to<Lines_window>(pw).dot_pressed();}

		// The actions.
		void red_pressed(){change(Color::red); hide_menu(); redraw();}
		void blue_pressed(){change(Color::blue); hide_menu(); redraw();}
		void black_pressed(){change(Color::black); hide_menu(); redraw();}
		void change(Color c){lines.set_color(c);}

		void hide_menu(){color_menu.hide(); menu_button.show(); redraw();}
		void menu_pressed(){menu_button.hide(); color_menu.show(); redraw();}
		
		void solid_pressed(){change_l_style(Line_style::solid); redraw();}
		void dot_pressed(){change_l_style(Line_style::dot); redraw();}
		void change_l_style(Line_style ls){lines.set_style(ls);} //Line_style(ls)

};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy,int w,int h,const string& title)
			: Window{xy,w,h,title},
			  next_button{Point{x_max()-150,0},70,20,"Next point",
			  [](Address,Address pw){reference_to<Lines_window>(pw).next();}},
			  quit_button{Point{x_max()-70,0},70,20,"Quit",
			  [](Address,Address pw){reference_to<Lines_window>(pw).quit();}},
			  next_x{Point{x_max()-310,0},50,20,"next x:"},
			  next_y{Point{x_max()-210,0},50,20,"next y:"},
			  xy_out{Point{100,0},100,20,"current(x,y):"},
			  color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
			  menu_button{Point{x_max()-80,30},80,20,"color menu",cb_menu},
			  l_style_menu{Point{x_max()-70,100},70,20,Menu::vertical,"Line style"}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");

	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	attach(color_menu);
	color_menu.hide(); 				// Menu initial state: hidden.

	l_style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
	l_style_menu.attach(new Button{Point{0,0},0,0,"dotted",cb_dot});
	attach(l_style_menu);

	attach(menu_button);
	attach(lines);
}

//------------------------------------------------------------------------------

void Lines_window::next()
{
	int x=next_x.get_int();
	int y=next_y.get_int();
	lines.add(Point{x,y});

	// Update current position readout.
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

//------------------------------------------------------------------------------

void Lines_window::quit()
{
	hide();
}

//------------------------------------------------------------------------------

int main()
{
	try
	{
		Lines_window win{Point{100,100},600,400,"lines"};
		return gui_main();
	}	
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch(...)
	{
		cerr << "Some exception.\n";
		return 2;
	}
}

//------------------------------------------------------------------------------
