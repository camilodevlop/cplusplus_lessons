/* Define a class Controller with four virtual functions on(), off(), set_level
(int), and show(). Derive at least two classes from Controller. */

#include<iostream>
#include<string>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include "GUI/std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

class Controller
{
    public:
        virtual void on() {};
        virtual void off() {};
        virtual void set_level(int ) {};
        virtual void show() const {};
};

//------------------------------------------------------------------------------

// This derived class tests Controller. It prints out whether the class is set
// to on or off and waht is the current level.

class Controller_1 : public Controller
{
    public:
        class Invalid {};
        Controller_1(bool st, int lv) : state{st}, level{lv} {}

        void on() override {state = true;}
        void off() override {state = false;}
        void set_level(int lv) override {level = lv;}
        void show() const override;

    private:
        bool state;
        int level;

};

//------------------------------------------------------------------------------

void Controller_1::show() const
{
    state ?  cout << "\n\n\tState:\tON" : cout << "\n\n\tState:\tOFF"; 
    cout << "\n\tLevel\t" << level << "\n\n\t";
    
    return;
}

//------------------------------------------------------------------------------

struct Controller_2 : Controller
{
    Controller_2(bool st, int lv, Line& ll, Text& tt) :
                 state{st}, level{lv}, plevel{lv}, l{ll}, t{tt} {}
    
    void on() override {state = true;}
    void off() override {state = false;}
    void set_level(int lv) override {level = lv-level; plevel = lv;} 
    void show() const override;

    private:
        bool state;
        int level;
        int plevel;                             // Printable level.
        Line& l;
        Text& t;
};

//------------------------------------------------------------------------------

void Controller_2::show() const
{
    state? t.set_label("Status: ON\t\tLevel: " + to_string(plevel))
          :t.set_label("Status: OFF\t\tLevel: " + to_string(plevel));

    l.move(0,-level);
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        // Controller_1 test.
        Controller_1 c1{true,5};
        c1.show();

        // Controller_2 test.
        using namespace Graph_lib;

        int sw{1000};                           // Size width.
        int sh{800};                            // Size height.
        Point tl{100,100};
        Simple_window win{tl,sw,sh,"Chapter 14 - EX1416"};

        // Drawing the control panel.
        Text t{Point{200,100},"Controller"};
        t.set_font(Font::times_bold);
        t.set_font_size(20);
        win.attach(t);
    
        Text t2{Point{700,250},"Status: "};
        t2.set_font(Font::times_bold);
        t2.set_font_size(20);
        win.attach(t2);

        Rectangle rect{Point{400,200},200,400};
        win.attach(rect);

        Point plv{400,600};                     // Point level.
        Line lv{plv,Point{plv.x+200,plv.y}};
        win.attach(lv);

        Axis ya{Axis::y,Point{370,600},400,10,"Level 0-400"};
        win.attach(ya);

        win.wait_for_button();

        // Changing the parameters in an object of class Controller_2.
        Controller_2 c2{true,200,lv,t2};
        c2.show();
        win.wait_for_button();

        c2.off();
        c2.set_level(50);
        c2.show();
    
        win.wait_for_button();
        return 0;
    }
    catch(Controller_1::Invalid)
    {
        cerr << "\n\n\tException test.\n\t"; // You can use throw Invalid();
        return 1;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        cerr << "\n\n\tSomething is wrong.\n\n\t";
        return 1;
    }

}

//------------------------------------------------------------------------------
