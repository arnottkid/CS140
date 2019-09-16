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

  /* - Read in each name and credit card, error checking, and create a person p.
     - Hash the name.
     - Insert p into the hash table. 
   */


  /* Process standard input:
       - Get a name.
       - Look it up in the hash table, and print out the name/cc if it's there.
       - If it's not there, print that it's not found, and print the table entry.
   */
     
  return 0;
}
