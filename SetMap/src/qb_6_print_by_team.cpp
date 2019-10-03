/* We implement Print_By_Team() using a two-level map, whose vals are multimaps. */

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

class QBS {
  public:
    bool Read(const string &filename);
    const Quarterback *Find(const string &name) const;
    void Print_By_Rating() const;
    void Print_By_Name() const;
    void Print_By_Team() const;
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

  for (i = 0; i < QV.size(); i++) {
    q = QV[i];
    QM[q->Name] = q;
  }

  /* Close the file and return success. */
  f.close();
  return true;
}

/* The find() simply calls find() on the map, returning NULL if it can't find the quarterback. */

const Quarterback *QBS::Find(const string &name) const
{
  map <string, Quarterback *>::const_iterator qit;

  qit = QM.find(name);
  if (qit == QM.end()) return NULL;
  return qit->second;
}

void QBS::Print_By_Rating() const
{
  Quarterback *q;
  size_t i;
  multimap <double, Quarterback *> m;
  multimap <double, Quarterback *>::const_iterator mit;

  for (i = 0; i < QV.size(); i++) {
    q = QV[i];
    m.insert(make_pair(q->Rating, q));
  }

  for (mit = m.begin(); mit != m.end(); mit++) {
    mit->second->Print();
  }
}

void QBS::Print_By_Name() const
{
  map <string, map <string, Quarterback *> > m;
  map <string, map <string, Quarterback *> >::const_iterator mit;
  map <string, Quarterback *>::const_iterator qit;
  size_t i;
  Quarterback *q;

  /* Traverse the vector, and insert the quarterbacks into the map.
     As you can see, I'm using the associative array feature to do this rather easily. */

  for (i = 0; i < QV.size(); i++) {
    q = QV[i];
    m[q->Lastname][q->Firstname] = q;
  }

  /* Now do a nested traversal, and print out the quarterbacks. */

  for (mit = m.begin(); mit != m.end(); mit++) {
    for (qit = mit->second.begin(); qit != mit->second.end(); qit++) {
      qit->second->Print();
    }
  }
}

void QBS::Print_By_Team() const
{
  map <string, multimap <int, Quarterback *> > m;
  map <string, multimap <int, Quarterback *> >::const_iterator mit;
  const multimap <int, Quarterback *> *tmp;
  multimap <int, Quarterback *>::const_iterator qit;
  size_t i;
  Quarterback *q;

  /* Traverse the vector, and insert all of the Quarterbacks into the map. */

  for (i = 0; i < QV.size(); i++) {
    q = QV[i];
    m[q->Team].insert(make_pair(-q->Yards, q));
  }

  /* Again we have a double-nested loop to print the map -- I'm using a
     temporary variable this time, which is a pointer, so that it doesn't make a copy. */
  
  for (mit = m.begin(); mit != m.end(); mit++) {
    tmp = &mit->second;
    for (qit = tmp->begin(); qit != tmp->end(); qit++) {
      qit->second->Print();
    }
  }
}

void print_commands()
{
  cout << "F name -- Find the quarterback with the given name." << endl;
  cout << "R      -- Print the quarterbacks by rating." << endl;
  cout << "N      -- Print the quarterbacks by name (last, first)." << endl;
  cout << "T      -- Print the quarterbacks by team, then by yardage." << endl;
  cout << "Q      -- Quit." << endl;
  cout << "?      -- Print the commands." << endl;
}

int main(int argc, char **argv)
{
  string line, word, name, filename;
  string prompt;
  istringstream ss;
  vector <string> sv;

  QBS qbs;
  const Quarterback *q;

  /* Error check the command line and read the quarterbacks. */

  try {
    if (argc != 2 && argc != 3) throw((string) "usage: qb_4_sort_by_rating file [prompt]");
    filename = argv[1];
    if (!qbs.Read(filename)) throw((string) ("could not open " + filename));
    if (argc ==3) {
      prompt = argv[2];
      prompt += " ";
    }
  } catch (const string s) {
    cerr << s << endl;
    return 0;
  }

  /* Now process standard input.  This code should be pretty familiar to you by now. */

  while (1) {
    if (prompt != "") {
      cout << prompt;
      cout.flush();
    }
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
    } else if (sv[0] == "R") {
      qbs.Print_By_Rating();
    } else if (sv[0] == "N") {
      qbs.Print_By_Name();
    } else if (sv[0] == "T") {
      qbs.Print_By_Team();
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
