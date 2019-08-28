#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  int i;

  if (argc != 2) { cerr << "usage: argv1int argument\n"; return 1; }

  ss.str(argv[1]);
  if (!(ss >> i)) {
    fprintf(stderr, "The argument %s is not an integer.\n", argv[1]);
    return 1;
  } 

  printf("Integer: %d\n", i);
}
