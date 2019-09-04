/* This shows how you get a compiler error if you make a find() call with the wrong
   types of arguments.  In this instance, you are trying to call:

   size_type find(const string &str, size_type pos, size_type count);

   However, that combination of parameters is not supported. */

#include <iostream>
using namespace std;

int main()
{
  string a, b;
  int i;

  a = "Lighting Strikes.  Lightning Strikes Again.";
  b = "Light";

  i = a.find(b, 1, 3);
  return 0;
}
