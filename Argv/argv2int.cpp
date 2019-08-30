/* Here we try to read argument 1 into i and argument 2 into j, but the second
   one fails, because we haven't cleared the stringstream.  In other words, if
   you put two integers on the command line, it will fail. */

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  istringstream ss;
  int i, j;

  /* Error check to make sure we have three arguments. */

  if (argc != 3) { 
    cerr << "usage: argv1int argument argument\n";
    return 1; 
  }

  /* Read the first argument into i. */

  ss.str(argv[1]);
  if (ss >> i) {
    printf("Argument i: %d\n", i);
  } else {
    fprintf(stderr, "Argument i -- %s is not an integer.\n", argv[1]);
    return 1;
  } 

  /* Read the first argument into j. */

  ss.str(argv[2]);
  if (ss >> j) {
    printf("Argument j: %d\n", j);
  } else {
    fprintf(stderr, "Argument j -- %s is not an integer.\n", argv[2]);
    return 1;
  } 

  return 0;
}
