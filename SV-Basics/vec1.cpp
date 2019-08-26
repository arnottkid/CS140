#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector <int> v1;
  vector <double> v2(10);
  int i;

  printf("V1's size: %ld.  V2's size: %ld\n", v1.size(), v2.size());
     // It is unfortunate that size() returns a "long", so you must use "%ld".
     // We'll talk about it in class

  v1.resize(5);
  v2.resize(8);

  printf("V1's size: %ld.  V2's size: %ld\n", v1.size(), v2.size());

  for (i = 0; i < v1.size(); i++) v1[i] = 10 + i;
  for (i = 0; i < v2.size(); i++) v2[i] = 20.3 + i;

  printf("V1:"); for (i = 0; i < v1.size(); i++) printf(" %d", v1[i]); printf("\n");
  printf("V2:"); for (i = 0; i < v2.size(); i++) printf(" %.1lf", v2[i]); printf("\n");
}

