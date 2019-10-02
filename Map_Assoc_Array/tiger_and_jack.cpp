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
    golfer[name+s] = score;
  }

  cout << "Number of golfers: " << golfer.size() << endl;
  cout << "Tiger Woods' Score: " << golfer["Tiger Woods"] << endl;
  cout << "Jack Nicklaus' Score: " << golfer["Jack Nicklaus"] << endl;
  cout << "Number of golfers: " << golfer.size() << endl;
}
