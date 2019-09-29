/* This is the same as mytail_list.cpp, except it prints the last 100
   lines rather than the last 10. */

#include <iostream>
#include <list>
using namespace std;

int main()
{
  list <string> lines;
  list <string>::const_iterator lit;
  string s;

  while (getline(cin, s)) {
    lines.push_back(s);
    if (lines.size() > 100) lines.erase(lines.begin());
  }
 
  for (lit = lines.begin(); lit != lines.end(); lit++) {
    cout << *lit << endl;
  }
  return 0;
}
