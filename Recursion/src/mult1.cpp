#include <iostream>
using namespace std;

int imult(int a, int b)
{
  int product;

  product = 0;

  while (b > 0) {
    product += a;
    b--;
  }
  return product;
}

int main()
{
  int a, b;
  
  while (cin >> a >> b) {
    cout << "The Product of " << a << " and " << b << " is " << imult(a,b) << endl;
  }
  return 0;
}
