/* Follow along with the lecture notes for detail on this program.
   This one simply reads QB info into a vector of pointers to QB classes. */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

/* The Quarterback class is quite simple -- data and a Print method. 
   We will construct the Name from the Firstname and Lastname. */

class Quarterback {
  public:
    string Name;
    string Firstname;
    string Lastname;
    string Team;
    int    Yards;
    double Rating;
    void Print() const;
};

void Quarterback::Print() const
{
  printf("%-25s %3s   Y: %4d    R: %5.1lf\n", Name.c_str(), Team.c_str(), Yards, Rating);
} 

/* Right now, the main() is simple -- it simple reads quarterbacks from the 
   file given on the command line.  It creates a new instance of the Quarterback class
   for each Quarterback on standard input, and puts a pointer to that instance into 
   an array called qbs.  At the end, it simply traverses tha array, and prints the
   quarterbacks. */

int main(int argc, char **argv)
{
  string filename;
  ifstream f;
  string fn, ln, team;
  int yards;
  double rating;
  Quarterback *q;
  vector <Quarterback *> qbs;
  size_t i;

  /* Error check the command line. */

  try {
    if (argc != 2) throw((string) "usage: qb_1_read_input file");
    filename = argv[1];
    f.open(filename.c_str());
    if (f.fail()) throw((string) ("could not open " + filename));
  } catch (const string s) {
    cerr << s << endl;
    return 0;
  }

  /* Read the lines, and for each line create a Quarterback an put it into the qbs vector. */

  while(f >> fn >> ln >> team >> yards >> rating) {
    q = new Quarterback;
    q->Firstname = fn;
    q->Lastname = ln;
    q->Team = team;
    q->Yards = yards;
    q->Rating = rating;
    q->Name = q->Firstname + " " + q->Lastname;
    qbs.push_back(q);
  }

  /* Print out the quarterbacks to test the code. */

  for (i = 0; i < qbs.size(); i++) qbs[i]->Print();
  return 0;
}
