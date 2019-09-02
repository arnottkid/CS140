/* Here, we change move_2019() so that it doesn't modify its line.  Now it compiles
   and runs just fine.  */

#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <iostream>
using namespace std;

void move_2019(const string &line)   // Since this code doesn't change line, it compiles.
{
  size_t i;
  string w1, w2;

  i = line.find(' ');
  if (i == string::npos) {
    fprintf(stderr, "move_2019() - the line of text has no space.\n");
    exit(1);
  }
  w1 = line.substr(0, i);
  w2 = line.substr(i+1);
  cout << "mv '" << w1 << " " << w2 << "' " << w1 << "-" << w2 << endl;
}
  
void move_photo(const string &line)
{
  string p, month, comma, ampm;
  int day, hour, minute, second;
  int m;
  istringstream ss;

  ss.str(line);
  if (ss >> p >> month >> day >> comma >> hour >> minute >> second >> ampm) {
    m = (month == "Jul") ? 7 : 8;
    if (ampm.substr(0, 2) == "PM") hour += 12;
    printf("mv '%s' 2019-%02d-%02d-%02d.%02d.%02d.jpg\n", line.c_str(), m, day, hour, minute, second);
  } else {
    fprintf(stderr, "move_2019() - sv.size has to equal two.\n");
    exit(1);
  }
}

int main()
{
  string l;

  while (getline(cin, l)) {
    if (l.substr(0, 4) == "2019") {
      move_2019(l);          
    } else {
      move_photo(l);       // move_photo() acts on l, but since it doesn't modify it, l does not change.
    }
    printf("The line of text: %s\n", l.c_str());
  }
  return 0;
}
