#include <iostream>
using namespace std;

/* Reading two integers, testing for failures, and differentiating
   whether the failures are due to EOF (end of file), or due to an
   unsuccessful integere conversion. */

int main()
{
  int i, j;
  string s;

  if (cin >> i) {
    cout << "I is " << i << endl;
  } else {
    if (cin.eof()) return 1;      // Here's we check for end-of-file, and terminate the program.
    cout << "Bad cin call reading i -- calling cin.clear()\n";
    cin.clear();
    cin >> s;
  }

  if (cin >> j) {
    cout << "J is " << j << endl;
  } else {
    if (cin.eof()) return 1;
    cout << "Bad cin call reading j -- calling cin.clear()\n";
    cin.clear();
    cin >> s;
  }

  return 0;
}
