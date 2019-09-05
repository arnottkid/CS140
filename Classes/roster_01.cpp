/* Roster_01.cpp implements the class methods defined in roster_01.hpp. 

   You'll note that since roster_01.hpp does not say "using namespace std", we do
   it here, so that we can use strings and vectors without having to say "std::". */

#include "roster_01.hpp"
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

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

void Roster::Print() const
{
  size_t i;

  for (i = 0; i < Names.size(); i++) printf("%-30s %s\n", Names[i].c_str(), Photos[i].c_str());
}

