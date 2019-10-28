/* This is a simple example of computing a factorial with a while loop. 
   This program reads numbers on standard input, and prints their factorials. */

#include <iostream>
using namespace std;

long long factorial(long long i)
{
  long long f;

  f = 1;
  while (i > 0) {
    f *= i;
    i--;
  }
  return f;
}

int main()
{
  long long i;

  while (cin >> i) cout << "Factorial of " << i << " is " << factorial(i) << endl;
  return 0;
}
