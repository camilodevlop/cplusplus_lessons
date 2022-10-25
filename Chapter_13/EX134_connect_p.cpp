/*Define fucntions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw().*/

#include <iostream>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

//------------------------------------------------------------------------------

Point n(Rectangle r)
{
	Point p{r.point(0).x + r.width()/2, r.point(0).y};
	return p;
}

//------------------------------------------------------------------------------

Point s(Rectangle r)
{
	Point p{r.point(0).x + r.width()/2, r.point(0).y + r.height()};
	return p;
}

//------------------------------------------------------------------------------

Point e(Rectangle r)
{
	Point p{r.point(0).x + r.width(), r.point(0).y + r.height()/2};
	return p;
}

//------------------------------------------------------------------------------

Point w(Rectangle r)
{
	Point p{r.point(0).x, r.point(0).y + r.height()/2};
	return p;
}

//------------------------------------------------------------------------------

Point center(Rectangle r)
{
	Point p{r.point(0).x + r.width()/2, r.point(0).y + r.height()/2};
	return p;
}

//------------------------------------------------------------------------------

Point ne(Rectangle r)
{
	Point p{r.point(0).x + r.width(), r.point(0).y};
	return p;
}

//------------------------------------------------------------------------------

Point se(Rectangle r)
{
	Point p{r.point(0).x + r.width(), r.point(0).y + r.height()};
	return p;
}

//------------------------------------------------------------------------------

Point nw(Rectangle r)
{
	Point p{r.point(0).x, r.point(0).y};
	return p;
}

//------------------------------------------------------------------------------

Point swt(Rectangle r)
{
	Point p{r.point(0).x, r.point(0).y + r.height()};
	return p;
}

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;
	
	int sw = 1000; 					// Size width.
	int hw = 1000; 					// Size height.
	Point tl{100,100};
	Simple_window win{tl,sw,hw,"Chapter 13 - EX134"};

	Point rp{150,100};
	int rw{200}; 					// Rectangle width.
	int rh{100}; 					// Rectangle height.

	Rectangle rect{rp,rw,rh};
	win.attach(rect);
	
	Point north = n({rp,rw,rh});
	cout << "\n\n\tNorth:\t" << north.x << '\t' << north.y;
	Point south = s({rp,rw,rh});
	cout << "\n\tSouth:\t" << south.x << '\t' << south.y;
	Point est = e({rp,rw,rh});
	cout << "\n\tEst:\t" << est.x << '\t' << est.y;
	Point west = w({rp,rw,rh});
	cout << "\n\tWest:\t" << west.x << '\t' << west.y;
	Point ctr = center({rp,rw,rh});
	cout << "\n\tCenter:\t" << ctr.x << '\t' << ctr.y;
	Point north_est = ne({rp,rw,rh});
	cout << "\n\tNorth_est:\t" << north_est.x << '\t' << north_est.y;
	Point south_est = se({rp,rw,rh});
	cout << "\n\tSouth_est:\t" << south_est.x << '\t' << south_est.y;
	Point north_west = nw({rp,rw,rh});
	cout << "\n\tNorth_west:\t" << north_west.x << '\t' << north_west.y;
	Point south_west = swt({rp,rw,rh});
	cout << "\n\tSouth_west:\t" << south_west.x << '\t' << south_west.y;

	Marks pp{"x",{{north.x,north.y},{south.x,south.y},{est.x,est.y},
			{west.x,west.y},{ctr.x,ctr.y},{north_est.x,north_est.y},
			{south_est.x,south_est.y},{north_west.x,north_west.y},
			{south_west.x,south_west.y}}};
	win.attach(pp);

	win.wait_for_button();
	return 0;
}

//------------------------------------------------------------------------------
