/* Now we write factorial recursively so that it looks just like its mathematical definition. */

#include <iostream>
using namespace std;

long long factorial(long long n)
{
  if (n <= 0) return 1;
  return n * factorial(n-1);
}

int main()
{
  long long i;

  while (cin >> i) cout << "Factorial of " << i << " is " << factorial(i) << endl;
  return 0;
}
