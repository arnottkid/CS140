#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

typedef vector <class Tournament *> TVec;

class Golfer {
  public:
    string name;
    TVec tournaments;
    void Print();
};

typedef vector <Golfer *> GVec;

class Tournament {
  public:
    GVec golfers;
    string name;
    void Print();
};

class Golf_Info {
  public:
    Golf_Info(int ghash_size, int thash_size);

    Golfer *GFind(string &n);
    void GInsert(Golfer *g);

    Tournament *TFind(string &n);
    void TInsert(Tournament *g);

    void Add_Tournament(string fn);
    vector <Golfer *> All();
  protected:
    vector <GVec> GHash;
    vector <Golfer *> Golfers;
    vector <TVec> THash;
    vector <Tournament *> Tournaments;
};
