// roster_05_bad_2.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include "roster_05.h"

Roster::Roster(int starting_number)
{
  start = starting_number;
}

void Roster::Add_name(string name)
{
  names.push_back(name);
}

void Roster::Print(int columns, int print_names)
{
  int i;
  int rn;
  vector <int> random, inrandom;

  inrandom.resize(names.size(), 0);
  for (i = 0; i < names.size(); i++) {
    do {
      rn = lrand48()%names.size(); 
    } while (inrandom[rn]);
    random.push_back(rn);
  }

  cout << "<table border=2>\n";

  for (i = 0; i < names.size(); i++) {

    if (i%columns == 0) cout << "<tr>\n";   

    rn = random[i];
    cout << "<td>";
    printf("<IMG src=Pictures/%06d.jpg height=100>", rn+start);
    if (print_names) cout << "<br>" << names[rn];
    cout << "</td>" << endl;

    if (i%columns == columns-1) cout << "</tr>\n";
  }

  if (i%columns != 0) cout << "</tr>\n";   
  cout << "</table>\n";
}
