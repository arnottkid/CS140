/* A program that writes to the two default output streams:

   - cout to standard output
   - cerr to standard error. */

#include <iostream>
using namespace std;

int main()
{
  cout << "Writing this to cout.\n";
  cerr << "Writing this to cerr.\n";
  return 0;
}
