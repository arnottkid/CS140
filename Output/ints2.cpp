#include <iostream>
#include <cstdio>
using namespace std;

main()
{
  int i, j;

   for (i = 0; i <= 10; i++) {
     j = i*i;
     printf("I is %2d - i*i is %3d - i*2 is %2d\n", i, j, i*2);
   }
}
