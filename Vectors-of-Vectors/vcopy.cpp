#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

typedef vector <double> DVec;

main()
{
  vector <DVec> v1, v2;
  DVec dv;
  int i, j;

  srand48(100);

  for (i = 0; i < 4; i++) {
    dv.clear();
    for (j = 0; j < 5; j++) dv.push_back(drand48()*10);
    v1.push_back(dv);
  }

  v2 = v1;

  for (i = 0; i < v2.size(); i++) {
    for (j = 0; j < v2[i].size(); j += 2) v2[i][j] = 0;
  }
  
  printf("V1:\n\n");

  for (i = 0; i < v1.size(); i++) {
    for (j = 0; j < v1[i].size(); j++) printf("%8.3lf", v1[i][j]);
    printf("\n");
  }
  
  printf("\nV2:\n\n");

  for (i = 0; i < v2.size(); i++) {
    for (j = 0; j < v2[i].size(); j++) printf("%8.3lf", v2[i][j]);
    printf("\n");
  }
}
