#include <iostream>
using namespace std;

/* - Use cin to read single characters.
   - Count the total number of characters.
   - Count the number of L's. */

int main()
{
  int nc;      // Total number of characters
  int nl;      // Total number of L's
  char c;

  nc = 0;
  nl = 0;

  while (cin >> c) {
    nc++;
    if (c == 'L') nl++;
  }

  cout << "# of characters: " << nc << endl;
  cout << "# of L's: " << nl << endl;
  return 0;
}
