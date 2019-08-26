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
  for (i = (lines.size()-10 < 0) ? 0 : lines.size()-10 ; i < lines.size(); i++) {
    cout << lines[i] << endl;
  }
}

