#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

main(int argc, char **argv)
{
  string s;
  int n, i;
  istringstream ss;
  ostringstream so;

  if (argc != 2) { cerr << "usage: gendouble iterations\n"; exit(1); }
  ss.str(argv[1]);
  if (!(ss >> n)) { cerr << "usage: gendouble iterations\n"; exit(1); }

  s = "";
  for (i = 0; i < n; i++) {
    so.clear();
    so.str("");
    so << drand48() << endl;
    s += so.str();
  }
  if (n <= 10) cout << s;
}
