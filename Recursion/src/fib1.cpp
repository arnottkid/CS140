/* A recursive implementation of the fibonacci numbers.
   The performance of this blows up exponentially. */

#include <iostream>
using namespace std;

long long fibonacci(long long n)
{
  if (n <= 1) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
  long long i;

  while (cin >> i) cout << "Fibonacci of " << i << " is " << fibonacci(i) << endl;
  return 0;
}
