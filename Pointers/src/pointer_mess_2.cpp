#include <cstdio>
using namespace std;

int main()
{
  int i;
  int *ip1, *ip2;

  /* This is like the previous program -- we set ip1 to point to i, and then after we
     set i's value to 5, you see that reflected in both i, and *ip1. */

  ip1 = &i;
  i = 5;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  /* By saying "new int", we have allocated new memory for ip1.  It now points to 
     this new memory, and no longer to i.  For this reason, i's value remains 5, while
     *ip1 has been set to ten. */

  ip1 = new int;
  *ip1 = 10;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  /* We have allocated another integer and set ip1 to point to it.  We have "lost"
     the memory from the first "new" statement, because we don't have any pointer
     to it.  This is known as a "memory leak." */

  ip1 = new int;
  *ip1 = 15;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  /* We set ip2 equal to ip1.  That means they both point to the same integer, so when
     you set *ip2 to 20, that will be reflected in both *ip1 and *ip2.  You'll note that
     all this time, i has been unaffected, with its value remaining as 5. */

  ip2 = ip1;
  *ip2 = 20;
  printf("i: %2d    *ip1: %2d     *ip2: %2d\n", i, *ip1, *ip2);

  /* We allocate still another integer for ip1.  Since ip2 points to where ip1 was, this
     is not a memory leak.  At this point, i, *ip1 and *ip2 are all different values. */

  ip1 = new int;
  *ip1 = 25;
  printf("i: %2d    *ip1: %2d     *ip2: %2d\n", i, *ip1, *ip2);

  /* This deallocates the memory for ip1, so that it can be used for a new "new" call.
     You'll note that you can still print it out (or worse yet, set it).  That's because
     the memory doesn't go away; it is simply not allocated.  This is a memory bug, the
     worst of all bugs to find and fix. */

  delete ip1;
  printf("i: %2d    *ip1: %2d     *ip2: %2d\n", i, *ip1, *ip2);
  
  return 0;
}
