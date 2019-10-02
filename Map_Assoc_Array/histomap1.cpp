#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
  map <double, int> histo;
  double i;
  double d;

  while (cin >> d) histo[rint(d)]++;

  for (i = 0; i <= histo.rbegin()->first; i++) {
    if (histo[i] > 0) cout << i << " " << histo[i] << endl;
  }
}
