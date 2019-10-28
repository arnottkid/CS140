/* A very simple recursive procedure. */

#include <cstdio>
using namespace std;

void a(int i)
{
  printf("In procedure a: i = %d\n", i);
  if (i == 10) a(9);
}

int main()
{
  a(10);
  return 0;
}
