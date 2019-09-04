// roster_02.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include "roster_02.h"

void Roster::Add_name(string name)
{
  names.push_back(name);
}

void Roster::Print(int columns)
{
  int i;

  cout << "<table border=2>\n";

  for (i = 0; i < names.size(); i++) {
    if (i % columns == 0) cout << "<tr>\n";            // Start a new row when i%columns == 0
    printf("<td>%s</td>\n", names[i].c_str());
    if (i % columns == columns-1) cout << "</tr>\n";   // End the row when i%columns == columns -1
  }

  if (i%columns != 0) cout << "</tr>\n";               // If the last row is incomplete, end it.
  cout << "</table>\n";
}
