#include <iostream>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib; 

    try
    {
        Point tl{100,100};
        Simple_window win{tl,600,400,"EX121_rect_poly"};

        // Window does't fit in the screen:
        // the maximum of the screen is automatically assigned.
        // Simple_window win{tl,1800,1100,"EX121_rect_poly"}; 

        // Polygon
        Polygon poly;
        poly.add(Point{100,50}); 
        poly.add(Point{150,50}); 
        poly.add(Point{150,100}); 
        poly.add(Point{100,100}); 
        poly.set_color(Color::red);
        win.attach(poly);

        // Rectangle
        Rectangle r{Point{200,50},50,50};
        r.set_color(Color::blue);
        win.attach(r);

        // Execise 2: rectangle and text
        Rectangle rx{Point{200,150},100,30};
        Text t{Point{230,170},"Howdy!"};
        win.attach(rx);
        win.attach(t);

        // Exercise 3: initials
        Text t2{Point{100,300},"C"};
        t2.set_font_size(75);
        t2.set_font(Font::times_bold);
        t2.set_color(Color::yellow);
        win.attach(t2);

        Text t3{Point{150,300},"A"};
        t3.set_font_size(75);
        t3.set_font(Font::times_bold);
        t3.set_color(Color::blue);
        win.attach(t3);

        // Exercise 4: 3 by 3 tic-tac-toe.
        Rectangle r1{Point{250,200},50,50};
        r1.set_color(Color::black);
        r1.set_fill_color(Color::white);
        win.attach(r1);

        Rectangle r2{Point{300,200},50,50};
        r2.set_color(Color::black);
        r2.set_fill_color(Color::red);
        win.attach(r2);

        Rectangle r3{Point{350,200},50,50};
        r3.set_color(Color::black);
        r3.set_fill_color(Color::white);
        win.attach(r3);

        Rectangle r4{Point{250,250},50,50};
        r4.set_color(Color::black);
        r4.set_fill_color(Color::red);
        win.attach(r4);

        Rectangle r5{Point{300,250},50,50};
        r5.set_color(Color::black);
        r5.set_fill_color(Color::white);
        win.attach(r5);

        Rectangle r6{Point{350,250},50,50};
        r6.set_color(Color::black);
        r6.set_fill_color(Color::red);
        win.attach(r6);

        Rectangle r7{Point{250,300},50,50};
        r7.set_color(Color::black);
        r7.set_fill_color(Color::white);
        win.attach(r7);

        Rectangle r8{Point{300,300},50,50};
        r8.set_color(Color::black);
        r8.set_fill_color(Color::red);
        win.attach(r8);

        Rectangle r9{Point{350,300},50,50};
        r9.set_color(Color::black);
        r9.set_fill_color(Color::white);
        win.attach(r9);

        // Excercise 5: 1/4 inch frame - rectangle.
        Rectangle rex5{Point{448,274},1344,822};
        rex5.set_color(Color::red);
        rex5.set_style(Line_style(Line_style::solid,24));
        win.attach(rex5);

        // Excercise 6: shape doesn't fit in the window.
        //              window doesn't fit in the screen.

        // The object is partially seen for the first case.
        Circle c{Point{100,200},300};
        win.attach(c);


        win.wait_for_button();

        return 0;
    }
    catch(const exception& e)
    {
       cerr << e.what() << '\n';
       return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\t";
        return 1;
    }
}
