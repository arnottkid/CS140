#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

double total(vector <double> v)
{
  int i;
  double t;

  t = 0;
  for (i = 0; i < v.size(); i++) t += v[i];
  return t;
}

double avg(vector <double> v)
{
  double size;

  size = v.size();
  return total(v)/size;
}

double max(vector <double> v)
{
  int i;
  double mx;

  mx = v[0];
  for (i = 1; i < v.size(); i++) if (v[i] > mx) mx = v[i];
  return mx;
}

double min(vector <double> v)
{
  int i;
  double mn;

  mn = v[0];
  for (i = 1; i < v.size(); i++) if (v[i] < mn) mn = v[i];
  return mn;
}

main(int argc, char **argv)
{
  int i;
  int n, seed;
  istringstream ss;
  vector <double> v;

  if (argc != 3) {
    cerr << "usage: total_etc_1 number-of-elements seed\n";
    exit(1);
  }

  ss.str(argv[1]);
  if (!(ss >> n)) { cerr << "usage: total_etc_1 number-of-elements seed\n"; exit(1); }

  ss.clear(); ss.str(argv[2]);
  if (!(ss >> seed)) { cerr << "usage: total_etc_1 number-of-elements seed\n"; exit(1); }

  if (n <= 0) exit(0);

  srand48(seed);

  for (i = 0; i < n; i++) v.push_back(drand48());

  if (n < 10) {
    for (i = 0; i < n; i++) printf("%6.4lf\n", v[i]);
    printf("\n");
  }

  printf("Total: %12.4lf\n", total(v));
  printf("Avg:   %12.4lf\n", avg(v));
  printf("Max:   %12.4lf\n", max(v));
  printf("Max:   %12.4lf\n", min(v));
  exit(0);
}
  
