/* This program reads three words at a time -- first name, last name, and social
   security number (as a string, not as a number).  It then prints them, each in
   its own column. */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  string fn, ln, ssn;

  while (cin >> fn >> ln >> ssn) {
    printf("%-10s %-13s %11s\n", fn.c_str(), ln.c_str(), ssn.c_str());
  }
  return 0;
}
