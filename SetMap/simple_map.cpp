#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

main()
{
  map <string, int> names;
  map <string, int>::iterator nit;
  string fn, ln;
  
  while (cin >> fn >> ln) {
    nit = names.find(ln);
    if (nit == names.end()) {
      names.insert(make_pair(ln, 1));
    } else {
      nit->second++;
    }
  }

  for (nit = names.begin(); nit != names.end(); nit++) {
    cout << "Last name: " << nit->first << ". Number of players: " << nit->second << endl;
  }
}
