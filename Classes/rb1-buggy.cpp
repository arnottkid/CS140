#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

main()
{
  int i, rn;
  vector <int> inrandom;

  inrandom.resize(100, 0);
  for (i = 0; i < 100; i++) {
    do {
      rn = lrand48()%100;
    } while (inrandom[rn]);
    printf("%3d\n", rn);
  }
}

