/* roster_01_main.cpp uses the Roster class, which is defined in roster_01.hpp and 
   implemented in roster_01.cpp.  This means that may use the public methods of the
   class, but not the protected data.  

   Here, it simply calls the Add_Name() method for every line of text in the file Roster.txt,
   and then in calls the Print() method. */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "roster_01.hpp"
using namespace std;

int main(int argc, char **argv)
{
  Roster r;
  ifstream fin;
  string line;

  /* Parse the command line and exit if there is an error. */

  if (argc != 2) {
    cerr << "usage: roster_01_main filename\n";
    return 1;
  }

  /* Open the specified file, and exit if there is an error. */

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); return 1; }
  
  /* Add all of the names to the roster, and then call the Print() method. 
     If a line can't be parsed, simply print the error message, but keep going. */

  while (getline(fin, line)) {
    if (!r.Add_Line(line)) fprintf(stderr, "Line not the right format: %s\n", line.c_str());
  }

  r.Print();
  return 0;
}
