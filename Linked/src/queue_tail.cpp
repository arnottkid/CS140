/* This program implements tail using a queue.  It reads lines of standard input
   into the queue, and once the queue reaches ten elements in size, then every
   time a line is pushed onto the end of the queue, a line is popped off the front.
   At the end, the queue is printed. */

#include "queue.hpp"
#include <iostream>
using namespace std;

int main()
{
  string s;
  Queue q;

  /* Read the lines into the queue, and keep it at a maximum of 10 elements. */

  while (getline(cin, s)) {
    q.Push(s);
    if (q.Size() > 10) (void) q.Pop();
  }

  /* Print the queue. */

  while (!q.Empty()) cout << q.Pop() << endl;
  return 0;
}
