// roster_02.h
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Roster {
  public:
    void Add_name(string name);
    void Print(int columns);
  protected:
    vector <string> names;
};
