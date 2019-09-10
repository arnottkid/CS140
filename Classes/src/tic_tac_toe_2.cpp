/* In this program, I implement the easy methods, which is all of the methods besides Make_Move() */

#include "tic_tac_toe.hpp"
#include <iostream>
using namespace std;

/* The constructor calls Clear_Game() to set up the empty board.
   It also creates the X_O_D vector and sets its entries to zero. */

Tic_Tac_Toe::Tic_Tac_Toe() 
{
  Clear_Game();
  X_O_D.resize(3, 0);
}

/* Clear_Game() creates an empty board with all dashes.  It sets the game state
   to 'B', for "Beginning", and sets the number of open squares to 9, since 
   all of the squares are empty. */

void Tic_Tac_Toe::Clear_Game() 
{
  State = 'B';
  Board.clear();
  Board.push_back("---");
  Board.push_back("---");
  Board.push_back("---");
  Open_Squares = 9;
}

/* Print() is simple, printing out the Board, one row per line. */

void Tic_Tac_Toe::Print() const 
{
  size_t i;

  for (i = 0; i < Board.size(); i++) cout << Board[i] << endl;
}

/* Game_State() is also simple, simply returning the State variable. */

char Tic_Tac_Toe::Game_State() const 
{
  return State; 
}

/* Board_String() concatenates the three rows of the Board together to make a single
   string without any newlines. */

string Tic_Tac_Toe::Board_String() const 
{ 
  string rv;

  rv = Board[0] + Board[1] + Board[2];
  return rv;
}

/* State() just copies X_O_D to its argument, which is a reference parameter. */

void Tic_Tac_Toe::Stats(vector <int> &xod) const 
{ 
  xod = X_O_D;
}

/* Make_Move() is still unwritten. */

char Tic_Tac_Toe::Make_Move(char xo, size_t row, size_t col) 
{
  (void) xo;
  (void) row;
  (void) col;
  return '.'; 
}
