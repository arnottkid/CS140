#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "golf.h"
using namespace std;

void Golfer::Print()
{
  int i;
  
  printf("Golfer: %s\n", name.c_str());
  for (i = 0; i < tournaments.size(); i++) printf("  %s\n", tournaments[i]->name.c_str());
  printf("\n");
}
  
void Tournament::Print()
{
  int i;
  
  printf("Tournament: %s\n", name.c_str());
  for (i = 0; i < golfers.size() && i < 10; i++) {
    printf("%3d %s\n", i, golfers[i]->name.c_str());
  }
  printf("\n");
}
  
bool golfer_comp(Golfer *g1, Golfer *g2)
{
  if (g1->name < g2->name) return 1;
  return 0;
}

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

string golfer_name(vector <string> &w)
{
  int i, j;
  string n;

  n = "";
  for (i =  0; i < w.size(); i++) {
    if (w[i][0] == '[') {
      j = w[i].find(']');
      if (j == string::npos) return "";
      n = w[i].substr(j+1);
    } else if (n.size() > 0) {
      if (w[i] == "E" || !isalpha(w[i][0])) return n;
      n += " ";
      n += w[i];
    }
  }
  return "";
}

int is_golfer(vector <string> &w)
{
  int i;
  for (i =  0; i < w.size(); i++) {
    if (w[i] == "F" || w[i] == "F*") return 1;
    if (w[i] == "--" && i < w.size()-1 && w[i+1] == "--") return 1;
  }
  return 0;
}

vector <string> break_up(string &s)
{
  string s2;
  vector <string> rv;
  istringstream ss;

  ss.str(s);
  while (ss >> s2) rv.push_back(s2);
  return rv;
}

Golf_Info::Golf_Info(int gs, int ts)
{
  GHash.resize(gs);
  THash.resize(ts);
}

Golfer *Golf_Info::GFind(string &n)
{
  int h;
  int i;
  Golfer *g;

  h = djb_hash(n) % GHash.size();
  for (i = 0; i < GHash[h].size(); i++) {
    g = GHash[h][i];
    if (g->name == n) return g;
  }
  return NULL;
}

void Golf_Info::GInsert(Golfer *g) 
{
  int h;

  h = djb_hash(g->name) % GHash.size();
  GHash[h].push_back(g);
}

Tournament *Golf_Info::TFind(string &n)
{
  int h;
  int i;
  Tournament *g;

  h = djb_hash(n) % THash.size();
  for (i = 0; i < THash[h].size(); i++) {
    g = THash[h][i];
    if (g->name == n) return g;
  }
  return NULL;
}

void Golf_Info::TInsert(Tournament *g) 
{
  int h;

  h = djb_hash(g->name) % THash.size();
  THash[h].push_back(g);
}

void Golf_Info::Add_Tournament(string fn)
{
  int i, c;
  ifstream fin;
  vector <string> words;
  string s, tn;
  Golfer *g;
  Tournament *t;

  fin.open(fn.c_str());
  if (fin.fail()) { perror(fn.c_str()); exit(1); }
 
  if (!getline(fin, s)) { cerr << "bad file\n"; exit(1); }
  words = break_up(s);
  if (words.size() == 0) { cerr << "bad file\n"; exit(1); }
  s = words[0];
  for (i = 1; i < words.size(); i++) { s += (" " + words[i]); }
  t = new Tournament;
  t->name = s;
  TInsert(t);
  Tournaments.push_back(t);
 
  while (getline(fin, s)) {
    words = break_up(s);
    if (is_golfer(words)) {
      s = golfer_name(words);
      g = GFind(s);
      if (g == NULL) {
        g = new Golfer;
        g->name = s;
        GInsert(g);
        Golfers.push_back(g);
      }
      t->golfers.push_back(g);
      g->tournaments.push_back(t);
    }
  }
  fin.close(); 
}

vector <Golfer *> Golf_Info::All()
{
  return Golfers;
}

int main(int argc, char **argv)
{
  int i;
  Golf_Info gi(1000, 1000);
  string s;
  string n;
  Golfer *g;
  Tournament *t;
  istringstream ss;
  vector <Golfer *> gvec;

  for (i = 1; i < argc; i++) {
    gi.Add_Tournament(argv[i]);
  }

  cout << "Golf> ";
  while(getline(cin, s)) {
    ss.clear();
    ss.str(s);
    if (ss >> s) {
      if (s == "ALL") {
        gvec = gi.All();
        sort(gvec.begin(), gvec.end(), golfer_comp);
        for (i = 0; i < gvec.size(); i++) cout << gvec[i]->name << endl;
        gvec.clear();
      } else if (s == "G") {
        n = "";
        while (ss >> s) if (n == "") n = s; else n += (" " + s);
        g = gi.GFind(n);
        if (g == NULL) {
          cout << n << " not found.\n";
        } else {
          g->Print();
        }
      } else if (s == "T") {
        n = "";
        while (ss >> s) if (n == "") n = s; else n += (" " + s);
        t = gi.TFind(n);
        if (g == NULL) {
          cout << n << " not found.\n";
        } else {
          t->Print();
        }
      }
    }
    cout << "Golf> ";
  }
}
