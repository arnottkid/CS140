#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class DiamondHunt {
  public:
    int countDiamonds(string mine);
};

/* We count diamonds by searching for "<>" in the string.
   If we find it, we "remove" it by recreating the string
   with the concatenation of the two substrings surrounding
   the "<>". */

int DiamondHunt::countDiamonds(string mine)
{
  int num_diamonds;
  size_t i;

  num_diamonds = 0;
  while (1) {
    i = mine.find("<>");
    if (i == string::npos) return num_diamonds;
    num_diamonds++;
    mine = mine.substr(0, i) + mine.substr(i+2);
  }
}

/* The main reads the strings from standard input and calls the method on each string. */

int main()
{
  DiamondHunt d;
  string s;

  while (cin >> s) {
    cout << d.countDiamonds(s) << endl;
  }
  return 0;
}
