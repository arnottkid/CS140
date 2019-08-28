#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  int i, j;

  if (argc != 3) { cerr << "usage: argv1int argument argument\n"; return 1; }

  ss.str(argv[1]);
  if (!(ss >> i)) {
    fprintf(stderr, "Argument i -- %s is not an integer.\n", argv[1]);
    return 1;
  } 
  printf("Argument i: %d\n", i);

  ss.str(argv[2]);
  if (!(ss >> j)) {
    fprintf(stderr, "Argument j -- %s is not an integer.\n", argv[2]);
    return 1;
  } 
  printf("Argument j: %d\n", j);
}
