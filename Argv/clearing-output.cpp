#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  ostringstream ss, ss2;
  int i, j;

  srand48(0);
  printf("Not calling ss.str(\"\"):\n\n");
  for (i = 0; i < 4; i++) {
    ss.clear();
    ss << "#" << i << ": " << lrand48()%1000 << "\n";
    cout << ss.str();
  }
  cout << endl;

  srand48(0);
  printf("Calling ss2.str(\"\"):\n\n");
 
  for (i = 0; i < 4; i++) {
    ss2.clear();
    ss2.str("");
    ss2 << "#" << i << ": " << lrand48()%1000 << "\n";
    cout << ss2.str();
  }
}
