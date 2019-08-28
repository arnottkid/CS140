#include <iostream>
#include <cstdio>
using namespace std;

main(int argc, char **argv)
{
  int i;

  printf("Argc is %d\n", argc);
  printf("\n");
  for (i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
}
