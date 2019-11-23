#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include "histogram.hpp"
using namespace std;

/* This is my internal definition of a map version of the histogram class. */

class Histo_Map {
  public:
    map <int, int> Elts;
    double Bin_Size;
};

/* The constructor / destructor, etc are all the same as for the vector, except they 
   use the Histo_Map class rather than Histo_Vector. */

Histogram::Histogram()
{
  Histo_Map *hv;

  hv = new Histo_Map;
  hv->Bin_Size = -1;

  state = (void *) hv;
}

Histogram::~Histogram()
{
  Histo_Map *hv;

  hv = (Histo_Map *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_Map *hv;

  hv = new Histo_Map;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Map *hv_original, *hv_copy;

  hv_original = (Histo_Map *) h.state;
  hv_copy = (Histo_Map *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_Map *hv;

  hv = (Histo_Map *) state;
  hv->Elts.clear();
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Map *hv;

  hv = (Histo_Map *) state;
  if (hv->Elts.size() != 0) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_Map *hv;

  hv = (Histo_Map *) state;
  return hv->Bin_Size;
}

bool Histogram::Add_Value(double d)
{
  Histo_Map *hv;
  int bin;

  hv = (Histo_Map *) state;

  if (d < 0) return false;
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);
  hv->Elts[bin]++;
  return true;
}

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  map <int, int>::const_iterator eit;
  Histo_Map *hv;

  hv = (Histo_Map *) state;
  if (hv->Bin_Size < 0) return false;

  bin_ids.clear();
  num_elts.clear();

  for (eit = hv->Elts.begin(); eit != hv->Elts.end(); eit++) {
    bin_ids.push_back(eit->first);
    num_elts.push_back(eit->second);
  }
  return true;
};
