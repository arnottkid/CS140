// roster_06.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include <fstream>
#include <sstream>
#include "roster_06.h"

main(int argc, char **argv)
{
  Roster *r;
  ifstream fin;
  istringstream ss;
  string name, a4;
  int columns, starting_number, print_names;

  if (argc != 5) {
    cerr << "usage: roster_main filename starting_number columns print_names(yes/no)\n";
    exit(1);
  }

  srand48(time(0));

  ss.clear(); ss.str(argv[2]); 
  if (!(ss >> starting_number)) {
    cerr << "usage: roster_main filename starting_number columns print_names(yes/no) -- bad starting number\n";
    exit(1);
  }

  ss.clear(); ss.str(argv[3]); 
  if (!(ss >> columns) || columns <= 0) {
    cerr << "usage: roster_main filename starting_number columns print_names(yes/no) -- bad columns specification\n";
    exit(1);
  }

  a4 = argv[4];
  if (a4 == "yes") {
    print_names = 1;
  } else if (a4 == "no") {
    print_names = 0;
  } else {
    cerr << "usage: roster_main filename starting_number columns print_names(yes/no)\n";
    cerr << "print_names must be yes or no\n";
    exit(1);
  }

  r = new Roster(starting_number);

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); exit(1); }
  
  while (getline(fin, name)) r->Add_name(name);
  r->Print(columns, print_names);
}
