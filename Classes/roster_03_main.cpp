/* roster_03_main.cpp reads two extra parameters on the command line -- the name of the
   directory that holds the pictures, and the name of the first picture.  These are 
   passed to the constructor of the Roster class.  Because of that, you need to declare
   a pointer to a Roster, and then call "new Roster()" with the two parameters. */

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
  string name;

  /* Parse the command line and exit if there is an error. */

  try {
    if (argc != 5) throw((string) "usage: roster_main filename columns directory first_filename");
    ss.str(argv[2]);
    if (!(ss >> columns) || columns <= 0) throw((string) "bad columns specification.");

    /* I'm calling the roster constructor with the directory name and first filename.
       If there's an error, it will throw a string exception, so we catch it here. */

    r = new Roster(argv[3], argv[4]);

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  /* The rest of the program is the same, except we use -> for the pointer, rather than . */

  fin.open(argv[1]);
  if (fin.fail()) { perror(argv[1]); return 1; }
  
  /* Add all of the names to the roster, and then call the Print() method. */

  while (getline(fin, name)) r->Add_Name(name);
  r->Print(columns);

  delete r;  /* This is unnecessary, because the process exits, but I'm putting it here
                just to show how you deallocate the Roster when you have allocated it with new. */
  return 0;
}
