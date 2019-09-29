#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef struct {
  string fn;
  string ln;
} Player;

typedef map <string, Player *> fnmap;

main()
{
  map <string, fnmap *> lnames;
  map <string, fnmap *>::iterator lnit;
  fnmap *fnames;
  fnmap::iterator fnit;
  int i;
  string fn, ln, name;
  Player *p;
  
  while (!cin.eof()) {
    cin >> fn;
    if (!cin.fail()) {
      cin >> ln;
      p = new Player;
      p->fn = fn;
      p->ln = ln;
      lnit = lnames.find(ln);
      if (lnit == lnames.end()) {
        fnames = new fnmap;
        lnames.insert(make_pair(ln, fnames));
      } else {
        fnames = lnit->second;
      }
      fnames->insert(make_pair(fn, p));
    }
  }

  for (lnit = lnames.begin(); lnit != lnames.end(); lnit++) {
    fnames = lnit->second;
    for (fnit = fnames->begin(); fnit != fnames->end(); fnit++) {
      p = fnit->second;
      cout << p->fn << " " << p->ln << endl;
    }
  }
}
