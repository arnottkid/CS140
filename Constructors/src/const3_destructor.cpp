#include <iostream>
#include <cstdio>
using namespace std;

/* This is like const1.cpp, except we've added a destructor
   that prints out out when it's called. I also call
   delete on cp1. */

class My_Class {
  public:
    My_Class();
    My_Class(int a, const string &s);
    ~My_Class();                       // This is the destructor
};

/* Here's the destructor.  Everything else is identical to
   const1.cpp, except I've added a delete call. */

My_Class::~My_Class()
{
  cout << "Destructor called." << endl;
}

My_Class::My_Class()
{
  cout << "Constructor called without parameters" << endl;
}

My_Class::My_Class(int a, const string &s)
{
  cout << "Constructor called with parameters " 
       << a << " and " << s << endl;
}

void proc()
{
  My_Class c3;
  My_Class c4(30, "Baby-Daisy");

  cout << endl << "proc begins and ends here." << endl;
}

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

  /* Here's the new code in main() */

  cout << endl << "Calling delete on cp1" << endl ;
  delete cp1;

  cout << endl << "Main is returning" << endl ;
  return 0;
}
