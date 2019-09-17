#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool string_compare(string s1, string s2)
{
  if (s1[1] < s2[1]) return true;
  return false;
}

main()
{
  vector <string> lines;
  string s;
  int i;

  while (getline(cin, s)) lines.push_back(s);

  sort(lines.begin(), lines.end(), string_compare);

  for (i = 0; i < lines.size(); i++) cout << lines[i] << endl;
}

