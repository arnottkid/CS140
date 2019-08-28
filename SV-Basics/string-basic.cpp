/* This program illustrates some basical functionalities with strings. */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  string a, b, c;
  size_t i;

  /* String assignment from literals. */

  a = "LIGHTNING";
  b = "Lightning";
  c = "Strikes";

  /* Printing out strings and their sizes. */

  cout << "a: " << a << " -- " << a.size() << " characters." << endl;
  printf("a.size = %lu\n", a.size());
  cout << "b: " << b << " -- " << b.size() << " characters." << endl;
  cout << "c: " << c << " -- " << c.size() << " characters." << endl;
  cout << endl;

  /* Modifying a string. */

  printf("Changing all but the first character of a to lower case:\n\n");

  for (i = 1; i < a.size(); i++) a[i] += ('a' - 'A');
  cout << "Changed a to: " << a << endl << endl;

  /* Testing equality and comparison. */

  printf("Testing equality: (a == b): %d.  (a == c): %d.  (b == c): %d\n", (a == b), (a == c), (b == c));

  printf("Comparison:       (a >= b): %d.  (a >= c): %d.  (b >= c): %d\n", (a >= b), (a >= c), (b >= c));
  printf("Comparison:       (a <= b): %d.  (a <= c): %d.  (b <= c): %d\n", (a <= b), (a <= c), (b <= c));
  printf("Comparison:       (a <  b): %d.  (a <  c): %d.  (b <  c): %d\n", (a <  b), (a <  c), (b <  c));
  printf("Comparison:       (a >  b): %d.  (a >  c): %d.  (b >  c): %d\n", (a >  b), (a >  c), (b >  c));
  cout << endl;

  /* Showing how addition is overloaded to do string concatenation. */

  a = b + c;
  cout << "a = b + c: a is now: " << a << endl;

  return 0;
}
