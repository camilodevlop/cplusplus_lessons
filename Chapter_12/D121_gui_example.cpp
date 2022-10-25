//#include </usr/local/include/FL/Fl.H>
//#include </usr/local/include/FL/Fl_Box.H>
//#include </usr/local/include/FL/Fl_Window.H>

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl{100,100};
    Simple_window win{tl,600,400,"My Window"};
    
    // Triangule
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    
    // Axis x
    Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
    win.attach(xa);

    // Axis y
    Axis ya{Axis::y,Point{20,300},280,10,"y_axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);

    // Sine function
    Function sine{sin,0,100,Point{20,150},1000,50,50};
    win.attach(sine);

    // Rectangle
    Rectangle r{Point{200,200},100,50};
    win.attach(r);

    // Polyline
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);

    // Fill
    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    // Text
    Text t{Point{150,150},"Hello, graphical world!"};
    win.attach(t);
    t.set_font(Font::times_bold);
    t.set_font_size(20);

    // Images
    Image ii{Point{100,50},"image.jpg"};
    win.attach(ii);
    ii.move(100,200);

    // And much more
    Circle c{Point{100,200},50};
    Ellipse e{Point{100,200},75,25};
    e.set_color(Color::dark_red);
    Mark m{Point{100,200},'x'};
    
    ostringstream oss;
    oss << "Screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100,20},oss.str()};

    Image cal{Point{225,225},"snow_cpp.gif"};
    cal.set_mask(Point{40,40},200,150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);

    win.set_label("My Window");
    win.wait_for_button();
}

// GUI INSTALLATION 
//---------------------------------------------------------


// FLTK version downloaded: fltk-1.3.8-source.tar.bz2

// FLTK was installed following the instructions of README.OSX.txt 
//      HOW TO BUILD FLTK USING GCC

// A stable version of Stroustrup's FLTK interface used in Chapters 12-16 of his Principles and Practice book
// https://github.com/cortical-iv/hello_fltk

// The stable version was based in
// https://groups.google.com/g/ppp-public/c/Url2jZtSrVQ

// Command used
// g++ -w -Wall -std=c++17 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp D121_gui_example.cpp  `fltk-config --ldflags --use-images` -o D121_gui_example
