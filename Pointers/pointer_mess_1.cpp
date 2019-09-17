#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

main()
{
  int i;
  int *ip1;

  ip1 = &i;

  i = 5;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  *ip1 = 10;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  i = 15;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);
}
