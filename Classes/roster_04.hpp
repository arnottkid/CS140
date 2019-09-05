/* Instead of passing the number of columns to Print(), instead define a constructor
   that takes the number of columns, and store it with the Roster class. */

#pragma once
#include <vector>
#include <string>
#include "MOA.hpp"

class Roster {
  public:
    Roster(int columns, int seed, const std::string );
    bool Add_Line(const std::string &line);
    void Print() const;
  protected:
    MOA Rng;
    int Columns;
    std::vector <std::string> Names;
    std::vector <std::string> Photos;
};
