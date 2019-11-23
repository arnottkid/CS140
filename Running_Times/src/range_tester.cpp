/* This program does some stress testing of the histogram class.
   It generates n random elements between low and high and adds them
   to the historgram.  It then gets the elements from the histogram
   and optionally prints them.  This is a good program to time the
   various features of the histogram. */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "histogram.hpp"
#include "MOA.hpp"
#include <sys/time.h>

using namespace std;

int main(int argc, char **argv)
{
  Histogram h;
  double bin_size;
  double v, low, high;
  int seed;
  int i, n;
  string print;
  vector <int> ids;
  vector <int> nelts;
  MOA rng;
  struct timeval time;
  double start, after_insert, after_get;
  
  /* Error check the command line. */

  try {
    if (argc != 7) throw((string) "usage: range_tester bin_size n low high seed print(Y|N)\n");
    if (sscanf(argv[1], "%lf", &bin_size) != 1) throw((string) "Bad bin_size.");
    if (!h.Set_Bin_Size(bin_size)) throw((string) "Bad bin_size.");
    if (sscanf(argv[2], "%d", &n) != 1) throw((string) "Bad n.");
    if (sscanf(argv[3], "%lf", &low) != 1 || low < 0) throw((string) "Bad low.");
    if (sscanf(argv[4], "%lf", &high) != 1 || high < low) throw((string) "Bad high.");
    if (sscanf(argv[5], "%d", &seed) != 1) throw((string) "Bad seed.");
    print = argv[6];
    if (print != "Y" && print != "N") throw((string) "print must be Y or N.");
  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  /* See the lecture on "Classes" if you don't know the MOA random number generator. */

  rng.Seed(seed);

  /* Set the start timer. */

  gettimeofday(&time, NULL);
  start = ((double) time.tv_usec / 1000000.0) + time.tv_sec;

  /* Add random values to the histogram */

  for (i = 0; i < n; i++) {
    v = rng.Random_Double() * (high - low) + low;
    if (!h.Add_Value(v)) {
      cerr << "Add_Value() failed on " << v << endl;
      return 1;
    }
  }

  /* Set the after_insert timer. */

  gettimeofday(&time, NULL);
  after_insert = ((double) time.tv_usec / 1000000.0) + time.tv_sec;

  /* Get the histogram's data */

  if (!h.Get_Data(ids, nelts)) {
    cerr << "Could not get the histogram's data." << endl;
    return 1;
  }

  /* Set the after_get timer. */

  gettimeofday(&time, NULL);
  after_get = ((double) time.tv_usec / 1000000.0) + time.tv_sec;


  /* Optionally print the histogram */

  if (print == "Y") {
    for (i = 0; i < (int) ids.size(); i++) {
      printf("%8g %8d\n", (double) ids[i] * bin_size, nelts[i]);
    }
  }

  /* Print the timers */

  printf("Time for Create:   %7.3lf\n", after_insert - start);
  printf("Time for Get_Data: %7.3lf\n", after_get - after_insert);

  return 0;
}
