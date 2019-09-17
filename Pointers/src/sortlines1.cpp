/* This program sorts the lines of standard input using the sort() procedure from
   the STL algorithms library. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector <string> lines;
  string s;
  size_t i;

  /* Read lines of standard input into the vector "lines".
     Sort the vector using the sort() procedure, and print the sorted lines. */

  while (getline(cin, s)) lines.push_back(s);
  sort(lines.begin(), lines.end());
  for (i = 0; i < lines.size(); i++) cout << lines[i] << endl;

  return 0;
}

