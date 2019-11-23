#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include "histogram.hpp"
using namespace std;

/* We're going to use a list which holds two integers -- bin and val.  And we'll keep
   it sorted.  This is not a good implementation, because of the linear running time
   of <b>Add_Value()</b>. */

class Histo_List {
  public:
    list < pair<int, int> > Bin_Elt;
    double Bin_Size;
};

/* As with the map version, pretty much everything is identical to Histo_Vector.
   The only changes are to Add_Values() and Get_Data(). */

Histogram::Histogram()
{
  Histo_List *hv;

  hv = new Histo_List;
  hv->Bin_Size = -1;

  state = (void *) hv;
}

Histogram::~Histogram()
{
  Histo_List *hv;

  hv = (Histo_List *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_List *hv;

  hv = new Histo_List;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_List *hv_original, *hv_copy;

  hv_original = (Histo_List *) h.state;
  hv_copy = (Histo_List *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_List *hv;

  hv = (Histo_List *) state;
  hv->Bin_Elt.clear();
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_List *hv;

  hv = (Histo_List *) state;
  if (hv->Bin_Elt.size() != 0) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_List *hv;

  hv = (Histo_List *) state;
  return hv->Bin_Size;
}

/* We have to traverse the list to find the bin.  If it's there, add one to the
   val.  If not, insert a new one. */

bool Histogram::Add_Value(double d)
{
  Histo_List *hv;
  int bin;
  list < pair<int, int> >::iterator lit;
  pair <int, int> p;

  hv = (Histo_List *) state;

  if (d < 0) return false;                    // Error check. 
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);

  /* Look for the bin -- stop when you are at the end of the list,
     or if you see a bin that is >= the bin you're looking for. */

  for (lit = hv->Bin_Elt.begin(); lit != hv->Bin_Elt.end() && lit->first < bin; lit++) ;

  /* If it's not there, insert it and return. */

  if (lit == hv->Bin_Elt.end() || lit->first > bin) {
    p.first = bin;
    p.second = 1;
    hv->Bin_Elt.insert(lit, p);
    return true;
  }

  /* Otherwise, it is there, so add one to its val and return .*/

  lit->second++;
  return true;
}

/* Get data is pretty simple -- just copy the vectors. */

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_List *hv;
  list < pair<int, int> >::iterator lit;

  hv = (Histo_List *) state;
  if (hv->Bin_Size < 0) return false;

  bin_ids.clear();
  num_elts.clear();

  for (lit = hv->Bin_Elt.begin(); lit != hv->Bin_Elt.end(); lit++) {
    bin_ids.push_back(lit->first);
    num_elts.push_back(lit->second);
  }

  return true;
};
