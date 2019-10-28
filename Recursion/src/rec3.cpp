/* This shows infinite recursion.  Unlike an infinite loop, which will
   run forever until interrupted, infinite recursion will eventually
   run out of stack space.  The result is usually a segmentation 
   violation, but sometimes it is something else like an illegal 
   instruction */

#include <cstdio>
using namespace std;

void a(int i)
{
  printf("In procedure a: i = %d\n", i);
  a(i);
}

int main()
{
  a(10);
}
