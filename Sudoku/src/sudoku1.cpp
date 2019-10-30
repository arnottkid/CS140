/* This is a file which implements dummy solutions for every method of sudoku.hpp.
   It will compile, but it won't solve anything. */

#include <iostream>
#include "sudoku.hpp"
using namespace std;


string Sudoku::Read_From_Stdin()
{
  return "Read_From_Stdin is not implemented yet";
}

void Sudoku::Print_Screen() const
{
}

void Sudoku::Print_Convert() const
{
}

bool Sudoku::Solve()
{
  return false;
}

void Sudoku::Clear()
{
}

bool Sudoku::Is_Row_Valid(int r) const
{
  (void) r;
  return false;
}

bool Sudoku::Is_Col_Valid(int c) const
{
  (void) c;
  return false;
}

bool Sudoku::Is_Panel_Valid(int sr, int sc) const
{
  (void) sr;
  (void) sc;
  return false;
}

bool Sudoku::Recursive_Solve(int r, int c)
{
  (void) r;
  (void) c;
  return false;
}

