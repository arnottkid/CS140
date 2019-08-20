#include <iostream>
using namespace std;

int main()
{
  string s;
  int i;

  i = 0;
  while (cin >> s) {
    i++;
    cout << "String " << i << " is " << s << endl;
  }
  return 0;
}
