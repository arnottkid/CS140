#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector <string> lines;
  int i, ln;
  string s;

  ln = 0;
  while (getline(cin, s)) {
    if (ln < 10) {
      lines.push_back(s);
    } else {
      lines[ln%10] = s;
    }    
    ln++;
  }
  i = ln-10;
  if (i < 0) i = 0;
  for ( ; i < ln; i++) cout << lines[i%10] << endl;
}
