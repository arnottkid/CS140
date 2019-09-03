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
  printf("b = %s\n", b.c_str());
  printf("a.find(b) = %ld\n", a.find(b));
  printf("a.find(b, 1) = %ld\n", a.find(b, 1));
  printf("a.find(b, 20) = %ld\n", a.find(b, 20));
  printf("a.find('g') = %ld\n", a.find('g'));
  printf("a.find('g', 20) = %ld\n", a.find('g', 20));
  printf("a.find(\"Strike\") = %ld\n", a.find("Strike"));
  printf("a.find(\"Strike\", 20) = %ld\n", a.find("Strike", 20));
  printf("a.find(\"Aging\", 0, 2) = %ld\n", a.find("Aging", 0, 2));
  printf("string::npos = %ld\n", string::npos);
}
