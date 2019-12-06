#include "stack.hpp"
#include <iostream>
using namespace std;

/* This program demonstrates why you have to call Clear() inside the assignment overload*/

int main()
{
  string s;
  Stack s1, s2;

  /* Read standard input into a stack. */

  while (getline(cin, s)) s1.Push(s);

  /* Copy the stack twice. The second one should overwrite the first one. */

  s2 = s1;
  s2 = s1;

  /* Print the copied stack.  It should only print the stack once. */

  while (!s2.Empty()) {
    cout << s2.Pop() << endl;
  }

  return 0;
}
