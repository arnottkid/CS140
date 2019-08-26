#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

main()
{
  string a, b, c;
  int i;

  a = "LIGHTNING";
  b = "Lightning";
  c = "Strikes";

  cout << "a: " << a << " -- " << a.size() << " characters." << endl;
  cout << "b: " << b << " -- " << b.size() << " characters." << endl;
  cout << "c: " << c << " -- " << c.size() << " characters." << endl;
  cout << endl;

  printf("Changing all but the first character of a to lower case:\n\n");

  for (i = 1; i < a.size(); i++) a[i] += ('a' - 'A');
  cout << "Changed a to: " << a << endl << endl;

  printf("Testing equality: (a == b): %d.  (a == c): %d.  (b == c): %d\n", (a == b), (a == c), (b == c));

  printf("Comparison:       (a >= b): %d.  (a >= c): %d.  (b >= c): %d\n", (a >= b), (a >= c), (b >= c));
  printf("Comparison:       (a <= b): %d.  (a <= c): %d.  (b <= c): %d\n", (a <= b), (a <= c), (b <= c));
  printf("Comparison:       (a <  b): %d.  (a <  c): %d.  (b <  c): %d\n", (a <  b), (a <  c), (b <  c));
  printf("Comparison:       (a >  b): %d.  (a >  c): %d.  (b >  c): %d\n", (a >  b), (a >  c), (b >  c));
  cout << endl;

  a = b + c;
  cout << "a = b + c: a is now: " << a << endl;

  return 0;
}
