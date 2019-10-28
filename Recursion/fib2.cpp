#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int fibonacci(int n)
{
  int fibim1, fibim2, fibi, i;

  if (n <= 1) return 1;

  fibim1 = 1;
  fibim2 = 1;
  i = 1;

  while (1) {
    i++;
    fibi = fibim1 + fibim2;
    if (i == n) return fibi;
    fibim2 = fibim1;
    fibim1 = fibi;
  }
}

main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "usage: fib1 n\n");
    exit(1);
  }
  
  printf("%d\n", fibonacci(atoi(argv[1])));
}
