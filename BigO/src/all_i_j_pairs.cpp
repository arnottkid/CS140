/* This program is identical to linear1.cpp, but it enumerates all i,j pairs 
   such that 0 <= i < j < n.  This is loop that comes up in computer science,
   which iterates (n + 1) * n / 2 times. */

#include <sys/time.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  long long n, count, i, j;
  double start_time, end_time;
  struct timeval tv;

  if (!(cin >> n)) return 1;

  /* Get the starting time. */

  gettimeofday(&tv, NULL);
  start_time = tv.tv_usec;
  start_time /= 1000000.0;
  start_time += tv.tv_sec;

  /* This loop executes (n + 1) * n / 2 times. */

  count = 0;
  for (j = 0; j < n; j++) {
    for (i = 0; i < j; i++) {
      count++;
    }
  }

  /* Get the ending time. */

  gettimeofday(&tv, NULL);
  end_time = tv.tv_usec;
  end_time /= 1000000.0;
  end_time += tv.tv_sec;

  /* Print N, the iterations, and the time. */

  printf("N: %lld     Count: %lld    Time: %.3lf\n", n, count, end_time - start_time);
  return 0;
}
