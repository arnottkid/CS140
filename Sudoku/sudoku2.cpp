#include <cstdio>
#include <cstdlib>
#include "sudoku.h"

Sudoku::Sudoku()
{
  int i, j;
  char c;

  Grid.resize(9);
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (!(cin >> c)) {
        cerr << "Bad Sudoku File -- not enough entries\n";
        exit(1);
      } 
      if (c == '-' || (c >= '0' && c <= '9')) {
        Grid[i].push_back(c);
      } else {
        cerr << "Bad Sudoku File -- entry: " << c << endl;
        exit(1);
      } 
    }
  }
}

void Sudoku::Print_Screen()
{
  int i, j;

  for (i = 0; i < Grid.size(); i++) {
    for (j = 0; j < Grid[i].size(); j++) {
      if (j != 0) printf(" ");
      printf("%c ", Grid[i][j]);
      if (j == 2 || j == 5) printf("  ");
    }
    printf("\n");
    if (i == 2 || i == 5) printf("\n");
  }
}

void Sudoku::Print_Convert()
{
}

int Sudoku::Solve()
{
  return 0;
}

int Sudoku::Is_Row_Valid(int r)
{
  return 0;
}

int Sudoku::Is_Col_Valid(int c)
{
  return 0;
}

int Sudoku::Is_Panel_Valid(int sr, int sc)
{
  return 0;
}

int Sudoku::Recursive_Solve(int r, int c)
{
  return 0;
}

