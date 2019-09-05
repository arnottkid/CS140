/* roster_03B_bad.cpp, to me, shows bad programming practice.  Now, instead of calling
   new, I declare the instance of Roster in the middle of my code.  I have to, because I cannot
   declare it, and therefore call its constructor, until I have parsed the variable columns.

   I believe that this is bad programming practice, because I believe you should have all of
   your variable declarations at the top of your procedures and methods, before you start 
   any code.  Once you start writing code, you should not then declare more variables.

   This is my opinion, by the way, and is not shared by everyone. */

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "roster_03.hpp"
using namespace std;

int main(int argc, char **argv)
{
  ifstream fin;                 /* I don't declare Roster here, because I can't */
  istringstream ss;
  int columns;
  string line;

  try {
    if (argc != 3) throw((string) "usage: roster_03_main filename columns");
    ss.str(argv[2]);
    if (!(ss >> columns) || columns <= 0) throw((string) "bad columns specification.");

    /* Instead, I declare it here, after I know columns.  You'll note that I can't
       close the try clause after this, because then r will be undefined.  So, instead,
       I have to extend my try clause all the way until I am done with r. */

    Roster r(columns);

    fin.open(argv[1]);
    if (fin.fail()) { perror(argv[1]); return 1; }
    
    while (getline(fin, line)) {
      if (!r.Add_Line(line)) fprintf(stderr, "Line not the right format: %s\n", line.c_str());
    }
  
    r.Print();

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  return 0;
}
