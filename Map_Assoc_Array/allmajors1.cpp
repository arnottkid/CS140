#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector <int> ivector;
     
int main()
{
  map <string, ivector> golfer;
  map <string, ivector>::iterator git;
  int score, i;
  string name, s;
  double total;

  while (cin >> score >> name) {
    getline(cin, s);
    golfer[name+s].push_back(score);
  }

  for (git = golfer.begin(); git != golfer.end(); git++) {
    if (git->second.size() == 4) {
      total = 0;
      for (i = 0; i < git->second.size(); i++) total += git->second[i];
      printf("%-30s %10.2lf\n", git->first.c_str(), total/4.0);
    }
  }
}
