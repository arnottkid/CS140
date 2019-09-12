/* This program hashes strings that it reads from standard input
   by simply adding their ascii values.  This is an easy hash function
   to write, but it performs very badly, because the hash values that
   it produces are very similar to each other.  Think about it:
   "abc", "acb", "bac", "bca", "cab" and "cba" all hash to the same value! */

#include <iostream>
#include <string>
using namespace std;

unsigned int bad_hash(const string &s)
{
  size_t i;
  unsigned int h;
  
  h = 0;

  for (i = 0; i < s.size(); i++) {
    h += s[i];
  }
  return h;
}

int main()
{
  string s;
  unsigned int h;

  while (getline(cin, s)) {
    h = bad_hash(s);
    cout << h << endl;
  }
  return 0;
}
