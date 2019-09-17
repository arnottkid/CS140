/* This program uses a comparison function to sort a vector of strings by the
   strings' second letters, rather than the entire strings. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* Your comparison function takes as arguments, two const references to 
   the type that is in the vector (strings). */

bool string_compare(const string &s1, const string &s2)
{
  if (s1[1] < s2[1]) return true;         /* I could have just said "return (s1[1] < s2[1]);" */
  return false;
}

int main()
{
  vector <string> lines;
  string s;
  size_t i;

  /* This code is the same as before, except we pass string_compare() to the sort() procedure. */

  while (getline(cin, s)) lines.push_back(s);
  sort(lines.begin(), lines.end(), string_compare);
  for (i = 0; i < lines.size(); i++) cout << lines[i] << endl;

  return 0;
}

