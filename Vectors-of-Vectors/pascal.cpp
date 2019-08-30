#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef vector <int> IVec;

main(int argc, char **argv)
{
  int r, i, j;
  istringstream ss;
  vector <IVec> pascal;

  if (argc != 2) { cerr << "usage: pascal rows\n"; exit(1); }

  ss.clear();  
  ss.str(argv[1]); 
  if (!(ss >> r)) { cerr << "Bad rows\n"; exit(1); }

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

  for (i = 0; i < pascal.size(); i++) {
    for (j = 0; j < pascal[i].size(); j++) printf(" %4d", pascal[i][j]);
    cout << endl;
  }
}
