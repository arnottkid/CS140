#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

main(int argc, char **argv)
{
  string a, b;
  char *ca, *ca2, *ca4; 
  const char *ca3;

  if (argc != 2) { cerr << "usage: argv-mess arg1\n"; exit(1); }

  a = argv[1];
  ca = argv[1];
  ca2 = ca;
  b = a;
  ca3 = a.c_str();

  printf("%-30s %7s %7s %7s %7s %7s %7s\n", "", "a", "b", "ca", "ca2", "ca3", "argv[1]");
  printf("%-30s %7s %7s %7s %7s %7s %7s\n", "", "-------", "-------", "-------", "--------", "-------", "-------");

  printf("%-30s %7s %7s %7s %7s %7s %7s\n", "Start:", 
         a.c_str(), b.c_str(), ca, ca2, ca3, argv[1]);
 
  a[0] = 'Y';
  printf("%-30s %7s %7s %7s %7s %7s %7s\n", "After setting a[0] to 'Y':", 
         a.c_str(), b.c_str(), ca, ca2, ca3, argv[1]);
  
  ca[0] = 'L';
  printf("%-30s %7s %7s %7s %7s %7s %7s\n", "After setting ca[0] to 'L':", 
         a.c_str(), b.c_str(), ca, ca2, ca3, argv[1]);
  
  a = "XX";
  printf("%-30s %7s %7s %7s %7s %7s %7s\n", "After setting a to \"XX\":",
         a.c_str(), b.c_str(), ca, ca2, ca3, argv[1]);
}
