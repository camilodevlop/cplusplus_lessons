/*1. Make a My_window which has two buttons, next and quit.
 2. Make a window -based on My_window- with a 4-by-4 checkerboard of square
 buttons. When pressed, a button performs a simple action.

WARNING: the code is wordy. Vector_ref and new Button were used in an attempt
to simplify the code. However, it was not possible to identify which of the 
buttons was activated. A class inheriting from Button is also implemented to 
identify the pressed buttons. This class was also not used because My_window
did not update its objects.*/

#include <iostream>
#include "GUI/GUI.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class My_window : public Graph_lib::Window
{
	public:
		My_window(Point xy,int w, int h, const string& title);

	private:
		Button next_button;
		Button quit_button;
		Out_box out;
		Button b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;

		void next();
		void quit();

		void b0_pressed() {out.put("B0 pressed"); redraw();}
		void b1_pressed(){out.put("B1 pressed"); redraw();}
		void b2_pressed(){out.put("B2 pressed"); redraw();}
		void b3_pressed(){out.put("B3 pressed"); redraw();}
		void b4_pressed(){out.put("B4 pressed"); redraw();}
		void b5_pressed(){out.put("B5 pressed"); redraw();}
		void b6_pressed(){out.put("B6 pressed"); redraw();}
		void b7_pressed(){out.put("B7 pressed"); redraw();}
		void b8_pressed(){out.put("B8 pressed"); redraw();}
		void b9_pressed(){out.put("B9 pressed"); redraw();}
		void b10_pressed(){out.put("B10 pressed"); redraw();}
		void b11_pressed(){out.put("B11 pressed"); redraw();}
		void b12_pressed(){out.put("B12 pressed"); redraw();}
		void b13_pressed(){out.put("B13 pressed"); redraw();}
		void b14_pressed(){out.put("B14 pressed"); redraw();}
		void b15_pressed(){out.put("B15 pressed"); redraw();}

		// Actions invoked by callbacks.
		static void cb_b0(Address,Address pw) 
		{reference_to<My_window>(pw).b0_pressed();}
		static void cb_b1(Address,Address pw) 
		{reference_to<My_window>(pw).b1_pressed();}
		static void cb_b2(Address,Address pw) 
		{reference_to<My_window>(pw).b2_pressed();}
		static void cb_b3(Address,Address pw) 
		{reference_to<My_window>(pw).b3_pressed();}
		static void cb_b4(Address,Address pw) 
		{reference_to<My_window>(pw).b4_pressed();}
		static void cb_b5(Address,Address pw) 
		{reference_to<My_window>(pw).b5_pressed();}
		static void cb_b6(Address,Address pw) 
		{reference_to<My_window>(pw).b6_pressed();}
		static void cb_b7(Address,Address pw) 
		{reference_to<My_window>(pw).b7_pressed();}
		static void cb_b8(Address,Address pw) 
		{reference_to<My_window>(pw).b8_pressed();}
		static void cb_b9(Address,Address pw) 
		{reference_to<My_window>(pw).b9_pressed();}
		static void cb_b10(Address,Address pw) 
		{reference_to<My_window>(pw).b10_pressed();}
		static void cb_b11(Address,Address pw) 
		{reference_to<My_window>(pw).b11_pressed();}
		static void cb_b12(Address,Address pw) 
		{reference_to<My_window>(pw).b12_pressed();}
		static void cb_b13(Address,Address pw) 
		{reference_to<My_window>(pw).b13_pressed();}
		static void cb_b14(Address,Address pw) 
		{reference_to<My_window>(pw).b14_pressed();}
		static void cb_b15(Address,Address pw) 
		{reference_to<My_window>(pw).b15_pressed();}

};

//------------------------------------------------------------------------------

My_window::My_window(Point xy,int w,int h,const string& title)
		 :Window{xy,w,h,title},
		  next_button{Point{x_max()-150,0},70,20,"Next",
		  [](Address,Address pw){reference_to<My_window>(pw).next();}},
		  quit_button{Point{x_max()-70,0},70,20,"Quit",
		  [](Address,Address pw){reference_to<My_window>(pw).quit();}},
		  out{Point{100,0},200,20,"Ad"},

		  b0{Point{40,40},40,40,"b0",cb_b0},
		  b1{Point{80,40},40,40,"b1",cb_b1},
		  b2{Point{120,40},40,40,"b2",cb_b2},
		  b3{Point{160,40},40,40,"b3",cb_b3},
		  b4{Point{40,80},40,40,"b4",cb_b4},
		  b5{Point{80,80},40,40,"b5",cb_b5},
		  b6{Point{120,80},40,40,"b6",cb_b6},
		  b7{Point{160,80},40,40,"b7",cb_b7},
		  b8{Point{40,120},40,40,"b8",cb_b8},
		  b9{Point{80,120},40,40,"b9",cb_b9},
		  b10{Point{120,120},40,40,"b10",cb_b10},
		  b11{Point{160,120},40,40,"b11",cb_b11},
		  b12{Point{40,160},40,40,"b12",cb_b12},
		  b13{Point{80,160},40,40,"b13",cb_b13},
		  b14{Point{120,160},40,40,"b14",cb_b14},
		  b15{Point{160,160},40,40,"b15",cb_b15}
{
	attach(next_button);
	attach(quit_button);
	attach(out);
	attach(b0); attach(b1); attach(b2); attach(b3); attach(b4); attach(b5); 
	attach(b6); attach(b7); attach(b8); attach(b9); attach(b10); attach(b11); 
	attach(b12); attach(b13); attach(b14); attach(b15);
}

//------------------------------------------------------------------------------

void My_window::next()
{
	out.put("Next button pressed!");
	redraw();
}

//------------------------------------------------------------------------------

void My_window::quit()
{
	hide();
}

//------------------------------------------------------------------------------

int main()
{
	try
	{
		My_window win{Point{100,100},600,400,"My window"};
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
