#include "queue.hpp"
#include <iostream>
using namespace std;

/* This program demonstrates the assignment overload in action. */

int main()
{
  string s;
  Queue q1, q2;

  /* Read standard input into a queue. */

  while (getline(cin, s)) q1.Push(s);

  /* Copy the queue and clear out the original queue */

  q2 = q1;
  q1.Clear();

  /* Print the copied queue */

  while (!q2.Empty()) cout << q2.Pop() << endl;
  return 0;
}
