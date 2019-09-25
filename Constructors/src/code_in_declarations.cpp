#include <iostream>
using namespace std;

/* Here's a program where the constructor has side effects on its parameter.
   By the time you're done declaring parameters, the value of i is 105. */

class My_Class {
  public:
    My_Class(int &i);
};

My_Class::My_Class(int &i)
{
  i += 50;
}

int main()
{
  int i = 5;
  My_Class c1(i), c2(i);
  
  cout << i << endl;
  return 0;
}
