#include <cstdio>
#include <cstdlib>
#include "sudoku.h"

void usage(string s)
{
  cerr << "usage: sudoku solve(yes|no) output-type(screen|convert) - puzzle on stdin\n";
  if (s != "") cerr << s << endl;
  exit(0);
}
  
main(int argc, char **argv)
{
  string solve, output;
  Sudoku *sud;

  if (argc != 3) usage("");
  solve = argv[1];
  output = argv[2];
  if (solve != "yes" && solve != "no") usage("bad solve");
  if (output != "screen" && output != "convert") usage("bad output");

  sud = new Sudoku;
  if (solve == "yes") {
    if (!sud->Solve()) {
      printf("Cannot solve puzzle\n");
      exit(0);
    }
  }

  if (output == "screen") {
    sud->Print_Screen();
  } else {
    sud->Print_Convert();
  }
  exit(0);
}
      
  
