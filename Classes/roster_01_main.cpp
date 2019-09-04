// roster_01_main.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//

#include <fstream>
#include "roster_01.h"

main(int argc, char **argv)
{
  Roster r;
  ifstream fin;
  string name;

  if (argc != 2) {
    cerr << "usage: roster_main filename\n";
    exit(1);
  }

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); exit(1); }
  
  while (getline(fin, name)) r.Add_name(name);
  r.Print();
}
