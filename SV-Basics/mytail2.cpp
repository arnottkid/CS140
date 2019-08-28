/* This program also prints out the last ten lines of standard input, however unlike
   mytail1.cpp, it only stores ten lines, rather than the entire file.  You keep track 
   of the total number of lines in the variable "ln", and you simply keep overwriting
   the strings in the "lines" vector, until you get to the end of the file. */

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector <string> lines;
  int i, ln;
  string s;

  /* Read the lines into elements 0 through 9 of the vector "lines." */

  ln = 0;
  while (getline(cin, s)) {
    if (ln < 10) {
      lines.push_back(s);
    } else {
      lines[ln%10] = s;
    }    
    ln++;
  }

  /* Set i to be (ln-10), or 0 if we haven't read ten lines. */

  i = ln-10;
  if (i < 0) i = 0;

  /* Now print out the last ten lines. */

  for ( ; i < ln; i++) cout << lines[i%10] << endl;
  return 0;
}
