#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
  string s1, s2, s3, s4;
  int n;
  double v;
  map <int, vector <double> > data;
  map <int, vector <double> >::iterator dit;
  size_t i;

  while (cin >> s1 >> n >> s2 >> s3 >> s4 >> v) {
    getline(cin, s1);
    data[n].push_back(v);
  }

  for (dit = data.begin(); dit != data.end(); dit++) {
    v = 0;
    for (i = 0; i < dit->second.size(); i++) v += dit->second[i];
    v /= (double) dit->second.size();
    printf("%8d %lf\n", dit->first, v);
  }
  return 0;
}
    
