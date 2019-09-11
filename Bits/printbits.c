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
  int i;

  while (1) {
    printf("Enter an integer between 0 and 255: ");
    fflush(stdout);
    if (scanf("%d", &i) != 1) exit(0);
    if (i < 0 || i > 255) {
      printf("Bad value of i\n");
    } else {
      c = (unsigned char) i;
      print_bits(c);
      putchar('\n');
    }
  }
}
