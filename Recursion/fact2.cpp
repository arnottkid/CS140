#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int factorial(int n)
{
  int f;

  if (n <= 0) return 1;
  return n * factorial(n-1);
}

main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "usage: fact1 n\n");
    exit(1);
  }
  
  printf("%d\n", factorial(atoi(argv[1])));
}
