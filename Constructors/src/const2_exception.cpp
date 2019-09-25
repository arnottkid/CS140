#include <iostream>
#include <cstdio>
using namespace std;

/* I've gotten rid of the first constructor, and I'm
   making the second constructor throw an exception
   when its parameter a is zero. */

class My_Class {
  public:
    My_Class(int a);
};

My_Class::My_Class(int a)
{
  printf("Constructor.  A = %d\n", a);
  if (a == 0) throw ((string) "Throwing exception");
}

/* Proc declares two My_Classes -- one with 
   a value of 1 and a second one with a value 
   of zero.  It does a try/catch, but neither 
   will get called because c2's declaration
   throws an exception.  */

void proc()
{
  My_Class c1(1);
  My_Class c2(0);

  try {
    cout << "In proc -- try\n";
  } catch (const string s) {
    cout << "In proc -- catch " << s << endl;
  }
}

/* Main calls proc(), and catches exceptions. */

int main()
{
  try {
    proc();
    cout << "This line won't print" << endl;
  } catch (const string s) {
    cout << "Caught " << s << endl;
  }
  return 0;
}
