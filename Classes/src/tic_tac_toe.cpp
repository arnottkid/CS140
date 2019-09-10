/* The only difference here from src/tic_tac_toe.cpp is that I implement Make_Move() */

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

/* Make_Move() goes through the following steps:

   - Error check the arguments
   - Update the Board and Open_Squares
   - Test to see if whoever called Make_Move() has now won the game.  If so,
     update the stats and set the State to 'X' or 'O'.
   - Otherwise, test to see if the game is a Draw, and set its state to 'D'.
   - Finally, if the game isn't over, set the game state to 'X' or 'O' 
     to indicate whose turn it is. */

char Tic_Tac_Toe::Make_Move(char xo, size_t row, size_t col) 
{
  bool win;                  // This is used to record whether the caller has won the game.
 
  /* Error Check */

  if (xo != 'X' && xo != 'O') return 'E';
  if (xo == 'X' && State != 'B' && State != 'X') return 'E';
  if (xo == 'O' && State != 'B' && State != 'O') return 'E';
  if (row >= 3) return 'E';
  if (col >= 3) return 'E';
  if (Board[row][col] != '-') return 'E';

  /* Update the Board and decrement the number of open squares */

  Board[row][col] = xo;
  Open_Squares--;

  /* Test to see if whoever calls Make_Move has won.  The tests go in the following order:
       - Check to see if the move completed a row.
       - Check to see if the move completed a column.
       - Check to see if the move completed the \ diagonal
       - Check to see if the move completed the / diagonal */

  if (Board[row][0] == Board[row][1] && Board[row][0] == Board[row][2]) {
    win = true;
  } else if (Board[0][col] == Board[1][col] && Board[0][col] == Board[2][col]) {
    win = true;
  } else if (row == col && Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2]) {
    win = true;
  } else if (row+col == 2 && Board[0][2] == Board[1][1] && Board[2][0] == Board[1][1]) {
    win = true;
  } else {
    win = false;
  }

  /* If the player won the game, update the stats and state accordingly. */

  if (win) {
    if (xo == 'X') {
      State = 'x';
      X_O_D[0]++;
    } else if (xo == 'O') {
      State = 'o';
      X_O_D[1]++;
    }

  /* Otherwise, if the game is a draw, then update the stats and state accordingly. */

  } else if (Open_Squares == 0) {
    State = 'D';
    X_O_D[2]++;

  /* Otherwise, set the State to whoever's turn it is */

  } else if (xo == 'X') {
    State = 'O';
  } else {
    State = 'X';
  }

  /* Finally, return the state. */

  return State;
}
