/* This version of the program defines a QBS class, and implements the "Find"
   functionality.  It also turns the main() into one that processes command lines. */

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

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

/* The QBS class is to manage my quarterback data.  I use a default
   constructor, and then implement methods to read from a filename,
   and to find a Quarterback by name.  In the protected data, I have
   two data structures: QV, which is a vector of pointers, and QM,
   which is a map of quarterbacks keyed by name. */

class QBS {
  public:
    bool Read(const string &filename);
    const Quarterback *Find(const string &name) const;
  protected:
    vector <Quarterback *> QV;
    map <string, Quarterback *> QM;
};

/* The code to read the quarterback is lifted from the previous main().
   When it is done reading the quarterbacks into the vector QV, it creates
   the map QM. */

bool QBS::Read(const string &filename)
{
  ifstream f;
  string fn, ln, team;
  int yards;
  double rating;
  Quarterback *q;
  size_t i;

  f.open(filename.c_str());
  if (f.fail()) return false;

  /* Read in the quarterbacks from the file, putting the pointers into the QV vector. */

  while(f >> fn >> ln >> team >> yards >> rating) {
    q = new Quarterback;
    q->Firstname = fn;
    q->Lastname = ln;
    q->Team = team;
    q->Yards = yards;
    q->Rating = rating;
    q->Name = q->Firstname + " " + q->Lastname;
    QV.push_back(q);
  }

  /* Now create the map QM, treating it like an associative array. */

  /* Close the file and return success. */
}

/* Write this. */

const Quarterback *QBS::Find(const string &name) const
{
}

void print_commands()
{
  cout << "F name -- Find the quarterback with the given name." << endl;
  cout << "Q      -- Quit." << endl;
  cout << "?      -- Print the commands." << endl;
}

int main(int argc, char **argv)
{
  string line, word, name, filename;
  istringstream ss;
  vector <string> sv;

  QBS qbs;
  const Quarterback *q;

  /* Error check the command line and read the quarterbacks. */

  try {
    if (argc != 2) throw((string) "usage: qb_2_qbs_class file");
    filename = argv[1];
    if (!qbs.Read(filename)) throw((string) ("could not open " + filename));
  } catch (const string s) {
    cerr << s << endl;
    return 0;
  }

  /* Now process standard input.  This code should be pretty familiar to you by now. */

  while (1) {
    cout << "QB> ";
    cout.flush();
    if (!getline(cin, line)) return 0;
    sv.clear();
    ss.clear();
    ss.str(line);
    while (ss >> word) sv.push_back(word);

    if (sv.size() == 0 || sv[0][0] == '#') {
      // Skip
    } else if (sv[0] == "Q") {
      return 0;
    } else if (sv[0] == "?") {
      print_commands();
    } else if (sv[0] == "F") {
      if (sv.size() != 3) {
        printf("usage: F firstname lastname\n");
      } else {
        name = sv[1] + " " + sv[2];
        q = qbs.Find(name);
        if (q == NULL) {
          printf("Not there.\n");
        } else {
          q->Print();
        }
      }
    }
  }
}
