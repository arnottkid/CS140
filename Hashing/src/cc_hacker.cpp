#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* A person is composed of a name and a credit card number. */

class Person {
  public:
    string name;
    string cc;
};

/* This is our djb hash function, copied from the lecture notes. */

unsigned int djb_hash(const string &s)
{
  size_t i;
  unsigned int h;
  
  h = 5381;

  for (i = 0; i < s.size(); i++) {
    h = (h << 5) + h + s[i];
  }
  return h;
}

int main(int argc, char **argv)
{
  vector < vector <Person> > table;     // The hash table
  size_t table_size;                    // The table's size

  size_t i, index;                      // Helpers
  string s;
  istringstream ss;
  Person p;
  ifstream f;

  /* Process the command line. */

  try {
    if (argc != 3) throw ((string) "usage: cc_hacker table_size file");
 
    ss.clear();
    ss.str(argv[1]);
    if (!(ss >> table_size || table_size == 0)) throw((string) "Bad table size"); 

     f.open(argv[2]);
     if (f.fail()) throw ((string) "couldn't open the file.");
   } catch (string s) {
     cerr << s << endl;
     exit(1);
   }

  table.resize(table_size);
 
  /* - Read in each name and credit card, error checking, and create a person p.
     - Hash the name.
     - Insert p into the hash table. 
   */

  while (getline(f, s)) {
    ss.clear();
    ss.str(s);
    if (!(ss >> p.cc)) { cerr << "Bad line\n"; exit(1); }
    if (p.cc.size() != 16 || p.cc.find_first_not_of("0123456789") != string::npos) { 
      cerr << "Bad credit card\n"; 
      return 1;
    }
    if (!(ss >> p.name)) { cerr << "Bad name\n"; exit(1); }
    while (ss >> s) { p.name += " "; p.name += s; }
    
    index = djb_hash(p.name) % table.size();
    table[index].push_back(p);
  }

  /* Process standard input:
       - Get a name.
       - Look it up in the hash table, and print out the name/cc if it's there.
       - If it's not there, print that it's not found, and print the index into the table.
   */
     
  while(1) {
    printf("Enter a name> "); 
    if (!getline(cin, s)) exit(1);
    index = djb_hash(s) % table.size();
    for (i = 0; i < table[index].size(); i++) {
      if (table[index][i].name == s) {
        p = table[index][i];
        printf("Found it: Table entry %lu: %s %s\n", index, p.name.c_str(), p.cc.c_str());
        i = table[index].size();
      }
    }
    if (i == table[index].size()) {
      printf("Not found.  Table entry %lu\n", index);
    }
  }
  return 0;
}
