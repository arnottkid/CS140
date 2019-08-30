#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector <double> reverse(vector <double> v)
{
  vector <double> rv;
  int i;

  for (i = v.size()-1; i >= 0; i--) rv.push_back(v[i]);
  return rv;
}

main(int argc, char **argv)
{
  int i;
  int n, seed;
  istringstream ss;
  vector <double> v;

  if (argc != 3) {
    cerr << "usage: rev_2 number-of-elements seed\n";
    exit(1);
  }

  ss.str(argv[1]);
  if (!(ss >> n)) { cerr << "usage: rev_2 number-of-elements seed\n"; exit(1); }

  ss.clear(); ss.str(argv[2]);
  if (!(ss >> seed)) { cerr << "usage: rev_2 number-of-elements seed\n"; exit(1); }

  if (n <= 0) exit(0);

  srand48(seed);

  for (i = 0; i < n; i++) v.push_back(drand48());

  if (n < 10) {
    for (i = 0; i < n; i++) printf("%6.4lf\n", v[i]);
  }

  v = reverse(v);
  printf("\n");

  if (n < 10) {
    for (i = 0; i < n; i++) printf("%6.4lf\n", v[i]);
  }
  exit(0);
}
  
