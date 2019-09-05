/* The only change from roster_01.hpp is that I'm adding a parameter to the
   Print method.  This is the number of columns to print the HTML table. */

#pragma once
#include <vector>
#include <string>

class Roster {
  public:
    bool Add_Line(const std::string &line);
    void Print(int columns) const;             // This is the only changed line in the header.
  protected:
    std::vector <std::string> Names;
    std::vector <std::string> Photos;
};
