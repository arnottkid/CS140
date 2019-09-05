/* roster_02_main.cpp has the user pass the number of columns for the HTML on the 
   command line.  It passes this to the Print() method of the Roster class. */

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "roster_02.hpp"
using namespace std;

int main(int argc, char **argv)
{
  Roster r;
  ifstream fin;
  istringstream ss;
  int columns;
  string line;

  /* Parse the command line and exit if there is an error. */

  try {
    if (argc != 3) throw((string) "usage: roster_02_main filename columns");
    ss.str(argv[2]);
    if (!(ss >> columns) || columns <= 0) throw((string) "bad columns specification.");

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  /* Open the specified file, and exit if there is an error. */

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); return 1; }
  
  /* Add all of the names to the roster, and then call the Print() method. */

  while (getline(fin, line)) {
    if (!r.Add_Line(line)) fprintf(stderr, "Line not the right format: %s\n", line.c_str());
  }

  r.Print(columns);
  return 0;
}
