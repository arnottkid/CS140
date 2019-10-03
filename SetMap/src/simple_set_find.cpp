/* This program reads lines from a file and stores them in a set.
   It then queries the user for names, and uses the find() method to find them in the set.
   It returns whether or not it was successful. */

#include <set>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  string s, filename;
  ifstream f;
  set <string> names;

  /* Error check the command line. */

  try {
    if (argc != 2) throw((string) "usage: simple_set_find file");
    filename = argv[1];
    f.open(filename.c_str());
    if (f.fail()) throw((string) ("could not open " + filename));
  } catch (const string s) {
    cerr << s << endl;
    return 0;
  }

  /* Read the lines and insert them into the set */

  while(getline(f, s)) names.insert(s);
  f.close();

  /* Now query the user, and try to find the name.  Print out whether it was successful. */

  while (1) {
    cout << "Enter a name: ";
    cout.flush();                    // Don't worry about this too much -- I do this
                                     // to make sure that the string is printed to the screen.
                                     // Sometimes, partial lines aren't printed immediately,
                                     // and cout.flush() forces the partial line to be printed.
    if (!getline(cin, s)) return 0;
    if (names.find(s) == names.end()) {
      cout << s << " is not in the set.\n";
    } else {
      cout << s << " is in the set.\n";
    }
  }
} 
