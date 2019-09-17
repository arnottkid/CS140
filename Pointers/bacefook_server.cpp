#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// This is our main data structure -- the Person.

class Person {
  public:
    string Name;
    string Mood;
    Person *InRelationship;
    vector <Person *> Friends;
};

// Here we copy the "djb_hash" function from the hashing lecture notes.

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

// This is our one and only hash table function.  It finds a person with the 
// given name in the hash table.  If the person is found, then it returns a 
// pointer to the person.  Otherwise, if "add" is true, it creates the person 
// and adds it to the hash table.  If "add" is false, then it simpy returns NULL.

typedef vector <Person *> PVec;

Person *find_person(string &name, vector <PVec> &HT, int add)
{
  int h;
  int i;
  Person *p;

  h = djb_hash(name) % HT.size();
  for (i = 0; i < HT[h].size(); i++) {
    if (HT[h][i]->Name == name) return HT[h][i];
  }
  if (add) {
    p = new Person;
    p->Name = name;
    p->Mood = "Neutral";
    p->InRelationship = NULL;
    HT[h].push_back(p);
    return p;
  } else {   
    return NULL;
  }
}

main(int argc, char **argv)
{
  istringstream iss;         // For processing argv[1]
  string n1, n2, mood;       // For reading in names and moods
  Person *p, *p2;            // Pointers to people, that we manipulate or print.

  int Table_Size;            // The table size is read from the command line.
  vector <PVec> Hash_Table;  // The hash table.  
                             // Entries are vectors because we use separate chaining

  int i;                     // Temporary variable
  string s;                  // Temporary variable

  // --------------------------------------------------
  // Process the command line and create the hash table.

  if (argc != 2) {
    cerr << "usage: bacefook_server table-size\n";
    exit(1);
  }

  iss.clear();
  iss.str(argv[1]);
  if (!(iss >> Table_Size) || Table_Size <= 0) {
    cerr << "usage: bacefook_server table-size\n";
    cerr << "bad table-size\n";
    exit(1);
  }
 
  Hash_Table.resize(Table_Size);

  // --------------------------------------------------
  // Process the input from standard input.

  while (getline(cin, s)) {

    // --------------------------------------------------------
    // NEW-PERSON.  If the person is already in the hash table,
    // then it is an error.  

    if (s == "NEW-PERSON") {
      if (!getline(cin, n1)) exit(1);
      p = find_person(n1, Hash_Table, 0);
      if (p != NULL) {
        printf("UNSUCCESSFUL\n");
      } else {
        p = find_person(n1, Hash_Table, 1);
        printf("SUCCESSFUL\n");
      }

    // --------------------------------------------------------
    // MOOD.  Find the name and set the mood.

    } else if (s == "MOOD") {
      if (!getline(cin, n1)) exit(1);
      if (!getline(cin, mood)) exit(1);
      p = find_person(n1, Hash_Table, 0);
      if (p == NULL) {
        printf("UNSUCCESSFUL\n");
      } else {
        p->Mood = mood;
        printf("SUCCESSFUL\n");
      }

    // ---------------------------------------------------------------
    // IN-RELATIONSHIP.  Now, you have to successfully find both
    // names.  Note how we set the pointer of p->InRelationship to p2.

    } else if (s == "IN-RELATIONSHIP") {
      if (!getline(cin, n1)) exit(1);
      if (!getline(cin, n2)) exit(1);
      p = find_person(n1, Hash_Table, 0);
      p2 = find_person(n2, Hash_Table, 0);
      if (p == NULL || p2 == NULL) {
        printf("UNSUCCESSFUL\n");
      } else {
        p->InRelationship = p2;
        printf("SUCCESSFUL\n");
      }

    // ---------------------------------------------------------------
    // ADD-FRIEND.  This is pretty much identical to IN-RELATIONSHIP,
    // except you are adding p2 to the Friends vector, rather than just
    // setting a pointer.

    } else if (s == "ADD-FRIEND") {
      if (!getline(cin, n1)) exit(1);
      if (!getline(cin, n2)) exit(1);
      p = find_person(n1, Hash_Table, 0);
      p2 = find_person(n2, Hash_Table, 0);
      if (p == NULL || p2 == NULL) {
        printf("UNSUCCESSFUL\n");
      } else {
        p->Friends.push_back(p2);
        printf("SUCCESSFUL\n");
      }

    // ---------------------------------------------------------------
    // QUERY.  This uses the InRelationship and Friend[] pointers to print
    // those names and moods.

    } else if (s == "QUERY") {
      if (!getline(cin, n1)) exit(1);
      p = find_person(n1, Hash_Table, 0);
      if (p == NULL) {
        printf("UNSUCCESSFUL\n");
      } else {
        printf("SUCCESSFUL\n");
        printf("NAME %s\n", p->Name.c_str());
        printf("MOOD %s\n", p->Mood.c_str());
        if (p->InRelationship != NULL) {
          printf("IN-RELATIONSHIP %s : %s\n", p->InRelationship->Name.c_str(),
                    p->InRelationship->Mood.c_str());
        }
        for (i = 0; i < p->Friends.size(); i++) {
          printf("FRIEND %s : %s\n", p->Friends[i]->Name.c_str(),
                    p->Friends[i]->Mood.c_str());
        }
        printf("END\n");
      }

    // Error check bad input.

    } else if (s != "") {
      printf("Bad Command %s\n", s.c_str());
    }

  }
  exit(0);
}
