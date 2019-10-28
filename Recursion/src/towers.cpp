#include "towers.hpp"
#include <cstdio>
#include <iostream>
using namespace std;

/* The constructor puts all of the disks onto tower 0.
   The front of the deque is the top of the tower */

Towers::Towers(int n)
{
  int i;

  if (n <= 0) throw ((string) "Towers::Towers() - Bad value of n");
  for (i = 1; i <= n; i++) T[0].push_back(i);
}

/* Moving is mostly a matter of error checking.  If all is ok,
   we remove the disk from the front of the "from" tower and
   add it to the front of the "to" tower. */

string Towers::Move(int from, int to, bool print)
{
  int disk;
  /* Error checking */

  if (from < 0 || from > 2) return "Bad source tower";
  if (to < 0 || to > 2) return "Bad destiniation tower";
  if (T[from].empty()) return "Source tower is empty";
  if (!T[to].empty() && T[from][0] > T[to][0]) {
    return "Disk on the source tower is bigger than the top of the destination tower";
  }
  
  /* Move the disk and return success */

  disk = T[from][0];
  T[to].push_front(disk);
  T[from].pop_front();
  if (print) printf("Moving disk of size %d from tower %d to tower %d\n", disk, from, to);
  return "";
}

/* Print() creates ASCII art of the towers.  Since we want them to have their
   bases line up, we have to put in a little effort to print the right values
   in the right places. */

void Towers::Print() const
{
  int max_disk, dots, spaces;
  size_t max_height, i, index;
  int j, k;

  /* Calculate the maximum size disk, and the height of the tallest tower. */

  max_disk = T[0].size() + T[1].size() + T[2].size();
  max_height = T[0].size();
  if (T[1].size() > max_height) max_height = T[1].size();
  if (T[2].size() > max_height) max_height = T[2].size();

  /* Now, go from top to bottom, then left to right, and for each row and
     tower, first figure out if you are printing a disk.  If so, you set
     "dots" to be the size of the disk.  If there is no disk, "dots" is zero.
     Then you'll print "dots" dots, and (max_disk-dots+1) spaces (the extra space
     is to put spaces between the towers. */

  for (i = 0; i < max_height; i++) {
    index = max_height - i - 1;
    for (j = 0; j < 3; j++) {
      if (T[j].size() > index) {
        dots = T[j][T[j].size()-index-1];
      } else {
        dots = 0;
      }
      spaces = max_disk - dots + 1;
      for (k = 0; k < dots; k++) printf(".");
      for (k = 0; k < spaces; k++) printf(" ");
    }
    printf("\n");
  }

  /* Finally, print the bases of the towers */

  for (j = 0; j < 3; j++) {
    for (k = 0; k < max_disk; k++) printf("-");
    printf(" ");
  }
  printf("\n");
}
