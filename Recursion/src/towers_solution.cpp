#include "towers.hpp"
#include <iostream>
using namespace std;

void Solve(Towers *t, int from, int to, int num_disks)
{
  int i, other;

  /* If there's just one disk on the pile to move, then move it and return. */ 

  if (num_disks == 1) {
    t->Move(from, to, true);
    t->Print();
    return;
  }

  /* Otherwise, figure out which tower is neither "from" nor "to".  Move the
     top (num_disks-1) disks to that tower recursively, move the bottom disk
     to the destination tower, and then move the (num_disks-1) disks from the
     temporary tower to the destination one. */

  for (i = 0; i < 3; i++) if (i != from && i != to) other = i;
  Solve(t, from, other, num_disks-1);
  t->Move(from, to, true);
  t->Print();
  Solve(t, other, to, num_disks-1);
}

int main()
{
  int npieces;
  Towers *t;

  while (1) {
    cout << "Enter the number of towers: ";
    cout.flush();
    if (!(cin >> npieces)) return 0;
    try {
      t = new Towers(npieces);
      t->Print();
      Solve(t, 0, 1, npieces);
      delete t;
      
    } catch (const string s) {
      cout << s << endl;
    }
  }
}
