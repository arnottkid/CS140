/* This demonstrates catching an exception thrown by a procedure call. */

#include <iostream>
#include <cstdio>
using namespace std;

/* The procedure a() throws an exception that it does not catch. */

void a()
{
  printf("A is called, and is going to throw an exception of type int.\n");
  throw(5);
  printf("This code does not get called.\n");
}

/* Instead, main() catches the exception and prints out its argument. */

int main()
{
  try {
    printf("Calling a()\n");
    a();
    printf("A did not return, did it?\n");

  } catch (int i) {
    printf("I caught an integer: %d\n", i);
  }

  return 0;
}
