#include <iostream>
using namespace std;

/* This program attempts to read ten numbers and flag when a number is not read correctly.
   It doesn't work, though, because it doesn't clear cin and then read the non-number 
   as a string. */

int main()
{
  int i, n1;

  for (i = 0; i < 10; i++) {
    if (!(cin >> n1)) {
      cout << "Number " << i << " entered incorrectly\n";
    } else {
      cout << "Number " << i << " equals " << n1 << endl;
    }
  }

  return 0;
}
