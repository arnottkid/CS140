/* This program uses the Mother of All random number generator from MOA.hpp to print
   a bunch of random doubles between 0 and 1. */

#include "MOA.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  MOA rng;
  double d;
  int n, i;

  /* Read a value, n, from standard input. */

  if (!(cin >> n)) return 1;

  /* Generate n random doubles and print them. */

  rng.Seed(0);
  for (i = 0; i < n; i++) {
    d = rng.Random_Double();
    printf("%7.5lf\n", d);
  }

  return 0;
}
