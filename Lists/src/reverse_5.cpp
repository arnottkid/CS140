/* This code uses a deque to store standard input in reverse order.
   We then traverse it in the forward direction, to print standard input 
   in reverse order.  Deques are like vectors, because we can access 
   elements with integer indices.  They differ, because you can insert
   and delete from both the front and the back.  With vectors, you should 
   only insert and delete from the back. */

#include <iostream>
#include <deque>
using namespace std;

int main()
{
  deque <string> lines;
  size_t i;
  string s;

  while (getline(cin, s)) lines.push_front(s);

  for (i = 0; i < lines.size(); i++) cout << lines[i] << endl;

  return 0;
}
