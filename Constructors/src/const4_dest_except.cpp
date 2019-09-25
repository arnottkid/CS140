#include <iostream>
#include <cstdio>
using namespace std;

/* My_Class has a string, which it sets in the constructor. 
   It also has a destructor that prints the string.  This 
   program will make a few nested procedure calls, each of
   which has some My_Class local variables.  In the deepest
   nesting, I throw an exception, which I catch in main().
   I do this to show how all of the destructors get called
   as the exception travels back to main(). */

class My_Class {
  public:
    My_Class(const string &s);
    ~My_Class();
    string my_string;
};

/* The constructor sets my_string, 
   and the destructor prints it. */
   
My_Class::My_Class(const string &s)
{
  my_string = s;
}

My_Class::~My_Class()
{
  cout << "Destructor called. my_string = " 
       << my_string << endl;
}

/* p1, p2, p3 declare four My_Class's.  
   p3 throws an exception. */

void p3()
{
  My_Class c1("p3_c1"), c2("p3_c2"); 
  My_Class c3("p3_c3"), c4("p3_c4");
  throw(0);
}

void p2()
{
  My_Class c1("p2_c1"), c2("p2_c2"); 
  My_Class c3("p2_c3"), c4("p2_c4");
  p3();
}

void p1()
{
  My_Class c1("p1_c1"), c2("p1_c2"); 
  My_Class c3("p1_c3"), c4("p1_c4");
  p2();
}

/* Finally, main() allocates one 
   My_Class, then calls p1(), 
   catching the exception. */

int main()
{
  My_Class c1("main_c1");

  try {
    p1();
  } catch (int i) {
    cout << "Caught " << i << endl;
  }

  return 0;
}
