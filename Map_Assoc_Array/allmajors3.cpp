#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector <int> ivector;
     
int main()
{
  map <string, ivector> golfer;
  map <string, ivector>::iterator git;
  multimap <double, string> averages;
  multimap <double, string>::iterator ait;

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
      averages[total/4.0] = git->first;
    }
  }
  for (ait = averages.begin(); ait != averages.end(); ait++) {
    printf("%8.2lf %s\n", ait->first, ait->second.c_str());
  }
}
