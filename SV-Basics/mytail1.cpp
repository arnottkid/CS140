/* This program prints out the last ten lines of a file, (or the whole file if it 
   has fewer than ten lines).  It reads all of the lines into a vector, and then
   prints out the last ten entries. */

#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector <string> lines;
  size_t i;
  string s;

  /* Read each line into the vector */

  while (getline(cin, s)) lines.push_back(s);

  /* Compute the first line to print */

  if (lines.size() < 10) {
    i = 0;
  } else {
    i = lines.size()-10;
  }

  /* And then print the lines. */

  for ( ; i < lines.size(); i++) cout << lines[i] << endl;

  return 0;
}
