#include <cstdio>
#include <cstdlib>
using namespace std;

main()
{
  int i;
  int *ip1, *ip2;

  ip1 = &i;
  i = 5;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  ip1 = new int;
  *ip1 = 10;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  ip1 = new int;
  *ip1 = 15;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  ip2 = ip1;
  *ip2 = 20;
  printf("i: %2d    *ip1: %2d     *ip2: %2d\n", i, *ip1, *ip2);

  ip1 = new int;
  *ip1 = 25;
  printf("i: %2d    *ip1: %2d     *ip2: %2d\n", i, *ip1, *ip2);

  delete ip1;
  printf("i: %2d    *ip1: %2d     *ip2: %2d\n", i, *ip1, *ip2);
}
