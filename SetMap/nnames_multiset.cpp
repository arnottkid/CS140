#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

main()
{
  multiset <string> names;
  multiset <string>::iterator nit;
  string fn, ln, pn;
  int count;
  
  while (cin >> fn >> ln) names.insert(ln);

  
  for (nit = names.begin(); nit != names.end(); nit++) {
    if (nit != names.begin()) {
      if (*nit == pn) {
        count++;
      } else { 
        printf("%-20s %d\n", pn.c_str(), count);
        pn = *nit;
        count = 1;
      }
    } else {
      pn = *nit;
      count = 1;
    }
  }

  if (names.size() > 0) printf("%-20s %d\n", pn.c_str(), count);
}
