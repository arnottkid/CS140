#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector <int> v1;
  vector <double> v2;
  int i;

  v1.resize(5, 22);
  v1.resize(8, 33);

  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  v1.resize(6);
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  v1.resize(10, 44);
  for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); 
  printf("\n");

  v2.resize(10, drand48());
  printf("\n");
  for (i = 0; i < v1.size(); i++) printf(" %4.2lf", v2[i]); 
  printf("\n");
}
