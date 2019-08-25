#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

main()
{
  int i, j;

  for (i = 32; i < 128; i += 8) {
    for (j = 0; j < 8; j++) {
      printf("%3d: '%c'  ", i+j, i+j);
    }
    printf("\n");
  }
}
