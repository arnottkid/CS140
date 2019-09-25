/* A program to demonstrate why it is dangerous to hold a pointer to
   an element of a vector, because it may get moved. */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main()
{
  vector <string> v;
  string *sp;
  string line;

  while (getline(cin, line)) {
    v.push_back(line); 
    if (v.size() == 1) sp = &(v[0]);          // I set sp to point to the first string in v.
    cout << v.size() << " " << *sp << endl;   // I then print v's size, and *sp.
  }
  return 0;
}
