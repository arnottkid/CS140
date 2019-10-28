#include <iostream>
#include <deque>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Towers {
  public:
    Towers(int n);
    void Make_Move(int from, int to);
    void Print();
  protected:
    deque <int> T[3];
};

