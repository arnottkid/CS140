#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/* Now we resize with a default value. */

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
  My_Class c;
  vector <My_Class> v;

  v.resize(5, c);
  return 0;
}
