// roster_06.h
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class Roster {
  public:
    Roster(int starting_number);
    void Add_name(string name);
    void Print(int columns, int print_names);
  protected:
    vector <string> names;
    int start;
};
