#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  string s;
  int l, w;

  l = 0;
  while (getline(cin, s)) {
    l++;
    ss.clear();
    ss.str(s);
    w = 0;
    while (ss >> s) {
      w++;
      printf("Line %3d, word %3d: %s\n", l, w, s.c_str());
    }
    printf("\n");
  }
}
