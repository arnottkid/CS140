/* This program reads lines from standard input, and inserts each line into a set.
   It then traverses the set and prints the lines.  This has the effect of sorting
   standard input (while stripping duplicates). */

#include <set>
#include <iostream>
using namespace std;

int main()
{
  string s;
  set <string> names;
  set <string>::const_iterator nit;

  while(getline(cin, s)) names.insert(s);

  for (nit = names.begin(); nit != names.end(); nit++) {
    cout << *nit << endl;
  }

  return 0;
} 
