#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/* We resize a vector of My_Class elements and 
   exit, just to see what the constructors and
   destructors do */

class My_Class {
  public:
    My_Class();
    ~My_Class();
};

My_Class::My_Class()
{
  cout << "Constructor called." << endl;
}

My_Class::~My_Class()
{
  cout << "Destructor called." << endl;
}

int main()
{
  vector <My_Class> v;

  v.resize(5);
  return 0;
}
