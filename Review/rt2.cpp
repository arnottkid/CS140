#include <iostream>
using namespace std;

/* Read in two integers and error check whether you were successful. */

int main()
{
  int i, j;

  if (cin >> i) {
    cout << "I is " << i << endl;
  } else {
    cout << "Bad cin call reading i -- calling cin.clear()\n";
    cin.clear();
  }

  if (cin >> j) {
    cout << "J is " << j << endl;
  } else {
    cout << "Bad cin call reading j -- calling cin.clear()\n";
    cin.clear();
  }

  return 0;
}
