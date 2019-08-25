#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

main()
{
  int i, j;

  printf(" 010 is equal to: %2d   0%02o  0x%02x\n", 010, 010, 010);
  printf("0x10 is equal to: %2d   0%02o  0x%02x\n", 0x10, 0x10, 0x10);

  printf("\n");

  for (i = 0; i < 32; i++) {
    printf("    %2d  0%02o  0x%02x", i, i, i);
    if (i%4 == 3) printf("\n");
  }
}
