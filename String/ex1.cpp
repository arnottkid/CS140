/* This is a program to demonstrate using exceptions to handle errors.
   We process the command line, and when we get an error, we throw an
   exception, passing a string to the "throw" call. When you throw the
   exception, the control goes to a "catch" clause that specifies the
   type of the thrown exception. */

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
  int a, b, c;
  istringstream ss;

  /* Process the command line, and when you see something wrong, you throw
     an exception.  Since the quoted strings are actually C-style strings, you 
     need to typecast them to C++ strings when you throw them. */

  try {
    if (argc != 4) throw((string) "usage: ./ex1 a b c");

    ss.clear(); ss.str(argv[1]); if (!(ss >> a)) throw((string) "a is not an integer.");
    ss.clear(); ss.str(argv[2]); if (!(ss >> b)) throw((string) "b is not an integer.");
    ss.clear(); ss.str(argv[3]); if (!(ss >> c)) throw((string) "c is not an integer.");

  /* Here's where you "catch" a thrown exception. */

  } catch (string s) {
    cerr << s << endl;
    return 1;
  }

  /* If the "try" clause was successful, you'll end up here, skipping the "catch" code. */

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  return 0;
}
