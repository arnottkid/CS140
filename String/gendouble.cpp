#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

main(int argc, char **argv)
{
  double d;
  int n, i;
  istringstream ss;

  if (argc != 2) { cerr << "usage: gendouble iterations\n"; exit(1); }
  ss.str(argv[1]);
  if (!(ss >> n)) { cerr << "usage: gendouble iterations\n"; exit(1); }

  d = 0;
  for (i = 0; i < n; i++) {
    d += drand48();
  }

  cout << d << endl;
}
