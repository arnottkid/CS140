/* This program demonstrates all of the ways to call the find() method of strings. */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
  string a, b;
  size_t i;

  /* Set two strings to use as examples. */

  a = "Lighting Strikes.  Lightning Strikes Again.";
  b = "Light";

  /* Print out the strings with digits over the top, so that it's easier to see the digits. */

  cout << "    ";
  for (i = 0; i < a.size(); i++) cout << i%10;
  cout << endl;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << endl;

  /* We call a.find() in a variety of ways.  Ignore the printf statements, because they
     are a little confusing.  Just look at the calls on the right. */

  printf("a.find(b) = %ld\n",               a.find(b));
  printf("a.find(b, 1) = %ld\n",            a.find(b, 1));
  printf("a.find(b, 20) = %ld\n",           a.find(b, 20));
  printf("a.find('g') = %ld\n",             a.find('g'));
  printf("a.find('g', 20) = %ld\n",         a.find('g', 20));
  printf("a.find(\"Strike\") = %ld\n",      a.find("Strike"));
  printf("a.find(\"Strike\", 20) = %ld\n",  a.find("Strike", 20));
  printf("a.find(\"Aging\", 0, 2) = %ld\n", a.find("Aging", 0, 2));
  printf("\n");

  printf("string::npos = %ld\n", string::npos);
  return 0;
}
