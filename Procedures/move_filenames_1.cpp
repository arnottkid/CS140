#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <iostream>
using namespace std;

/* This emits the shell command to move the files that start with 2019.  
   We implement it by finding the space in the line.  Then we print "mv 'line'", 
   change the space to a hyphen, and finally "line\n". */

void move_2019(string line)
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
  
/* move_photo() assumes that the line is like "Photo Aug 04, 3 03 33 PM.jpg".  It uses
   an istringstream to read all of those values, and then emits the shell command
   to move the photo to one like "2019-08-04-15.03.33.jpg" */

void move_photo(string line)
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

/* The main is pretty simple.  It reads in a line of text, and if the line begins with
   "2019", it calls move_2019().  Otherwise, it calls movo_photo(). */

int main()
{
  string l;

  while (getline(cin, l)) {
    if (l.substr(0, 4) == "2019") {
      move_2019(l);
    } else {
      move_photo(l);
    }
  }
  return 0;
}
