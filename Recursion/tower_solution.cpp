#include <stdio.h>
#include "towers.h"

void Solve(Towers *t, int from, int to, int npieces)
{
  int i, other;

  if (npieces == 1) {
    t->Make_Move(from, to);
    t->Print();
    return;
  }

  for (i = 0; i < 3; i++) if (i != from && i != to) other = i;
  Solve(t, from, other, npieces-1);
  t->Make_Move(from, to);
  t->Print();
  Solve(t, other, to, npieces-1);
}

main(int argc, char **argv)
{
  int npieces;
  Towers *t;

  if (argc != 2) {
    fprintf(stderr, "usage: tower_solution size\n");
    exit(1);
  }

  npieces = atoi(argv[1]);
  if (npieces <= 0) exit(1);
  t = new Towers(npieces);

  t->Print();
  Solve(t, 0, 1, npieces);
}
