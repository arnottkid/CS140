/* A program to show an assignment overload */

#include <iostream>
#include <cstdio>
using namespace std;

class Crazy_Class {
  public:
    int value;
    Crazy_Class& operator= (const Crazy_Class &cc);
};

/* The assignment overload copies value+1 from the original class. */

Crazy_Class& Crazy_Class::operator= (const Crazy_Class &cc)
{
  value = cc.value+1;
  return *this;
}

int main()
{
  Crazy_Class c1, c2;

  c1.value = 5;
  c2 = c1;
  cout << c2.value << endl;
}

