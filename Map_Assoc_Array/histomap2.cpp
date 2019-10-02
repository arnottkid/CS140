#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
  map <double, int> histo;
  map <double, int>::iterator hit;
  double d;

  while (cin >> d) histo[rint(d)]++;

  for (hit = histo.begin(); hit != histo.end(); hit++) {
    cout << hit->first  << " " << hit->second << endl;
  }
}
