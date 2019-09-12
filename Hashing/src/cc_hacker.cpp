#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Person {
  public:
    string name;
    string cc;
};

typedef vector <Person> PVec;

unsigned int djb_hash(string &s)
{
  int i;
  unsigned int h;
  
  h = 5381;

  for (i = 0; i < s.size(); i++) {
    h = (h << 5) + h + s[i];
  }
  return h;
}

main(int argc, char **argv)
{
  int ts, i, index, counter, j;
  string s;
  istringstream ss;
  vector <PVec> table;
  Person p;
  ifstream f;

  if (argc != 3) {
    cerr << "usage: cc_hacker table_size file\n";
    exit(1);
  }
 
  ts = atoi(argv[1]);
  f.open(argv[2]);
  if (f.fail()) { perror(argv[2]); exit(1); }
  if (ts <= 0) { cerr << "usage: cc_hacker table_size file\n"; exit(1); }

  table.resize(ts);
 
  counter = 0;
  while (getline(f, s)) {
    counter++;
    ss.clear();
    ss.str(s);
    if (!(ss >> p.cc)) { cerr << "Bad line\n"; exit(1); }
    if (p.cc.size() != 16 || p.cc.find_first_not_of("0123456789") != string::npos) { 
      cerr << "Bad credit card\n"; exit(1); 
    }
    if (!(ss >> p.name)) { cerr << "Bad name\n"; exit(1); }
    while (ss >> s) { p.name += " "; p.name += s; }
    
    index = djb_hash(p.name) % table.size();
    table[index].push_back(p);
  }

  while(1) {
    printf("Enter a name> "); 
    if (!getline(cin, s)) exit(1);
    index = djb_hash(s) % table.size();
    for (i = 0; i < table[index].size(); i++) {
      if (table[index][i].name == s) {
        p = table[index][i];
        printf("Found it: Table entry %d: %s %s\n", index, p.name.c_str(), p.cc.c_str());
        i = table[index].size();
      }
    }
    if (i == table[index].size()) {
      printf("Not found.  Table entry %d\n", index);
    }
  }
}
