/* roster_03_main.cpp shows my preffered way to handler the constructor with its
   parameter.  You call "new Roster(columns)" which returns a pointer to an instance
   of the class.   You treat the pointer pretty much identically to the instance
   in roster_02.cpp; however, you access the methods with "->" instead of ".", and
   when you're done with it, you should delete it. */

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "roster_03.hpp"
using namespace std;

int main(int argc, char **argv)
{
  Roster *r;
  ifstream fin;
  istringstream ss;
  int columns;
  string line;

  /* Parse the command line and exit if there is an error. */

  try {
    if (argc != 3) throw((string) "usage: roster_03_main filename columns");
    ss.str(argv[2]);
    if (!(ss >> columns) || columns <= 0) throw((string) "bad columns specification.");
    r = new Roster(columns);

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  /* Open the specified file, and exit if there is an error. */

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); return 1; }
  
  /* Add all of the names to the roster, and then call the Print() method. */

  while (getline(fin, line)) {
    if (!r->Add_Line(line)) fprintf(stderr, "Line not the right format: %s\n", line.c_str());
  }

  r->Print();

  /* This delete call isn't necessary, because the program is over, but it's good practice
     to delete a pointer when you've created it with new, and you are done with it. */

  delete r;
  
  return 0;
}
