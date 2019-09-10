/* This implementation file simply has dummy methods for every method in the class.
   It allows me to write a testing program and have it compile.  Then, I'll start
   to implement the methods. */

#include "tic_tac_toe.hpp"
using namespace std;

Tic_Tac_Toe::Tic_Tac_Toe() {}

void Tic_Tac_Toe::Clear_Game() {}

void Tic_Tac_Toe::Print() const {}

char Tic_Tac_Toe::Game_State() const { return '-'; }

string Tic_Tac_Toe::Board_String() const { return "-"; }

void Tic_Tac_Toe::Stats(vector <int> &xod) const 
{ 
  xod.resize(3, 0); 
}

char Tic_Tac_Toe::Make_Move(char xo, size_t row, size_t col) 
{ 
  (void) xo;        // These statements shut the compiler up about not using the parameters.
  (void) row;
  (void) col;
  return 'E'; 
}
