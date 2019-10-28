#include <iostream>
using namespace std;

int imult(int a, int b)
{
  if (b <= 0) return 0;
  return a + imult(a, b-1);
}

int main()
{
  int a, b;
  
  while (cin >> a >> b) {
    cout << "The Product of " << a << " and " << b << " is " << imult(a,b) << endl;
  }
  return 0;
}
