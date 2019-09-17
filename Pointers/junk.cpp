#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

main()
{
  int i;
  int *ip, *ip2;

  ip = &i;

  *ip = 10;

  printf("i = %d.  *ip = %d.\n", i, *ip);

  ip = new int;
  *ip = 20;

  printf("i = %d.  *ip = %d.  \n", i, *ip);

  ip2 = ip;

  ip = new int;
  *ip = 30;

  printf("i = %d.  *ip = %d. *ip2 = %d \n", i, *ip, *ip2);

  delete ip;

  ip = new int;
  *ip = 40;

  printf("i = %d.  *ip = %d. *ip2 = %d \n", i, *ip, *ip2);

  delete ip;
  printf("i = %d.  *ip = %d. *ip2 = %d \n", i, *ip, *ip2);
}
