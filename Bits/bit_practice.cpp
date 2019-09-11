#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
  int w;
  unsigned short a, b, c;
  int i, op;
  string s;
  
  srandom(time(0));

  int f;

  w = 8;
  f = 'b';

  while (1) {
    
    a = random() % (1 << w);
    b = random() % (1 << w);
    op = random() % 8;

    printf("A is %8d  0x%04x  ", a, a);
    for (i = 15; i >= 8; i--) printf("%d",a & (1 << i) ? 1 : 0);
    printf(" ");
    for (i = 7; i >= 0; i--) printf("%d", a & (1 << i) ? 1 : 0);
    printf("\n");

    if (op > 0 && op < 4) {
      printf("B is %8d  0x%04x  ", b, b);
      for (i = 15; i >= 8; i--) printf("%d", b & (1 << i) ? 1 : 0);
      printf(" ");
      for (i = 7; i >= 0; i--) printf("%d", b & (1 << i) ? 1 : 0);
      printf("\n");
    }
    
    printf("Operation is ");

    switch(op) {
      case 0: printf("~\n\n");  c = ~a; break;
      case 1: printf("&\n\n");  c = (a&b); break;
      case 2: printf("|\n\n");  c = (a|b); break;
      case 3: printf("^\n\n");  c = (a^b); break;
      case 4: printf("<< 1\n\n");  c = (a << 1); break;
      case 5: printf(">> 1\n\n");  c = (a >> 1); break;
      case 6: printf("<< 4\n\n");  c = (a << 4); break;
      case 7: printf(">> 4\n\n");  c = (a >> 4); break;
    }

    if (!getline(cin, s)) exit(0);

    printf("C is %8d  0x%04x  ", c, c);

    for (i = 15; i >= 8; i--) printf("%d", c & (1 << i) ? 1 : 0);
    printf(" ");
    for (i = 7; i >= 0; i--) printf("%d", c & (1 << i) ? 1 : 0);
    printf("\n");

    printf("----------------\n");
    if (!getline(cin, s)) exit(0);
  }
  return 0;
}

