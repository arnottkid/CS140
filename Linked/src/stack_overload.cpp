#include "stack.hpp"
#include <iostream>
using namespace std;

/* This program demonstrates the assignment overload in action. */

int main()
{
  string s;
  Stack s1, s2;

  /* Read standard input into a stack. */

  while (getline(cin, s)) s1.Push(s);

  /* Copy the stack and clear out the original stack */

  s2 = s1;
  s1.Clear();

  /* Print the copied stack */

  while (!s2.Empty()) {
    cout << s2.Pop() << endl;
  }
  return 0;
}
