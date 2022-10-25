/*Drill of chapter 13.*/

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;

	// 1. Make a 800-by-1000 Simple_window.
	
	int sw = 800; 					// Size width.
	int hw = 1000; 					// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,hw,"Drill - Chapter 13"};

	
	// 2. Put an 8-by-8 grid on the leftmost part of the window.
	
	int x_grid = 100;
	int y_grid = 100;
	Lines grid;

	for(int x=x_grid; x<sw; x+=x_grid)
		grid.add(Point{x,0},Point{x,sw}); 			// Vertical line.
	
	for(int y=y_grid; y<=sw; y+=y_grid)
		grid.add(Point{0,y},Point{sw,y}); 			// Horizontal line.

	win.attach(grid);

	
	// 3. Make the squares of the diagonal red (use Rectangle).
	
	Vector_ref<Rectangle> vr;

	for(int x=0; x<sw; x+=x_grid)	
	{
		vr.push_back(new Rectangle{Point{x,x},100,100});
		vr[vr.size()-1].set_fill_color(Color::red);
		vr[vr.size()-1].set_color(Color::invisible);
		win.attach(vr[vr.size()-1]);
	}

	// 4. Find a 200-by-200-pixel image and place three copies on the grid.
	
	Image img1{Point{300,0},"rita.jpg"};
	win.attach(img1);

	Image img2{Point{500,0},"rita.jpg"};
	win.attach(img2);
	
	Image img3{Point{0,600},"rita.jpg"};
	win.attach(img3);


	// Add a 100-by-100 iamge. Have it move around from square to square using
	// "Next" button.
	
	Image img4{Point{0,0},"arrow.jpg"};
	win.attach(img4);

	for(int x=0; x<8; ++x)
	{
		for(int y=0; y<7; ++y)
		{
			win.wait_for_button();
			img4.move(100,0);
		}
		win.wait_for_button();
		img4.move(-700,100);
	}

	win.wait_for_button();
	return 0;
}
