#include <iostream>
using namespace std;

int main()
{
  string s;
  int i;

  i = 0;
  cin >> s;
  while (!cin.eof()) {
    i++;
    cout << "String " << i << " is " << s << endl;
    cin >> s;
  }
  return 0;
}
