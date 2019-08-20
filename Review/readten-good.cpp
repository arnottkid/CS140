#include <iostream>
using namespace std;

/* A program that does not negate cin, but instead negates
   the whole boolean expression. */

int main()
{
  int i, n1;

  for (i = 0; i < 10; i++) {
    if (!(cin >> n1)) {            // Here is the correct line.
      cout << "Done\n";
      return 0;
    }
    cout << "Number " << i << " equals " << n1 << endl;
  }

  return 0;
}
