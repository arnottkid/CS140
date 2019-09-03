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

  printf("%-30s %26s %26s %26s %26s %26s %26s\n", "", "a", "b", "ca", "ca2", "ca3", "argv[1]");
  printf("%-30s %26s %26s %26s %26s %26s %26s\n", "", "-------", "-------", "-------", "--------", "-------", "-------");

  printf("%-30s %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx\n", 
         "Start:", 
         a.c_str(), (long unsigned int) a.c_str(), 
         b.c_str(), (long unsigned int) b.c_str(), 
         ca, (long unsigned int) ca, 
         ca2, (long unsigned int) ca2, 
         ca3, (long unsigned int) ca3, 
         argv[1], (long unsigned int) argv[1]);
 
  a[0] = 'Y';
  printf("%-30s %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx\n", 
         "After setting a[0] to 'Y':", 
         a.c_str(), (long unsigned int) a.c_str(), 
         b.c_str(), (long unsigned int) b.c_str(), 
         ca, (long unsigned int) ca, 
         ca2, (long unsigned int) ca2, 
         ca3, (long unsigned int) ca3, 
         argv[1], (long unsigned int) argv[1]);
  
  ca[0] = 'L';
  printf("%-30s %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx\n", 
         "After setting ca[0] to 'L':", 
         a.c_str(), (long unsigned int) a.c_str(), 
         b.c_str(), (long unsigned int) b.c_str(), 
         ca, (long unsigned int) ca, 
         ca2, (long unsigned int) ca2, 
         ca3, (long unsigned int) ca3, 
         argv[1], (long unsigned int) argv[1]);
  
  a = "XX";
  printf("%-30s %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx\n", 
         "After setting a to \"XX\":",
         a.c_str(), (long unsigned int) a.c_str(), 
         b.c_str(), (long unsigned int) b.c_str(), 
         ca, (long unsigned int) ca, 
         ca2, (long unsigned int) ca2, 
         ca3, (long unsigned int) ca3, 
         argv[1], (long unsigned int) argv[1]);

  b = "XX";
  printf("%-30s %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx %7s 0x%016lx\n", 
         "After setting b to \"XX\":",
         a.c_str(), (long unsigned int) a.c_str(), 
         b.c_str(), (long unsigned int) b.c_str(), 
         ca, (long unsigned int) ca, 
         ca2, (long unsigned int) ca2, 
         ca3, (long unsigned int) ca3, 
         argv[1], (long unsigned int) argv[1]);
}
