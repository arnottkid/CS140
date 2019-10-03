/* This is the same as simple_set.cpp, except it uses a multiset rather than a set.
   Thus, duplicate entries are not ignored, and will result in multiple identical lines. */

#include <set>
#include <iostream>
using namespace std;

int main()
{
  string s;
  multiset <string> names;
  multiset <string>::const_iterator nit;

  while(getline(cin, s)) names.insert(s);

  for (nit = names.begin(); nit != names.end(); nit++) {
    cout << *nit << endl;
  }

  return 0;
} 
