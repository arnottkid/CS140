/* A program to demonstrate why it can be dangerous to use the c_str() method of a 
   string, when the string goes away before you use the c_str(). */

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

class My_Class {
  public:
    My_Class(int a);
};

/* With a == 0, I throw a string literal.  The type of this is (const char *), so
   that's what I have to catch.  With (a < 0), I construct an error string with
   a stringstream.  I should throw(oss.str()), but the type of that is (string),
   so now I have to have separate catch statements for the two types.

   I wanted to avoid that, so I call the c_str() method, so that it throws a
   (const char *).  There's a big problem with this (read the lecture notes).
 */

My_Class::My_Class(int a)
{
  ostringstream oss;

  if (a == 0) throw("Bad constructor for My_Class().  A shouldn't equal zero.");

  if (a < 0) {
    oss << "Bad constructor for My_Class().  A shouldn't equal " << a;
    throw(oss.str().c_str());
  }
}

/* Here, I catch (const char *)'s rather than strings. */

int main()
{
  My_Class *cp;

  try {                        // This one works fine, because the string literal is 
    cp = new My_Class(0);      // really a global variable.
  } catch (const char *s) {
    printf("%s\n", s);
  }
   
  try {                        // This one doesn't work, because the oss's destructor is called, 
    cp = new My_Class(-5);     // and the memory pointed to by s has been freed up (and reused)
  } catch (const char *s) {
    printf("%s\n", s);
  }
  return 0;
}
