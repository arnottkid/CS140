#include <iostream>
#include <cstdio>
using namespace std;

/* I'm declaring this class to have two constructors --
   one without parameters, and one with parameters. */

class My_Class {
  public:
    My_Class();
    My_Class(int a, const string &s);
};

/* The constructor without parameters prints the string,
   "Constructor called without parameters. */

My_Class::My_Class()
{
  cout << "Constructor called without parameters" << endl;
}

/* The second constructor prints out its parameters. */

My_Class::My_Class(int a, const string &s)
{
  cout << "Constructor called with parameters " 
       << a << " and " << s << endl;
}

/* The procedure proc() simply declares two
  instances of My_Class, prints a line and exits.  */

void proc()
{
  My_Class c3;
  My_Class c4(30, "Baby-Daisy");

  cout << endl << "proc begins and ends here." << endl;
}

/* Main has two My_Class's declared as local
  variables, and two pointers, where the My_Class
  instances are created with new. */

int main()
{
  My_Class c1;
  My_Class c2(5, "Fred");
  My_Class *cp1, *cp2;

  cout << endl << "Main is starting" << endl;
  cout << "calling: cp1 = new My_Class;" << endl;
  cp1 = new My_Class;

  cout << "cp2 = new My_Class(10, \"Luther\");" << endl;
  cp2 = new My_Class(10, "Luther");

  cout << "Calling proc():" << endl << endl;
  proc();
  return 0;
}
