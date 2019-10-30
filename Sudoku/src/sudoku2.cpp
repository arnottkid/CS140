/* Our second pass implements Read_From_Stdin() to read puzzles, and
   Print_Screen() to print what we've read.  There is minimal error
   checking at this point. */

#include <iostream>
#include <sstream>
#include "sudoku.hpp"
using namespace std;

string Sudoku::Read_From_Stdin()
{
  int i, j;
  char c;
  ostringstream oss;        // This is to build an error string.

  /* Read 81 characters, error checking for legal characters, and EOF.
     The try/catch is nice because you want to clear the grid on all errors. */

  Grid.clear();
  Grid.resize(9);
  
  try {
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {

        /* Handle EOF -- if nothing was read, return "EOF"; otherwise return an error. */

        if (!(cin >> c)) {
          if (i == 0 && j == 0 && cin.eof()) throw((string) "EOF");
          throw((string) "Bad Sudoku File -- not enough entries");
        }

        /* Error check the digit. */

        if (c == '-' || (c >= '0' && c <= '9')) {
          Grid[i].push_back(c);
        } else {
          oss << "Bad character at row " << i << ", column " << j << ": " << c ;
          throw(oss.str());
        } 
      }
    }
 
  /* Clear the grid when you get an error. */

  } catch (const string s) {
    Grid.clear();
    return s;
  }

  /* Otherwise, return "" on success. */

  return "";
}

/* Print_Screen() prints the grid, putting a space between characters, an extra 
   space between panel columns, and an extra line between panel rows. */

void Sudoku::Print_Screen() const
{
  size_t i, j;

  for (i = 0; i < Grid.size(); i++) {
    for (j = 0; j < Grid[i].size(); j++) {
      if (j != 0) cout << " ";
      cout << Grid[i][j];
      if (j == 2 || j == 5) cout << " ";
    }
    cout << endl;
    if (i == 2 || i == 5) cout << endl;
  }
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
  Grid.clear();
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

