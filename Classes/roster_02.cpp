/* Roster_02.cpp implements the class methods defined in roster_02.hpp. 

   The change from roster_01.cpp is that it prints out a HTML table with the specified
   number of columns. */

#include "roster_02.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

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

void Roster::Print(int columns) const
{
  size_t i;

  /* Start the table. */

  cout << "<table border=2>" << endl;

  /* Here's the body of the table -- when i%columns is zero, then print a new row
     before the name, with "<tr>".  When  i%columns is (columns-1), then end the 
     current row, after the name, with "</tr>". */

  for (i = 0; i < Names.size(); i++) {
    if (i % columns == 0) cout << "<tr>" << endl;
    cout << "<td>" << Names[i] << "</td>" << endl;
    if (i % columns == columns-1) cout << "</tr>" << endl;
  }

  /* If the last row is incomplete, end it with a final "</tr>".  Then end the table. */

  if (i % columns != 0) cout << "</tr>" << endl;
  cout << "</table>" << endl;
}
