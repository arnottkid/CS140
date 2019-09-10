/* This program runs a more natural command-line version of tic-tac-toe than
   src/ttt_tester.cpp.  Note how it makes use of the game state to help it
   play the game. */

#include "tic_tac_toe.hpp"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  Tic_Tac_Toe ttt;                  // The game player
  vector <int> stats;               // This is for reading the stats
  size_t row, col;                  // These are entered on standard input for Make_Move()
  char start;                       // 'X' or 'O' for who starts the game
  char turn;                        // 'X' or 'O' for whose turn it is
  char state;                       // The game state.
  
  /* Set it up so that 'X' plays the first game.  
     We will alternate this between games. */

  start = 'X';

  while (1) {
 
    /* Get the game state, and print the board. */

    state = ttt.Game_State();
    cout << endl;
    ttt.Print();
    cout << endl;

    /* If we're playing the game, then figure out whose turn it is,
       and then get the player's move from standard input. */

    if (state == 'B' || state == 'X' || state == 'O') {
      turn = (state == 'B') ? start : state;
      cout << turn  << "'s Move: ";
      cout.flush();
      if (!(cin >> row >> col)) return 0;

      /* If the move is illegal, then we print an error message.
         Then, regardless of whether the move was legal or illegal,
         we're simply going to go to the top of the while loop.
         If there was an error, we'll simply repeat this code.
         Otherwise, the game will move on. */

      if (ttt.Make_Move(turn, row, col) == 'E') {
        cout << endl << "Bad input -- try again, please." << endl;
      }
        
    /* Otherwise, the game is over.  We're going to do the following things:
        - Print the winner (or whether it's a draw).
        - Print the stats.
        - Start a new game
        - Set the starting player to the other player. */

    } else {
      if (state == 'D') {
        printf("Draw\n");
      } else {
        printf("%c Wins!\n", state + ('A' - 'a'));   // This converts the lower-case to upper-case.
      }

      ttt.Stats(stats);
      printf("Stats: X:%d O:%d D:%d\n", stats[0], stats[1], stats[2]);

      ttt.Clear_Game();
      start = (start == 'X') ? 'O' : 'X';
    }
  }
}
