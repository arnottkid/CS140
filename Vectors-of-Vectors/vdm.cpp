#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef vector <int> IVec;

main(int argc, char **argv)
{
  int r, c, p, i, j, base, val;
  istringstream ss;
  vector <IVec> vdm;

  if (argc != 4) { cerr << "usage: vdm rows cols prime\n"; exit(1); }

  ss.clear(); ss.str(argv[1]); if (!(ss >> r)) { cerr << "Bad rows\n"; exit(1); }
  ss.clear(); ss.str(argv[2]); if (!(ss >> c)) { cerr << "Bad cols\n"; exit(1); } 
  ss.clear(); ss.str(argv[3]); if (!(ss >> p)) { cerr << "Bad prime\n"; exit(1); }

  vdm.resize(r);
  for (i = 0; i < vdm.size(); i++) {
    base = i+1;
    val = 1;
    for (j = 0; j < c; j++) {
      vdm[i].push_back(val);
      val = (val * base) % p;
    }
  }

  for (i = 0; i < vdm.size(); i++) {
    for (j = 0; j < vdm[i].size(); j++) printf(" %4d", vdm[i][j]);
    cout << endl;
  }
}
