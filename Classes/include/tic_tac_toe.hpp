#pragma once
 
#include <vector>
#include <string>

class Tic_Tac_Toe
{
  public:
    Tic_Tac_Toe();                    /* Constructor */
    void Clear_Game();                /* Turn the current board into an empty board */
    char Game_State() const;          /* Return the state of the game:
                                           'B' = beginning of game
                                           'X' = X's turn
                                           'O' = O's turn
                                           'x' = Game is over and X has won.
                                           'o' = Game is over and O has won.
                                           'd' = Game is over and it's a draw. */

    char Make_Move(char xo, size_t row, size_t col);  /* This does the move.  
                                                         xo must be 'X' or 'O'.
                                                         Returns 'E' on an error.
                                                         Otherwise it returns resulting game state. */

    void Print() const;                         /* Prints the board. */
    std::string Board_String() const;           /* Returns a 9-character string of X's, O's and -'s */
    void Stats(std::vector <int> &xod) const;   /* Sets xod to a three element vector: 
                                                   X wins, O wins, draws */

  protected:
    std::vector <std::string> Board;    /* The board */
    char State;                         /* Game state -- same values as Game_State() above */
    std::vector <int> X_O_D;            /* The three stats */
    int Open_Squares;                   /* The number of open squares on the board. */
};
