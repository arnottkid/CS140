/* This is a simple command-line player of the towers of Hanoi */

#include "towers.hpp"
#include <iostream>
using namespace std;

int main()
{
  Towers *t;
  int npieces;
  int from, to;
  string rv;

  /* Get the number of disks and create the instance of the Towers class. */

  cout << "Enter the number of disks: ";
  cout.flush();
  if (!(cin >> npieces)) return 0;

  try {
    t = new Towers(npieces);
  } catch (const string s) {
    cout << s << endl;
    return 0;
  }

  /* Print the board, prompt the user, and make the move. */
    
  while (1) {
    t->Print();
    cout << "Enter source and destination: ";
    cout.flush();
    if (!(cin >> from >> to)) return 0;
    rv = t->Move(from, to, false);
    if (rv != "") cout << endl << rv << endl << endl;
  }
}
