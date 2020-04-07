/* A program to demonstrate single pointer that points to an integer. */

#include <cstdio>
using namespace std;

int main()
{
  int i;                     // Declare an integer i
  int *ip1;                  // and a pointer to an integer, named ip1.

  ip1 = &i;                  // Set ip1 to point to i.

  /* When we change i, we can access that change either from i itself,
     or by "dereferencing" ip1 using the asterisk. */

  i = 5;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);

  /* When we change *ip1, you see the change reflected in both i and *ip1. */

  *ip1 = 10;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);
  return 0;

  /* This is like the first statement - changine i is reflected in both i and *ip1. */

  i = 15;
  printf("i: %2d    *ip1: %2d\n", i, *ip1);
  return 0;
}
