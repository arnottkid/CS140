#include <iostream>
using namespace std;

unsigned int bad_hash(string &s)
{
  int i;
  unsigned int h;
  
  h = 0;

  for (i = 0; i < s.size(); i++) {
    h += s[i];
  }
  return h;
}

main()
{
  string s;
  unsigned int h;

  while (getline(cin, s)) {
    h = bad_hash(s);
    cout << h << endl;
  }
}
