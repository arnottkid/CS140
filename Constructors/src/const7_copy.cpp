#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/* We're going to resize a vector with
   a default, and define a copy
   constructor, which gets called
   each time. */

class My_Class {
  public:
    My_Class();
    My_Class(const My_Class &mc);
    ~My_Class();
};

My_Class::My_Class(const My_Class &mc)
{
  (void) mc;
  cout << "Copy Constructor called." << endl;
}

My_Class::My_Class()
{
  cout << "Constructor called." << endl;
}

My_Class::~My_Class()
{
  cout << "Destructor called." << endl;
}

void proc1(My_Class c)
{
  (void) c;
}

void proc2(My_Class &c)
{
  (void) c;
}

void proc3(const My_Class &c)
{
  (void) c;
}

int main()
{
  My_Class c;
  vector <My_Class> v;

  v.resize(5, c);
  cout << "vector resized" << endl;
  proc1(c);
  proc2(c);
  proc3(c);
  
  cout << "returning" << endl;
  return 0;
}
