#include <set>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

main(int argc, char **argv)
{
  string s;
  ifstream f;
  set <string> names;

  if (argc != 2) { cerr << "usage: simple_set_find file\n"; exit(1); }

  f.open(argv[1]);
  if (f.fail()) { perror(argv[1]); exit(1); }

  while(getline(f, s)) names.insert(s);
  f.close();

  while (1) {
    cout << "Enter a name: ";
    cout.flush();                    // Don't worry about this too much -- I do this
                                     // to make sure that the string is printed to the screen.
                                     // Sometimes, partial lines aren't printed immediately,
                                     // and cout.flush() forces the partial line to be printed.
    if (!getline(cin, s)) exit(0);
    if (names.find(s) == names.end()) {
      cout << s << " is not in the set.\n";
    } else {
      cout << s << " is in the set.\n";
    }
  }
} 
