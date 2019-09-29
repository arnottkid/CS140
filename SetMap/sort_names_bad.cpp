#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef set <string> fnset;

main()
{
  map <string, fnset> lnames;
  map <string, fnset>::iterator lnit;
  fnset fnames;
  fnset::iterator fnit;
  string fn, ln;
  
  while (cin >> fn >> ln) {
    lnit = lnames.find(ln);
    if (lnit == lnames.end()) {
      lnames.insert(make_pair(ln, fnames));
    } else {
      fnames = lnit->second;
    }
    fnames.insert(fn);
  }

  for (lnit = lnames.begin(); lnit != lnames.end(); lnit++) {
    fnames = lnit->second;
    for (fnit = fnames.begin(); fnit != fnames.end(); fnit++) {
      cout << *fnit << " " << lnit->first << endl;
    }
  }
}
