/* This also reverses standard input, by appending the strings to the list,
   and then using a "reverse" iterator to traverse the list backward. */

#include <iostream>
#include <list>
using namespace std;

int main()
{
  list <string> lines;
  list <string>::const_reverse_iterator lit;
  string s;

  while (getline(cin, s)) lines.push_back(s);
 
  for (lit = lines.rbegin(); lit != lines.rend(); lit++) {
    cout << *lit << endl;
  }
  return 0;
}
