// roster_03_main.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include <fstream>
#include <sstream>
#include "roster_03.h"

main(int argc, char **argv)
{
  ifstream fin;
  istringstream ss;
  string name;
  int columns, starting_number;

  if (argc != 4) {
    cerr << "usage: roster_main filename starting_number columns\n";
    exit(1);
  }

  ss.clear(); ss.str(argv[2]); 
  if (!(ss >> starting_number)) {
    cerr << "usage: roster_main filename starting_number columns -- bad starting number\n";
    exit(1);
  }

  ss.clear(); ss.str(argv[3]); 
  if (!(ss >> columns) || columns <= 0) {
    cerr << "usage: roster_main filename starting_number columns -- bad columns specification\n";
    exit(1);
  }

  Roster r(starting_number);

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); exit(1); }
  
  while (getline(fin, name)) r.Add_name(name);
  r.Print(columns);
}
