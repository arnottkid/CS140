#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fields.h"

typedef struct {
  int board[9][9];
} Puzzle;

void print_board(Puzzle *p)
{
  int i;
  int j;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (p->board[i][j] < 0) {
        printf("- ");
      } else {
        printf("%d ", p->board[i][j]);
      }
      if (j % 3 == 2) printf("     ");
    }
    if (i % 3 == 2) printf("\n");
    printf("\n");
  }
}
  
int is_legal(Puzzle *p, int r, int c)
{
  int tester[10];
  int i;
  int entry;
  int sr, sc, j;

  entry = p->board[r][c];
  
  for (i = 1; i < 10; i++) tester[i] = 0;
  for (i = 0; i < 9; i++) {
    if (p->board[i][c] > 0) {
      entry = p->board[i][c];
      if (tester[entry]) return 0;
      tester[entry] = 1;
    }
  }

  for (i = 1; i < 10; i++) tester[i] = 0;
  for (i = 0; i < 9; i++) {
    if (p->board[r][i] > 0) {
      entry = p->board[r][i];
      if (tester[entry]) return 0;
      tester[entry] = 1;
    }
  }

  for (i = 1; i < 10; i++) tester[i] = 0;
  sr = (r - (r%3));
  sc = (c - (c%3));
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      entry = p->board[i+sr][j+sc];
      if (entry > 0) {
        if (tester[entry]) return 0;
        tester[entry] = 1;
      }     
    }
  }  

  return 1;
}

int solve(Puzzle *p)
{
  int i, j, k;
  int ok;

  /* Find an element whose entry is -1 */

  ok = 0;
  for (i = 0; !ok && i < 9; i++) {
    for (j = 0; j < 9 && p->board[i][j] != -1; j++) ;
    if (j < 9) ok = 1;
  }
  if (!ok) return 1;
  i--;

  for (k = 1; k <= 9; k++) {
    p->board[i][j] = k;
    if (is_legal(p, i, j)) {
      if (solve(p)) return 1;
    }
  }
  p->board[i][j] = -1;
  return 0;
}

int main()
{
  Puzzle *p;
  IS is;
  int i, j, entry;
  
  p = (Puzzle *) malloc(sizeof(Puzzle));
  is = new_inputstruct(NULL);

  for (i = 0; i < 9; i++) {
    get_line(is);
    for (j = 0; j < 9; j++) {
      if (is->fields[j][0] == '-') {
        p->board[i][j] = -1;
      } else {
        entry = is->fields[j][0] - '0';
        p->board[i][j] = entry;
      }
    }
  } 
  if (solve(p)) {
    print_board(p);
  } else {
    printf("You Lose\n");
  }
}
