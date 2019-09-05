/* Roster_03.cpp implements the class methods defined in roster_03.hpp. 

   The change from roster_02.cpp is that there is a constructor now, which takes
   as an argument the number of columns.  That is stored in the class now, and
   Print() uses it to define the number of columns. */

#include "roster_03.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* The constructor is called when the roster is created, and it must be passed
   an integer parameter which is the number of columns. */

Roster::Roster(int columns)
{
  if (columns <= 0) throw((string) "Bad number of columns");
  Columns = columns;
}

/* Add_Line() is unchanged from roster_01.cpp */

bool Roster::Add_Line(const std::string &line)
{
  istringstream ss;
  string s;
  string name, photo;
  bool reading_name;

  ss.str(line);

  reading_name = true;
  while (ss >> s) {
    if (reading_name && s == "XX") {
      reading_name = false;
    } else if (reading_name) {
      if (name.size() > 0) name.push_back(' ');
      name += s;
    } else {
      if (photo.size() > 0) photo.push_back(' ');
      photo += s;
    }
  }

  if (reading_name || name.size() == 0 || photo.size() == 0) return false;
  Names.push_back(name);
  Photos.push_back(photo);
  return true;
}

/* Print() now prints an HTML table with just the name.
   The number of columns in the table is a parameter of Print */

void Roster::Print() const
{
  size_t i;

  /* See roster_02.cpp for comments on how this works. */

  cout << "<table border=2>" << endl;

  for (i = 0; i < Names.size(); i++) {
    if (i % Columns == 0) cout << "<tr>" << endl;
    cout << "<td>" << Names[i] << "</td>" << endl;
    if (i % Columns == Columns-1) cout << "</tr>" << endl;
  }

  if (i % Columns != 0) cout << "</tr>" << endl;
  cout << "</table>" << endl;
}
