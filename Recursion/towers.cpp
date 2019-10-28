#include "towers.h"

Towers::Towers(int n)
{
  int i;

  for (i = 1; i <= n; i++) T[0].push_back(i);
}

void Towers::Make_Move(int from, int to)
{
  if (from < 0 || from > 2) {
    printf("Bad Source Tower (%d)\n", from);
  } else if (to < 0 || to > 2) {
    printf("Bad Destination Tower (%d)\n", to);
  } else if (T[from].empty()) {
    printf("Can't move from tower %d to %d -- tower %d is empty\n", from, to, from);
  } else if (!T[to].empty() && T[from][0] > T[to][0]) {
    printf("Can't move from tower %d to %d -- piece is too big (%d can't go on top of %d)\n", 
      from, to, T[from][0], T[to][0]);
  } else {
    printf("Moving %d from tower %d to tower %d\n", T[from][0], from, to);
    T[to].push_front(T[from][0]);
    T[from].pop_front();
  }
}

void Towers::Print()
{
  int mx, mxe, dots, spaces;
  int i, j, k;

  mx = T[0].size() + T[1].size() + T[2].size();
  mxe = T[0].size();
  if (T[1].size() > mxe) mxe = T[1].size();
  if (T[2].size() > mxe) mxe = T[2].size();

  for (i = mxe-1; i >= 0; i--) {
    for (j = 0; j < 3; j++) {
      if (T[j].size() > i) {
        dots = T[j][T[j].size()-i-1];
      } else {
        dots = 0;
      }
      spaces = mx - dots + 1;
      for (k = 0; k < dots; k++) printf(".");
      for (k = 0; k < spaces; k++) printf(" ");
    }
    printf("\n");
  }
  for (j = 0; j < 3; j++) {
    for (i = 0; i < mx; i++) printf("-");
    printf(" ");
  }
  printf("\n");
}
