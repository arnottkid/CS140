#include <set>
#include <iostream>
using namespace std;

main()
{
  string s;
  multiset <string> names;
  multiset <string>::iterator nit;

  while(getline(cin, s)) names.insert(s);

  for (nit = names.begin(); nit != names.end(); nit++) {
    cout << *nit << endl;
  }
} 
