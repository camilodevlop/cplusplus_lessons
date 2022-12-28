# cplusplus_lessons

In this repository I share most of the solutions for the exercises proposed in the book "Programming Principles and Practice Using C++" second edition. The exercises are related to the topics referred below. Before taking a bootcamp I decided to learn from this book because the author explains in depth the concepts of programming. It's just that I like to know the why of things and then apply them.

CHAPTER 1 - COMPUTERS, PEOPLE, and PROGRAMMING: Information only (no coding).

CHAPTER 2 - HELLO, WORLD!: programs, the classic first program, compilation, linking, programming environments.

CHAPTER 3 - OBJECTS, TYPES, and VALUES: input, variables, input on type, operations and operators, assignment
and initialization, composite assignment operators, names, types and objects, type safety.

CHAPTER 4 - COMPUTATION: computation, objectives and tools, expressions, statements, fucntions, vector, lan-
guage features.

CHAPTER 5 - ERRORS: sources of errors, compile-time errors, link-time errors, run-time errors, exceptions,
logic errors, estimation, debugging, pre- and post-conditions, testing.

CHAPTER 6 - WRITING A PROGRAM: a problem, thinking about the problem, grammars, turning a grammar into code,
token streams, program structure.

CHAPTER 7 - COMPLETING A PROGRAM: introduction, input and output, error handling, negative numbers, cleaning
up the code, recovering from errors, variables.

CHAPTER 8 - TECHNICALITIES: technicalities, declarations and definitions, header files, scope, function call
and return, order of evaluation, namespaces.

CHAPTER 9 - TECHNICALITIES: classes, user-defined types, classes and members, interface and implementation,
evolving a class, enumerations, operator overloading, class interfaces.

CHAPTER 10 - INPUT AND OUTPUT STREAMS: input and output, the I/O stream model, files, opening a file, reading
and writing a file, I/O error handling, reading a single value, user-defined output operators, user-defined 
input operators, a standard input loop, reading a structure file.

CHAPTER 11 - CUSTOMIZING INPUT AND OUTPUT: regularity and irregularity, output formating, file opening and
positioning, string streams, line-oriented input, character classification, using nonstandard separators.

CHAPTER 12 - A DISPLAY MODEL: a display model, using a GUI library, coordinates, shapes, using shape 
primitives.

CHAPTER 13 - GRAPHICS CLASSES: overview of graphics classes (point and line, lines, color, line_style,
polygon, rectangle, etc).

CHAPTER 14 - GRAPHICS CLASS DESIGN: design principles, shape, base and derived classes, benefits of
object-oriented programming.

CHAPTER 15 - GRAPHING FUNCTIONS AND DATA: graphing simple functions, function, axis, approximation, graphing
data.

CHAPTER 16 - GRAPHICAL USER INTERFACES: the "next" button, a simple window, button and other widgets, an
example, control inversion, adding a menu, debugging GUI code.

CHAPTER 17 - VECTOR AND FREE STORE: vector basics, memory, addresses, pointers, free store and pointers,
destructors, access to elements, pointers to class objects, void* and casts, pointers and references, the
this pointer.

CHAPTER 18 - VECTORS AND ARRAYS: initialization, copying, essential operations, access to vector elements,
arrays.

CHAPTER 19 - VECTOR, TEMPLATES, AND EXCEPTIONS: the problems, changing size, templates, range checking and
exceptions, resources and exceptions.

CHAPTER 20 - CONTAINERS AND ITERATORS: storing and processing data, STL ideals, sequences and iterators,
linked lists, generalizing vector yet again, a simple text editor, vector, list, string, adapting our vector
to the STL, adapting built-in arrays to the STL, container overview.

------------------------------------------------------------------------------------------------------------

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
