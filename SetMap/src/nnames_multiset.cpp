/* This program outputs the same thing as src/simple_map.cpp, except it puts the
   last names into a multiset.  It then counts the duplicate names while traversing
   the multiset. */

#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
  multiset <string> names;
  multiset <string>::const_iterator nit;
  string fn, ln, pn;
  int count;
  
  /* Read the last names into the multiset */

  while (cin >> fn >> ln) names.insert(ln);

  /* Traverse the multiset, keeping track of the previous name in the variable pn.
     When the current name is different from pn, print out the previous name and
     its count.  Otherwise, increment the count.  You need special code for the 
     first name in the multiset */

  for (nit = names.begin(); nit != names.end(); nit++) {
    if (nit == names.begin()) {                           // First name
      pn = *nit;
      count = 1;
    } else if (*nit == pn) {                              // Current name equals previous name
      count++;
    } else {                                              // Current name doesn't equal previous name
      cout << "Last name: " << pn << ". Number of players: " << count << endl;
      pn = *nit;
      count = 1;
    } 
  }

  /* You have to print the last name after the set traversal */

  if (names.size() > 0) {
    cout << "Last name: " << pn << ". Number of players: " << count << endl;
  }
  return 0;
}
