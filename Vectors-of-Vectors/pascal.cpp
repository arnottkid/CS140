/* This program creates Pascal's triangle and prints it out.
   It stores Pascal's triangle as a vector of vectors. */

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
  int r;                               // The number of rows
  vector < vector <int> > pascal;      // The vector of vectors that holds Pascal's triangle

  size_t i, j;
  istringstream ss;

  /* Error check the command line. */

  if (argc != 2) { cerr << "usage: pascal rows\n"; exit(1); }
  ss.clear();  ss.str(argv[1]); if (!(ss >> r)) { cerr << "Bad rows\n"; exit(1); }

  /* Create an entry in the vector for each row.  Then add values to each row
     by using push_back() with either the value one, or the sum of two values
     on the previous row. */

  pascal.resize(r);
  for (i = 0; i < pascal.size(); i++) {
    for (j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        pascal[i].push_back(1);
      } else {
        pascal[i].push_back(pascal[i-1][j-1] + pascal[i-1][j]);
      }
    }
  }

  /* Print out the vector of vectors. */

  for (i = 0; i < pascal.size(); i++) {
    for (j = 0; j < pascal[i].size(); j++) printf(" %4d", pascal[i][j]);
    cout << endl;
  }

  return 0;
}
