#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

main()
{
  int i, j;

  srand48(time(0));

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf(" %5.2lf", drand48()*100);
    } 
    printf("\n");
  }
}
