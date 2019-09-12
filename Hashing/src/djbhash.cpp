/* This is a hash function that I from http://www.cse.yorku.ca/~oz/hash.html.  
   The author claims that it works well, but doesn't know why! */

#include <iostream>
#include <string>
using namespace std;

unsigned int djb_hash(const string &s)
{
  size_t i;
  unsigned int h;
  
  h = 5381;

  for (i = 0; i < s.size(); i++) {
    h = (h << 5) + h + s[i];
  }
  return h;
}

int main()
{
  string s;
  unsigned int h;

  while (getline(cin, s)) {
    h = djb_hash(s);
    cout << h << endl;
  }
  return 0;
}
