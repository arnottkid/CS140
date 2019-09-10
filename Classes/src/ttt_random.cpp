/* This program allows us to do a scientific experiment on tic-tac-toe.  The hypothesis is that
   if you start the game in the middle square, and then play the game randomly, you will do 
   betting than simply playing randomly. 

   The program is a nice demonstration of how our Tic_Tac_Toe class can serve multiple
   goals (playing the game interactively, and doing a scientific experiment. */

#include "tic_tac_toe.hpp"
#include "MOA.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

/* On the command line, we're going to read a number of iterations and a seed
   for a random number generator (this is why we included "MOA.hpp" above). */

int main(int argc, char **argv)
{
  Tic_Tac_Toe ttt;                     // The game player
  vector <int> stats;                  // For the final Stats() call
  MOA rng;                             // Random number generator
  istringstream ss;                    // For parsing the command line arguments

  size_t iterations;                   // The number of games to play
  size_t seed;                         // Seed for the random number generator
  size_t games_played;                 // Keeping track of the number of games played
  char start;                          // Who starts the game
  char turn;                           // Whose turn it is
  char state;                          // The game state
  string bs;                           // The board string, which helps do the random choosing
  vector <size_t> legal_moves_r;       // Legal moves -- the row numbers
  vector <size_t> legal_moves_c;       // Legal moves -- the column numbers
  
  size_t i;

  /* Parse and error check the command line */

  try {
    if (argc != 3) throw((string) "usage: bin/ttt_random iterations seed");
    ss.clear(); ss.str(argv[1]); if (!(ss >> iterations)) throw((string) "Bad iterations");
    ss.clear(); ss.str(argv[2]); if (!(ss >> seed)) throw((string) "Bad seed");
  } catch (string s) {
    cout << s << endl;
    return 1;
  }

  /* Initialize everything */

  rng.Seed(seed);
  start = 'X';
  games_played = 0;
  
  /* Keep going until you complete enough games.
     You only increment games_played when a game is over. */

  while (games_played < iterations) {
 
    // printf("%s\n", ttt.Board_String().c_str());     This is useful for debugging.

    /* If the game isn't over, then determine whose turn it is, and then
       determine the legal moves that can be made.  Choose one of them randomly.
       When it's X's turn and it's the beginning of a game, set it up so that
       the only legal move is to use the center square. */

    state = ttt.Game_State();
    if (state == 'B' || state == 'X' || state == 'O') {
      turn = (state == 'B') ? start : state;
      legal_moves_r.clear();
      legal_moves_c.clear();

      /* This is how to handle when the game is starting and it's X's turn. */

      if (state == 'B' && turn == 'X') {
        legal_moves_r.push_back(1);
        legal_moves_c.push_back(1);

      /* Otherwise, use the dashes in the board string to determine the legal moves. */

      } else {
        bs = ttt.Board_String();
        for (i = 0; i < bs.size(); i++) {
          if (bs[i] == '-') {
            legal_moves_r.push_back(i/3);
            legal_moves_c.push_back(i%3);
          }
        }
      }

      /* Choose a random legal move and make it. */

      i = rng.Random_Integer()%legal_moves_r.size();
      ttt.Make_Move(turn, legal_moves_r[i], legal_moves_c[i]);

    /* Otherwise, the game is over.  Update the games played, and set the
       starting player to the other player. */

    } else {
      games_played++;
      ttt.Clear_Game();
      start = (start == 'X') ? 'O' : 'X';
    }
  }

  /* At the end, print the stats. */

  ttt.Stats(stats);
  printf("Stats: X:%d O:%d D:%d\n", stats[0], stats[1], stats[2]);
  return 0;
}
