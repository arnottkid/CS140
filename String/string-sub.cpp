/* This program demonstrates the substr() method of strings. */

#include <iostream>
using namespace std;

int main()
{
  string a;
  size_t i;

  a = "Lighting Strikes.  Lightning Strikes Again.";

  /* Print out digits, so that it's easier to see the indices of the string. */

  cout << "    ";
  for (i = 0; i < a.size(); i++) cout << i%10;
  cout << endl;

  /* Now make a few a.substr() calls. */

  cout << "a = "                           << a << endl;
  cout << "a.substr(19) = "                << a.substr(19) << endl;
  cout << "a.substr(19, 13) = "            << a.substr(19, 13) << endl;
  cout << "a.substr(19, 13).substr(5) = "  << a.substr(19, 13).substr(5) << endl;

  return 0;
}
