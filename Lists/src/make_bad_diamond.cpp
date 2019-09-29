/* This program creates a long string of n less-than signs followed by n greater-than signs. */

#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  int i, nd;
  istringstream ss;

  if (argc != 2) {
    cerr << "usage: make_bad_diamond ndiamonds\n";
    exit(1);
  }

  ss.str(argv[1]);
  if (ss >> nd) {
    for (i = 0; i < nd; i++) cout << '<';
    for (i = 0; i < nd; i++) cout << '>';
    cout << endl;
  }
  return 0;
}
