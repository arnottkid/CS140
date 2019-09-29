/* This program shows how to reverse standard input using a list.
   We create the list with push_front(), so the list holds the 
   lines of standard input in reverse order.  Therefore, we traverse
   it from front to back with a const_interator. */

#include <iostream>
#include <list>
using namespace std;

int main()
{
  list <string> lines;
  string s;
  list <string>::const_iterator lit;             // We use const_iterator, because the iterator
                                                 // does not change its contents.
  while (getline(cin, s)) lines.push_front(s);
 
  for (lit = lines.begin(); lit != lines.end(); lit++) {
    cout << *lit << endl;
  }
  return 0;
}
