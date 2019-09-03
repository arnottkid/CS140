#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

main()
{
  string a;
  int i;

  a = "Lighting Strikes.  Lightning Strikes Again.";

  printf("    ");
  for (i = 0; i < 43; i++) printf("%d", i%10);
  printf("\n");

  printf("a = %s\n", a.c_str());
  printf("a.substr(19) = %s\n", a.substr(19).c_str());
  printf("a.substr(19, 13) = %s\n", a.substr(19, 13).c_str());
  printf("a.substr(19, 13).substr(5) = %s\n", a.substr(19, 13).substr(5).c_str());
}
