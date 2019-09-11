#include <stdlib.h>
#include <stdio.h>

print_bits(unsigned char c)
{
  unsigned int i;

  for (i = 1 << 7; i != 0; i >>= 1) {
    if (i&c) putchar('1'); else putchar('0');
  }
}

main()
{
  unsigned char c;
  int i1, i2;

  while (1) {
    printf("Enter an integer and a shift amount: ");
    fflush(stdout);
    if (scanf("%d %d", &i1, &i2) != 2) exit(0);
    if (i1 < 0 || i1 > 255 || i2 < 0) {
      printf("Bad value of i1 or i2\n");
    } else {
      print_bits((unsigned char)i1);
      printf(" <<  %d = ", i2);
      print_bits((unsigned char)(i1 << i2));
      printf("\n");
    }
  }
}
