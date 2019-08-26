#include <iostream>
#include <cstdio>
using namespace std;

main()
{
  string s;
  int ln, len;

  ln = 0;
  while (getline(cin, s)) {
    ln++;
    len = s.size();
    printf("Line %2d - Size: %3d - %s\n", ln, len, s.c_str());
  }
}
