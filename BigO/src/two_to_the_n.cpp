/* This program is identical to linear1.cpp, but it executes its for loop 2^n times. */

#include <sys/time.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  long long n, count, i;
  double start_time, end_time;
  struct timeval tv;

  if (!(cin >> n)) return 1;

  /* Get the starting time. */

  gettimeofday(&tv, NULL);
  start_time = tv.tv_usec;
  start_time /= 1000000.0;
  start_time += tv.tv_sec;

  /* This loop executes 2^n times. */

  count = 0;
  for (i = 0; i < (1LL << n); i++) {
    count++;
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
