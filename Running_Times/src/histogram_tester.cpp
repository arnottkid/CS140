#include "histogram.hpp"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void print_commands()
{
  cout << "usage: histo_tester prompt(- for empty) -- commands on stdin." << endl;
  cout << endl;
  cout << "commands:" << endl;
  cout << "  SET_BIN bin_size       - Call Set_Bin(bin_size)." << endl;
  cout << "  ADD_VALUES v1 v2 ...   - Call Add_Value(v) for each vi." << endl;
  cout << "  PRINT                  - Get Get_Data() and print." << endl;
  cout << "" << endl;
  cout << "  CLEAR                  - Calls the Clear() method." << endl;
  cout << "  DESTROY                - Call the destructor and remake an empty histogram." << endl;
  cout << "  PRINT_COPY             - Print a copy, thus testing the copy constructor." << endl;
  cout << "  ASSIGN                 - Use the assignment overload to make a copy." << endl;
  cout << "" << endl;
  cout << "  QUIT                   - Quit." << endl;
  cout << "  ?                      - Print commands." << endl;
}

void Print(const Histogram &h)
{
  size_t i;
  vector <int> ids, elts;

  if (!h.Get_Data(ids, elts)) {
    printf("Can't print.\n");
    return;
  }

  for (i = 0; i < ids.size(); i++) {
    printf("%8g %8d\n", (double) ids[i] * h.Get_Bin_Size(), elts[i]);
  }
}

void Print_Copy(Histogram h)
{
  Print(h);
}

int main(int argc, char **argv)
{
  string s, line;
  vector <string> sv;
  istringstream ss;
  string prompt;
  double v;
  Histogram *h1, *h2, *tmp;
  size_t i;

  if (argc != 2) { print_commands(); return 1; }
  prompt = argv[1];

  h1 = new Histogram;
  h2 = new Histogram;

  while (1) {
 
    /* Print a prompt, and read in a line. */

    if (prompt != "-") {
      cout << prompt << " ";
      cout.flush();
    }
    if (!getline(cin, line)) return 0;

    /* Use a stringstream to turn the line into a vector of words. */

    sv.clear();
    ss.clear();
    ss.str(line);
    while (ss >> s) sv.push_back(s);

    /* Ignore blank lines and lines that start with the pound sign. */

    if (sv.size() == 0 || sv[0][0] == '#') {

    } else if (sv[0] == "SET_BIN") {
      if (sv.size() != 2 || sscanf(sv[1].c_str(), "%lf", &v) == 0) {
        cout << "usage: SET_BIN double" << endl;
      } else if (!h1->Set_Bin_Size(v)) printf("Failed.\n");

    } else if (sv[0] == "GET_BIN") {
      printf("%lf\n", h1->Get_Bin_Size());

    } else if (sv[0] == "PRINT") {
      Print(*h1);

    } else if (sv[0] == "PRINT_COPY") {
      Print_Copy(*h1);

    } else if (sv[0] == "CLEAR") {
      h1->Clear();

    } else if (sv[0] == "DESTROY") {
      delete h1;
      h1 = new Histogram;

    } else if (sv[0] == "ASSIGN") {
      *h2 = *h1;
      tmp = h2;
      h2 = h1;
      h1 = tmp;

    } else if (sv[0] == "ADD_VALUES") {
      for (i = 1; i < sv.size(); i++) {
        if (sscanf(sv[i].c_str(), "%lf", &v) != 1) {
          printf("Bad value %s\n", sv[i].c_str());
        } else if (!h1->Add_Value(v)) {
          printf("Add_Value returned false for %s\n", sv[i].c_str());
        }
      }

    } else if (sv[0] == "QUIT") {
      return 0;
    } else if (sv[0] == "?") {
      print_commands();
    } else {
      printf("Unknown command %s\n", sv[0].c_str());
    }
  }
}
