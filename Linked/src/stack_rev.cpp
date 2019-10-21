#include "stack.hpp"
#include <iostream>
using namespace std;

int main()
{
  string s;
  Stack st;

  /* Create the stack with every line of standard input. */

  while (getline(cin, s)) st.Push(s);

  /* Now, pop each string off the stack and print it out.
     This will print standard output in reverse order. */

  while (!st.Empty()) cout << st.Pop() << endl;

  return 0;
}
