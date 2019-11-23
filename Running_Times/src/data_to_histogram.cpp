#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "histogram.hpp"
using namespace std;

int main(int argc, char **argv)
{
  Histogram h;
  double bin_size;
  double v;
  string s;
  bool done;
  size_t i;
  vector <int> ids;
  vector <int> nelts;
  
  /* Error check the command line. */

  try {
    if (argc != 2) throw((string) "usage: data_to_histogram bin_size");
    if (sscanf(argv[1], "%lf", &bin_size) != 1) throw((string) "Bad bin_size.");
    if (!h.Set_Bin_Size(bin_size)) throw((string) "Bad bin_size.");
  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  /* Add every word on standard input that is a number to the histogram.
     Ignore non-numbers. */
  
  done = false;
  while (!done) {
    if (cin >> v) {
      if (!h.Add_Value(v)) {
        cerr << "Could not add " << v << " to the histogram. " << endl;
        return 1;
      }
    } else {                    /* Ignore non-numbers */
      cin.clear();
      done = !(cin >> s);
    }
  }

  /* Now that all the values are in the histogram, get the two vectors and print them. */

  if (!h.Get_Data(ids, nelts)) {
    cerr << "Could not get the histogram's data." << endl;
    return 1;
  }

  for (i = 0; i < ids.size(); i++) printf("%8g %8d\n", (double) ids[i] * bin_size, nelts[i]);

  return 0;
}
