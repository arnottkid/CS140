#include <iostream>
#include <map>
using namespace std;

int main()
{
  map <string, int> golfer;
  map <string, int>::iterator git;
  int score;
  string name, s;

  while (cin >> score >> name) {
    getline(cin, s);
    golfer[name+s] = score;   // Here's the associative array line.
  }

  for (git = golfer.begin(); git != golfer.end(); git++) {
    printf("%-30s %5d\n", git->first.c_str(), git->second);
  }
}
