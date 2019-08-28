#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  ostringstream ss;
  string s;
  int i;

  for (i = 1; i < 11; i++) ss << i << " ";
  s = ss.str();
  cout << s << endl;
}
