/* This is a basic class definition file for a program that I'm writing
   to learn students' names.  Its structure is a standard structure in C++,
   where a header file defines a class, and a separate C++ file, which includes
   the header, implements the methods.  Other C++ files can use the class and
   its methods.  This is typical modular code. */

/* The pragma line prevents this file from being included more than once, even if
   multiple files include it.  We also include the header for vectors, because
   we use them in the class defintion.

   You'll note that we don't say "using namespace std."  The reason is that some
   people don't like to use the standard namespace, so we will not force them to
   when they include our header file. As an unfortunate consequence, we now have to
   put "std::" in front of a lot of things, such as strings and vectors. */

#pragma once
#include <vector>
#include <string>

/* We're going to build up this class.  It starts with two arrays -- Names and Photos.
   The photo file in Photos[i] will correspond to the name in Names[i].  Add_Line() is
   a method that takes a line of text of the form "Name XX Photo", and breaks
   it into the name and photo, adding the name to the Names vector and the photo 
   into the Photos vector.  Print() simply prints them out. 

   Add_Line() returns a boolean to say whether it was successful. */

class Roster {
  public:
    bool Add_Line(const std::string &line);
    void Print() const;
  protected:
    std::vector <std::string> Names;
    std::vector <std::string> Photos;
};
