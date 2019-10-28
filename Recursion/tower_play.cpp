#include "towers.h"

main(int argc, char **argv)
{
  Towers *t;
  int npieces;
  int from, to;

  if (argc != 2) {
    fprintf(stderr, "usage: tower_play size\n");
    exit(1);
  }

  npieces = atoi(argv[1]);

  t = new Towers(npieces);
  t->Print();

  while (cin >> from >> to) {
    t->Make_Move(from, to);
    printf("\n");
    t->Print();
    printf("\n");
  }
}
