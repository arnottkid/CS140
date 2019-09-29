/* This is idential to src/mytail_100_list.cpp, 
   except I have substituted "vector" for "list". */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector <string> lines;
  vector <string>::const_iterator lit;
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
