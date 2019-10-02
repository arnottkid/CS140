#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  vector <int> histo;
  double i;
  double d;

  while (cin >> d) {
    i = rint(d);
    if (histo.size() <= i) histo.resize(i+1, 0);
    histo[i]++;
  }

  for (i = 0; i <= histo.size(); i++) {
    if (histo[i] > 0) cout << i << " " << histo[i] << endl;
  }
}
