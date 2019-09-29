#include <set>
#include <iostream>
using namespace std;

typedef set <string> string_set;

main()
{
  string s;
  string_set names;
  string_set::iterator nit;
  pair <string_set::iterator, bool> retval;
  

  while(getline(cin, s)) {
    retval = names.insert(s);
    if (retval.second) {
      cout << s << ": Successfully inserted.\n";
    } else {
      cout << s << ": Duplicate not inserted.\n";
    }
  }
} 
