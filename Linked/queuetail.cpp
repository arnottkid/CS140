#include "queue.h"
#include <iostream>
using namespace std;

main()
{
  string s;
  Queue q;

  while (getline(cin, s)) {
    q.Push(s);
    if (q.Size() > 10) q.Pop();
  }
  while (!q.Empty()) cout << q.Pop() << endl;
}
