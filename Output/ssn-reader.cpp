#include <iostream>
#include <cstdio>
using namespace std;

main()
{
  string fn, ln, ssn;

  while (cin >> fn >> ln >> ssn) {
    printf("%-10s %-13s %11s\n", fn.c_str(), ln.c_str(), ssn.c_str());
  }
}
