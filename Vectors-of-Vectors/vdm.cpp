/* This program creates and prints a "Vandermonde" matrix.
   The user will enter a number of rows, a number of columns, and a prime number, p.
   The Vandermonde matrix element in row i, column j is equal to (i+1)^j, mod p.
   Vandermonde matrices have interesting mathematical properties, which I won't
   go into -- if you take CS494 from me in a few semesters, you'll learn about
   some of them! */

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  int r;                             // Number of rows
  int c;                             // Number of columns
  int p;                             // The prime number
  istringstream ss;                  // We use this to read from the command line.
  vector < vector <int> > vdm;       // The Vandermonde matrix
  int base, val;                     // We use these to calculate (i+1)^j, mod p
  size_t i, j;

  /* Error check the command line.  I usually don't like to put multiple statements
     on a single line like this, but with error checking, it's cleaner. */

  if (argc != 4) { cerr << "usage: vdm rows cols prime\n"; exit(1); }
  ss.clear(); ss.str(argv[1]); if (!(ss >> r)) { cerr << "Bad rows\n"; exit(1); }
  ss.clear(); ss.str(argv[2]); if (!(ss >> c)) { cerr << "Bad cols\n"; exit(1); } 
  ss.clear(); ss.str(argv[3]); if (!(ss >> p)) { cerr << "Bad prime\n"; exit(1); }

  /* First create all of the elements of the matrix. */

  vdm.resize(r);
  for (i = 0; i < vdm.size(); i++) vdm[i].resize(c);

  /* Next, calculate (i+1)^j mod p and put it into vdm[i][j] */

  for (i = 0; i < vdm.size(); i++) {
    base = i+1;
    val = 1;
    for (j = 0; j < vdm[i].size(); j++) {
      vdm[i][j] = val;
      val = (val * base) % p;
    }
  }

  /* Finally, print out the Vandermonde matrix. */

  for (i = 0; i < vdm.size(); i++) {
    for (j = 0; j < vdm[i].size(); j++) printf(" %4d", vdm[i][j]);
    cout << endl;
  }

  return 0;
}
