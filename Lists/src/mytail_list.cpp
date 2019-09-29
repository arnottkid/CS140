/* This program uses lists to print the last ten lines of standard input.
   It calls push_back to append each line to the list, and then whenever
   the list becomes greater than 10 elements, it deletes the first element. */

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
    if (lines.size() > 10) lines.erase(lines.begin());
  }
 
  for (lit = lines.begin(); lit != lines.end(); lit++) {
    cout << *lit << endl;
  }
  return 0;
}
