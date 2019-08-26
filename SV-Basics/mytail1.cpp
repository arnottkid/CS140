#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector <string> lines;
  int i;
  string s;

  while (getline(cin, s)) lines.push_back(s);
  i = lines.size()-10;
  if (i < 0) i = 0;
  for ( ; i < lines.size(); i++) cout << lines[i] << endl;
}

