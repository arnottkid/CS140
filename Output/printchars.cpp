/* Print the character values of numbers from 32 to 127, in eight columns. */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int i, j;

  for (i = 32; i < 128; i += 8) {
    for (j = 0; j < 8; j++) {
      printf("%3d: '%c'  ", i+j, i+j);
    }
    printf("\n");
  }
  return 0;
}
