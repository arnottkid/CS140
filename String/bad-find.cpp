#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

main()
{
  string a, b;
  int i;

  a = "Lighting Strikes.  Lightning Strikes Again.";
  b = "Light";

  printf("    ");
  for (i = 0; i < 43; i++) printf("%d", i%10);
  printf("\n");

  printf("a = %s\n", a.c_str());
  printf("a.find(b, 1, 3) = %d\n", a.find(b, 1, 3));
}
