// roster_03.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include "roster_03.h"

Roster::Roster(int starting_number)
{
  start = starting_number;
}

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
    printf("<td>");
    printf("Filename: Pictures/%06d.jpg, %s", i+start, names[i].c_str());
    printf("</td>\n");
    if (i % columns == columns-1) cout << "</tr>\n";   // End the row when i%columns == columns -1
  }

  if (i%columns != 0) cout << "</tr>\n";               // If the last row is incomplete, end it.
  cout << "</table>\n";
}
