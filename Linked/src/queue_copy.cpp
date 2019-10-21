#include "queue.hpp"
#include <iostream>
using namespace std;

/* This program demonstrates the copy constructor in action. */

void Print_Queue(Queue q)
{
  while (!q.Empty()) cout << q.Pop() << endl;
  cout << endl;
}

int main()
{
  string s;
  Queue q;

  /* Create a queue from the lines of standard input. */

  while (getline(cin, s)) q.Push(s);

  /* Print it twice, using a procedure, which calls the copy constructor twice. */

  Print_Queue(q);
  Print_Queue(q);
  printf("Here.\n");
  return 0;
}
