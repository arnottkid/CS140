#include <iostream>
using namespace std;

unsigned int djb_hash(string &s)
{
  int i;
  unsigned int h;
  
  h = 5381;

  for (i = 0; i < s.size(); i++) {
    h = (h << 5) + h + s[i];
  }
  return h;
}

main()
{
  string s;
  unsigned int h;

  while (getline(cin, s)) {
    h = djb_hash(s);
    cout << h << endl;
  }
}
