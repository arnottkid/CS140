#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  int i, j;

  for (i = 1; i < argc; i++) {
    ss.clear();
    ss.str(argv[i]);
    if (!(ss >> j)) {
      printf("Argument %d -- %s is not an integer.\n", i, argv[i]);
    } else {
      printf("Argument %d -- %d\n", i, j);
    }
  }
}
