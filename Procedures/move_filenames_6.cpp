/* In this version, we declare <b>move_photo()</b> to have a const reference parameter.
   In that way, the parameter is not copied, but the compiler ensures that it is not
   modified. */

#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <iostream>
using namespace std;

void move_2019(string &line)
{
  size_t i;

  i = line.find(' ');
  if (i == string::npos) {
    fprintf(stderr, "move_2019() - the line of text has no space.\n");
    exit(1);
  }
  printf("mv '%s'", line.c_str());
  line[i] = '-';
  printf(" %s\n", line.c_str());
}
  
void move_photo(const string &line)      // This is the only line that is changed.
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
