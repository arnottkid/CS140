// roster_02_main.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include <fstream>
#include <sstream>
#include "roster_02.h"

main(int argc, char **argv)
{
  Roster r;
  ifstream fin;
  istringstream ss;
  string name;
  int columns;

  if (argc != 3) {
    cerr << "usage: roster_main filename columns\n";
    exit(1);
  }

  ss.str(argv[2]); 
  if (!(ss >> columns) || columns <= 0) {
    cerr << "usage: roster_main filename columns -- bad columns specification\n";
    exit(1);
  }

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); exit(1); }
  
  while (getline(fin, name)) r.Add_name(name);
  r.Print(columns);
}
