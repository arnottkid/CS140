/* roster_03C_bad.cpp is not much better than roster_03B_bad.cpp  It "gets away" with
   declaring the instance of Roster with the other variables by creating a new procedure
   that uses "columns" as a parameter, and then it declares the instance of Roster with
   columns as a parameter.

   Again, I'm not a fan, largely because the variable declarations *are* executing code
   here, and when they throw an exception, it must be caught by the caller.
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "roster_03.hpp"
using namespace std;

void add_lines_and_print_roster(int columns, ifstream &fin)
{
  Roster r(columns);
  string line;

  while (getline(fin, line)) {
    if (!r.Add_Line(line)) fprintf(stderr, "Line not the right format: %s\n", line.c_str());
  }
  
  r.Print();
}

int main(int argc, char **argv)
{
  ifstream fin;                 
  istringstream ss;
  int columns;

  try {
    if (argc != 3) throw((string) "usage: roster_03_main filename columns");
    ss.str(argv[2]);
    if (!(ss >> columns) || columns <= 0) throw((string) "bad columns specification.");

    fin.open(argv[1]);
    if (fin.fail()) { perror(argv[1]); return 1; }
    
    add_lines_and_print_roster(columns, fin);

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  return 0;
}
