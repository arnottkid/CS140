#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

main()
{
  vector <string> lines;
  string s;
  int i;

  while (getline(cin, s)) lines.push_back(s);

  sort(lines.begin(), lines.end());

  for (i = 0; i < lines.size(); i++) cout << lines[i] << endl;
}

