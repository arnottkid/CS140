#include "stack_no_ao_or_cc.hpp"
#include <iostream>
using namespace std;

/* This program demonstrates how you get in trouble when your data structure
   has pointers and you don't implement an assignment overload properly. 
   
   It is identical to src/stack_overload.cpp, but it includes stack_no_ao_or_cc.hpp
   instead of stack.hpp, which means that they use the default assignment overload.
 */

int main()
{
  string s;
  Stack s1, s2;

  while (getline(cin, s)) s1.Push(s);
  s2 = s1;
  s1.Clear();

  while (!s2.Empty()) {
    cout << s2.Pop() << endl;
  }
  return 0;
}
