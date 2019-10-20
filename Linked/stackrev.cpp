#include "stack.h"
#include <iostream>
using namespace std;

main()
{
  string s;
  Stack st;

  while (getline(cin, s)) st.Push(s);
  while (!st.Empty()) cout << st.Pop() << endl;
}
