#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


void add_5_to_i_non_ref(int i)
{
  i += 5;
}

void add_5_to_i_ref(int& i)
{
  i += 5;
}

main(int argc, char **argv)
{
  int i;
  istringstream ss;

  if (argc != 2) {
    cerr << "usage: refparam number\n";
    exit(1);
  }

  ss.str(argv[1]);
  if (!(ss >> i)) {
    cerr << "usage: refparam number\n";
    exit(1);
  }

  cout << "I is " << i << endl;

  add_5_to_i_non_ref(i);
  cout << "After calling add_5_to_i_non_ref(i).  I is " << i << endl;
  
  add_5_to_i_ref(i);
  cout << "After calling add_5_to_i_ref(i).      I is " << i << endl;
  
  cout << "I feel ill." << endl;
  exit(0);
}
