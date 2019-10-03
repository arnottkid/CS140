/* This program reads first name / last name pairs, and keeps track of the last names
   in a map.  It uses an integer value in the map, and increments that value whenever
   it encounters a last name.  In other words, it keeps track of the number of people
   with each last name. */

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
  map <string, int> names;
  map <string, int>::iterator nit;
  string fn, ln;
  
  /* Read in first name / Last names */

  while (cin >> fn >> ln) {

    /* Look up the last name in the map.  If we don't find the last name in the map,
       we insert it there with a value of 1.  Otherwise, we increment the value. */

    nit = names.find(ln);
    if (nit == names.end()) {
      names.insert(make_pair(ln, 1));
    } else {
      nit->second++;                // This statement is why nit cannot be a const_iterator.
    }
  }

  /* Print out the last names and the number of players */

  for (nit = names.begin(); nit != names.end(); nit++) {
    cout << "Last name: " << nit->first << ". Number of players: " << nit->second << endl;
  }

  return 0;
}
