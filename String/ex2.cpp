/* This is the same code as ex1.cpp, except we don't typecast the quoted
   strings to C++ strings.  When you get an error, you won't catch the exception. */

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  int a, b, c;
  istringstream ss;

  try {
    if (argc != 4) throw("usage: ./ex2 a b c");

    ss.clear(); ss.str(argv[1]); if (!(ss >> a)) throw("a is not an integer.");
    ss.clear(); ss.str(argv[2]); if (!(ss >> b)) throw("b is not an integer.");
    ss.clear(); ss.str(argv[3]); if (!(ss >> c)) throw("c is not an integer.");

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  return 0;
}
