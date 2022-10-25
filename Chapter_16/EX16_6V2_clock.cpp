/*6_Version_2. Make an "analog clock", that is, a clock with hands that move.
In this version of the watch press the "Start" button to start the watch.
The "for" instruction -line xxx- indicates how many seconds the clock should move
-in this case 10 times-. The hands should update every second but the pc moves
them only after the 10 seconds. It is possible that while "Start" is activated,
the instructions of the clk() function are being accumulated in a buffer.*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>

#include "GUI/GUI.h"
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "GUI/std_lib_facilities.h"

using namespace std;
using chrono::system_clock;

//------------------------------------------------------------------------------
// Drawing the hands.

class Hands : public Line
{
    public:
    Hands(Point pp1,Point pp2) : ix{pp2.x}, iy{pp2.y}, Line{pp1,pp2} {}
    void draw_lines() const;
    void inc_x(int x) {ix = x;}
    void inc_y(int y) {iy = y;}

    private:
        int ix;
        int iy;
};

void Hands::draw_lines() const
{
    fl_line(point(0).x,point(0).y,ix,iy);
}
//------------------------------------------------------------------------------
// It gets the system time.

class S_clock
{
    public:
        S_clock() : h{0},m{0},s{0} {}
        void update();                                  // Update time function.
        Point move_hand(Point c, int rad, char ut);     // Move hand.
        int hour() const {return h;}
        int min() const {return m;}
        int sec() const {return s;}

    private:
        int h;                          // Hour.
        int m;                          // Minutes.
        int s;                          // Seconds.
};

//------------------------------------------------------------------------------

void S_clock::update()
{
    system_clock::time_point today = system_clock::now();
    time_t tt = system_clock::to_time_t(today);  // Www Mmm dd hh:mm:ss yyyy.
    string ss = ctime(&tt);                 // Converts a time_t to string.
    stringstream rs{ss};

    // Updating hours, minutes and seconds.
    rs.seekg(11); rs>>h; if(h>=12) h-=12;
    rs.seekg(14); rs>>m;
    rs.seekg(17); rs>>s;
}

//------------------------------------------------------------------------------

Point S_clock::move_hand(Point c, int rad, char ut)
{
    int n_x, n_y;                           // New x and y coordinates.

    // Adjust the position of the hands on the screen.
    int correction_m_n = 15;
    int correction_h = 3;

    switch(ut)
    {
        case 's':
            n_x = c.x + rad*cos((s-correction_m_n)*(2*M_PI/60));
            n_y = c.y + rad*sin((s-correction_m_n)*(2*M_PI/60));
            break;
        case 'm':
            n_x = c.x + rad*cos((m-correction_m_n)*(2*M_PI/60));
            n_y = c.y + rad*sin((m-correction_m_n)*(2*M_PI/60));
            break;
        case 'h': 
            n_x = c.x + rad*cos((h-correction_h)*(2*M_PI/12));
            n_y = c.y + rad*sin((h-correction_h)*(2*M_PI/12));
            break;
        default:
            error("The time unit is invalid.");
    }

    return Point{n_x,n_y};
}

//------------------------------------------------------------------------------

class My_window : public Graph_lib::Window
{
	public:
		My_window(Point xy,int w, int h, const string& title);

	private:
        int r;                  // This sets the length of the hands.
        S_clock sc;             // System time.

        // Clock hands.
        Point common;           // Hands common point.

        Hands sec_hand;           // Seconds hand.
        Hands min_hand;           // Minutes hand.
        Hands hr_hand;            // Hours hand.
         

        // Widgets.
		Button quit_button;
        Button start;

        // Functions.
		void quit();
        void clk();
};

//------------------------------------------------------------------------------

My_window::My_window(Point xy,int w,int h,const string& title)
         : Window{xy,w,h,title}, r{150}, common{300,200},
           sec_hand{common,Point{common.x+r,200}},
           min_hand{common,Point{common.x+(r-50),200}},
           hr_hand{common,Point{common.x+(r-100),200}},
           quit_button{Point{x_max()-70,0},70,20,"Quit",
		   [](Address,Address pw){reference_to<My_window>(pw).quit();}},
           start{Point{x_max()-140,0},70,20,"Start",
		   [](Address,Address pw){reference_to<My_window>(pw).clk();}}
{
    // Hands style.
    sec_hand.set_color(Color::red);
    sec_hand.set_style(Line_style{Line_style::solid,4});
    min_hand.set_color(Color::blue);
    min_hand.set_style(Line_style{Line_style::solid,3});
    hr_hand.set_color(Color::green);
    hr_hand.set_style(Line_style{Line_style::solid,2});

    attach(hr_hand);
    attach(min_hand);
    attach(sec_hand);
    attach(quit_button);
    attach(start);
}

//------------------------------------------------------------------------------

void My_window::quit()
{
    hide();
}

//------------------------------------------------------------------------------

void My_window::clk()
{
    Point t{0,0};
    
    for(int i=0; i<10; ++i)
	{
        this_thread::sleep_for(std::chrono::milliseconds(1000));
		sc.update();

    	// Second hand update.
    	t = sc.move_hand(common,r,'s');
    	sec_hand.inc_x(t.x); sec_hand.inc_y(t.y);

    	// Minute hand update.
    	t = sc.move_hand(common,r-50,'m');
    	min_hand.inc_x(t.x); min_hand.inc_y(t.y);

    	// Hour hand update.
    	t = sc.move_hand(common,r-100,'h');
    	hr_hand.inc_x(t.x); hr_hand.inc_y(t.y);

    	redraw();
	}
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        // Prints the time every second for ten seconds.
        /*S_clock sc;
        for(int i = 0; i<2; ++i)
        {
            sc.update();
            cout << "\n\n\t" << sc.hour() << '\t' << sc.min() << '\t' << sc.sec() << "\n\t";
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }*/
       
        My_window win{Point{100,100},600,400,"Clock"};
        return gui_main();
    }
    catch(exception& e)
    {
       cerr << "Exception " << e.what() << '\n';
    }
    catch(...)
    {
       cerr << "Some exception.\n";
       return 2;
    }

}

//------------------------------------------------------------------------------
