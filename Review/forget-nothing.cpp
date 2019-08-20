#include <iostream>
using namespace std;

/* This program reads 10 numbers, identifying when it
   reads a non-number, and also eof. */

int main()
{
  int i, n1;
  string s;

  for (i = 0; i < 10; i++) {
    if (!(cin >> n1)) {
      cin.clear();
      if (!(cin >> s)) return 0;       // This reads the number and detects EOF
      cout << "Number " << i << " entered incorrectly\n";
    } else {
      cout << "Number " << i << " equals " << n1 << endl;
    }
  }

  return 0;
}
