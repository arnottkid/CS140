#include <cstdio>
using namespace std;

/* This is a slightly more complex recursion example, where the
   procedure a() calls itself recursively twice. */

void a(int i)
{
  int j;

  j = i*5;
  printf("In procedure a: i = %d, j = %d\n", i, j);
  if (i > 0) a(i-1);
  printf("Later In procedure a: i = %d, j = %d\n", i, j);
}

int main()
{
  int i;
  
  i = 16;
  a(3);
  printf("main: %d\n", i);
  return 0;
}
