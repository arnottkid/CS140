#include "tic_tac_toe.hpp"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/* It's good to put this in a procedure at the beginning of your file -- that
   way you know where it is for reference, while you're writing the program. */

void print_commands()
{
  cout << "usage: ttt_tester -- commands on stdin." << endl;
  cout << endl;
  cout << "commands:" << endl;
  cout << "  C            - Clear game state." << endl;
  cout << "  GS           - Print the game state char." << endl;
  cout << "  P            - Print the board." << endl;
  cout << "  BS           - Print the Board String." << endl;
  cout << "  S            - Print stats." << endl;
  cout << "  M X/O R C    - Move X or O to space at row R, col C." << endl;
  cout << "  Q            - Quit." << endl;
  cout << "  ?            - Print commands." << endl;
}


int main()
{
  string s, line;         // I use these to read a line of text and turn it into a 
  vector <string> sv;     // vector of strings (which is in sv).
  istringstream ss;

  Tic_Tac_Toe ttt;        // Here's my tic-tac-toe game.
  vector <int> stats;     // This is for when I call ttt.Stats()

  int row, col;           // These are for the ttt.Make_Move(xo, row, col) call.
  char xo;

  while (1) {
 
    /* Print a prompt, and read in a line. */

    cout << "TTT> ";
    cout.flush();
    if (!getline(cin, line)) return 0;

    /* Use a stringstream to turn the line into a vector of words. */

    sv.clear();
    ss.clear();
    ss.str(line);
    while (ss >> s) sv.push_back(s);

    /* Ignore blank lines and lines that start with the pound sign. */

    if (sv.size() == 0 || sv[0][0] == '#') {

    /* Handle the simple commands: */

    } else if (sv[0] == "P") {
      ttt.Print();
    } else if (sv[0] == "C") {
      ttt.Clear_Game();
    } else if (sv[0] == "GS") {
      printf("%c\n", ttt.Game_State());
    } else if (sv[0] == "BS") {
      printf("%s\n", ttt.Board_String().c_str());

    /* Stats */

    } else if (sv[0] == "S") {
      ttt.Stats(stats);
      printf("X Wins: %4d\n", stats[0]);
      printf("O Wins: %4d\n", stats[1]);
      printf("Draws:  %4d\n", stats[2]);

    /* Make a move.  
       You'll note that I'm not using a stringstream for row/col.  This code
       is simpler, and since row and col have to be between 0 and 2, it works
       just fine.  You'll note that I'm not doing much error-checking here.
       That will be handled in Make_Move() which returns 'E' if it is called
       incorrectly.  */

    } else if (sv[0] == "M") {
      if (sv.size() != 4) {
        printf("Usage M X/O row col\n");
      } else {
        xo = sv[1][0];
        row = sv[2][0] - '0';
        col = sv[3][0] - '0';
        printf("Result of move: %c\n", ttt.Make_Move(xo, row, col));
      }

    /* Quit, print commands or a bad command. */

    } else if (sv[0] == "Q") {
      return 0;
    } else if (sv[0] == "?") {
      print_commands();
    } else {
      printf("Unknown command %s\n", sv[0].c_str());
    }
  }
}
