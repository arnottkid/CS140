/* This is the same as total_etc_1.cpp, except I'm declaring the parameters
   to be const reference parameters.  The reference parameters mean that 
   copies of the vectors will not be made when the procedures are called.
   The const keyword means that the compiler will check to make sure that
   the procedures don't modify the parameters.  That allows whoever calls
   the procedures to know that the vector v won't be changed by the procedures. */

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

/* This returns the total of the values. */

double total(const vector <double> &v)
{
  size_t i;
  double t;

  t = 0;
  for (i = 0; i < v.size(); i++) t += v[i];
  return t;
}

/* This returns the average of the values.  It does it by calling total to sum the values. */

double avg(const vector <double> &v)
{
  double size;

  size = v.size();
  return total(v)/size;
}

/* This returns the maximum of the values. */

double max(const vector <double> &v)
{
  size_t i;
  double mx;

  mx = v[0];
  for (i = 1; i < v.size(); i++) if (v[i] > mx) mx = v[i];
  return mx;
}

/* This returns the minimum of the values. */

double min(const vector <double> &v)
{
  size_t i;
  double mn;

  mn = v[0];
  for (i = 1; i < v.size(); i++) if (v[i] < mn) mn = v[i];
  return mn;
}

/* We call main() with the number of values in the vector. 
   We then create the vector, and call all of the procedures. */

int main(int argc, char **argv)
{
  int i;
  int n;
  istringstream ss;
  vector <double> v;
  double val;

  /* Parse the command line. */

  if (argc != 2) { cerr << "usage: total_etc_1 number-of-elements\n"; exit(1); }
  ss.str(argv[1]);
  if (!(ss >> n)) { cerr << "usage: total_etc_1 number-of-elements\n"; exit(1); }

  /* Create the vector -- I'm not using a random number generator here -- I'm 
     just starting with val = 10*1/7 and repeatedly squaring it, dividing by
     ten with it exceeds ten.  That will keep the values between 1 and 10, but
     looking kinda random. */

  val = 1/7.0 * 10.0;

  for (i = 0; i < n; i++) {
    v.push_back(val);
    val *= val; 
    if (val > 10) val /= 10.0;
  }

  /* Print the values if there are fewer than 10 */

  if (n < 10) {
    for (i = 0; i < n; i++) printf("%6.4lf\n", v[i]);
    printf("\n");
  }

  /* Call the procedures and print the results. */

  printf("Total: %12.4lf\n", total(v));
  printf("Avg:   %12.4lf\n", avg(v));
  printf("Max:   %12.4lf\n", max(v));
  printf("Max:   %12.4lf\n", min(v));
  return 0;
}
