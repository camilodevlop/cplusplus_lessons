# cplusplus_lessons

In this repository I share most of the solutions for the exercises proposed in the book "Programming Principles and Practice Using C++" second edition. Before taking a bootcamp I decided to learn from this book because the author explains in depth the concepts of programming. It's just that I like to know the why of things and then apply them.


To compile the programs in chapters 12-16 you need the FLTK library.

FLTK version downloaded: fltk-1.3.8-source.tar.bz2

- FLTK was installed following the instructions of README.OSX.txt 

HOW TO BUILD FLTK USING GCC
A stable version of Stroustrup's FLTK interface used in Chapters 12-16 of his Principles and Practice book
https://github.com/cortical-iv/hello_fltk

The stable version was based in
https://groups.google.com/g/ppp-public/c/Url2jZtSrVQ

Command used
g++ -w -Wall -std=c++17 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp D121_gui_example.cpp  `fltk-config --ldflags --use-images` -o D121_gui_example
