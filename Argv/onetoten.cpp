/* Use an ostringstream to create a string that contains the numbers from 1 to 10. */

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main()
{
  ostringstream ss;
  string s;
  int i;

  for (i = 1; i < 11; i++) ss << i << " ";
  s = ss.str();
  cout << s << endl;
  return 0;
}
