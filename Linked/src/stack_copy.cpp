#include "stack.hpp"
#include <iostream>
using namespace std;

/* This program demonstrates the copy constructor in action. */

void Print_Stack(Stack st)
{
  while (!st.Empty()) cout << st.Pop() << endl;
  cout << endl;
}

int main()
{
  string s;
  Stack st;

  /* Create a stack from the lines of standard input. */

  while (getline(cin, s)) st.Push(s);

  /* Print it twice, using a procedure, which calls the copy constructor twice. */

  Print_Stack(st);
  Print_Stack(st);
  return 0;
}
