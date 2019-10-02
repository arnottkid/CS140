#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  int i;

  for (i = 0; i < 10000000; i++) printf("%.2lf\n", drand48()*1000000);
}
