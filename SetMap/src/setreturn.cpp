/* This shows how to look at the return value of insert in a set (a map is similar) */

#include <set>
#include <iostream>
using namespace std;

int main()
{
  string s;
  set <string>  names;
  set <string>::iterator nit;
  pair <set <string>::iterator, bool> retval;

  while(getline(cin, s)) {
    retval = names.insert(s);
    if (retval.second) {
      cout << s << ": Successfully inserted.\n";
    } else {
      cout << s << ": Duplicate not inserted.\n";
    }
  }
  return 0;
} 
