/* This program demonstrates octal and hexadecimal numbers, both as
   literals in C++, and when printed with printf(). */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int i, j;

  printf(" 010 is equal to: %2d   0%02o  0x%02x\n", 010, 010, 010);
  printf("0x10 is equal to: %2d   0%02o  0x%02x\n", 0x10, 0x10, 0x10);

  printf("\n");

  /* Print the numbers from 0 to 31 in octal and in hex.
     Print four numbers per row. */

  for (i = 0; i < 32; i++) {
    printf("    %2d  0%02o  0x%02x", i, i, i);
    if (i%4 == 3) printf("\n");
  }
  return 0;
}
