// roster_01.cpp
// CS302
// James S. Plank
// EECS Department, University of Tennessee
// August, 2009
// Last Modification: February, 2011
//
#include "roster_01.h"

void Roster::Add_name(string name)
{
  names.push_back(name);
}

void Roster::Print()
{
  int i;

  for (i = 0; i < names.size(); i++) cout << names[i] << endl;
}
