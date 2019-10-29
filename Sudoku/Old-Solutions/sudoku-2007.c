#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fields.h"

int find_hyphen(int *p)
{
  int i;

  for (i = 0; i < 81; i++) if (p[i] == '-') return i;
  return -1;
}
  
int is_row_valid(int *p, int r)
{
  int checker[10];
  int i, c;

  for (i = 1; i < 10; i++) checker[i] = 0;
  for (i = 0; i < 9; i++) {
    c = p[r*9+i];
    if (c != '-') {
      c -= '0';
      if (checker[c] != 0) return 0;
      checker[c] = 1;
    }
  }
  return 1;
}

int is_panel_valid(int *p, int row, int col)
{
  int checker[10];
  int i, j, c;

  row = row - row % 3;
  col = col - col % 3;
  for (i = 1; i < 10; i++) checker[i] = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c = p[(row+i)*9+col+j];
      if (c != '-') {
        c -= '0';
        if (checker[c] != 0) return 0;
        checker[c] = 1;
      }
    }
  }
  return 1;
}

int is_col_valid(int *p, int r)
{
  int checker[10];
  int i, c;

  for (i = 1; i < 10; i++) checker[i] = 0;
  for (i = 0; i < 9; i++) {
    c = p[i*9+r];
    if (c != '-') {
      c -= '0';
      if (checker[c] != 0) return 0;
      checker[c] = 1;
    }
  }
  return 1;
}

int solve(int *p)
{
  int i, r, c, index;

  index = find_hyphen(p);
  if (index == -1) return 1;
  r = index/9;
  c = index%9;

  for (i = '1'; i <= '9'; i++) {
    p[index] = i;
    if (is_row_valid(p, r) && is_col_valid(p, c) && is_panel_valid(p, r, c)) {
      if (solve(p)) return 1;
    }
  }
  p[index] = '-';
  return 0;
}

void print_puzzle(int *p)
{
  int i, j;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      printf("%c", p[i*9+j]);
      if (j == 2 || j == 5) printf(" ");
    }
    printf("\n%s", (i == 2 || i == 5) ? "\n" : "");
  }
}

main()
{
  IS is;
  int i, j;

  int *puzzle;

  puzzle = (int *) malloc(sizeof(int)*9*9);
  if (puzzle == NULL) { perror("malloc"); exit(1); }

  is = new_inputstruct(NULL);

  for (i = 0; i < 9; i++) {
    if (get_line(is) != 9) {
      printf("bad dog\n");
      exit(1);
    }
    for (j = 0; j < 9; j++) {
      if (is->fields[j][0] > '0' && is->fields[j][0] <= '9') {
        puzzle[i*9+j] = is->fields[j][0];
      } else {
        puzzle[i*9+j] = '-';
      }
    }
  }
  jettison_inputstruct(is);
  for (i = 0; i < 9; i++) {
    if (!is_row_valid(puzzle, i)) {
      printf("Row %d is bad\n", i);
      exit(1);
    }
    if (!is_col_valid(puzzle, i)) {
      printf("Column %d is bad\n", i);
      exit(1);
    }
  }
  for (i = 0; i < 9; i += 3) {
    for (j = 0; j < 9; j += 3) {
      if (!is_panel_valid(puzzle, i, j)) {
        printf("Panel %d,%d is bad\n", i, j);
        exit(1);
      }
    }
  }
  if (solve(puzzle)) {
    print_puzzle(puzzle);
  } else {
    printf("Can't solve it.  Darn.\n");
  }
}


