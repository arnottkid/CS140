/* This program's intent is to use a single ostringstream to create four strings, 
   each of which has four numbers in it.  We do it twice -- once incorrectly, because
   we don't call str("") on the stringstream to reset it.  The second time, we do it
   correctly. */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
  ostringstream ss;
  int i;
  string s;

  /* Here we create four strings, each of which is supposed to hold four numbers,
     with an ostringstream, but we do it incorrectly. */

  printf("Using the stringstream incorrectly:\n\n");

  for (i = 0; i < 4; i++) {
    ss.clear();
    ss << 10*i << " " << 10*i+1 << " " << 10*i+2 << " " << 10*i+3;
    s = ss.str();
    cout << s << endl;
  }
  cout << endl;

  /* Now we do the same thing, but correctly, by calling ss.str("") before
     putting numbers into the stringstream. */

  printf("Using the stringstream correctly:\n\n");

  for (i = 0; i < 4; i++) {
    ss.clear();
    ss.str("");                        // This is the only change from the code above.
    ss << 10*i << " " << 10*i+1 << " " << 10*i+2 << " " << 10*i+3;
    s = ss.str();
    cout << s << endl;
  }
  cout << endl;

  return 0;
}

