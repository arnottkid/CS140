/* We can implement the fibonacci numbers without recursion,
   by keeping track of f(i-1) and f(i-2) to calculate f(i).
   Now, calculating f(n) is O(n) instead of being exponential */

#include <deque>
#include <iostream>
using namespace std;

long long fibonacci(long long n)
{
  deque <long long> f;
  int i;

  if (n <= 1) return 1;

  /* We start with fib(0) = fib(1) = 1 */

  f.push_back(1);
  f.push_back(1);

  /* In the body of this for loop, f[0] holds fib(i-1), and f[1] holds fib(i).
     We calculate fib(i+1) by adding f[0] and f[1], pushing it on the back
     of f, and then deleting f[0].  When the loop is done, f[1] will hold fib(n). */

  for (i = 1; i < n; i++) {
    f.push_back(f[0] + f[1]);
    f.pop_front();
  }
  return f[1];
}

int main()
{
  long long i;

  while (cin >> i) cout << "Fibonacci of " << i << " is " << fibonacci(i) << endl;
  return 0;
}
