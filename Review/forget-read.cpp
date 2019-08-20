#include <iostream>
using namespace std;

/* This tries to read 10 numbers, flagging a failure.  However, it doesn't
   work, because when you have a failed conversion, you need to read the
   failed word, in addition to doing clear(). */

int main()
{
  int i, n1;

  for (i = 0; i < 10; i++) {
    if (!(cin >> n1)) {
      cout << "Number " << i << " entered incorrectly\n";
      cin.clear();
    } else {
      cout << "Number " << i << " equals " << n1 << endl;
    }
  }

  return 0;
}
