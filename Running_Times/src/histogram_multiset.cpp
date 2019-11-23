#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include "histogram.hpp"
using namespace std;

/* Now, we're using a multiset.  Add_Values simply inserts the bin.
   Get_Data traverses the multiset, and counts up the number of bins. */

class Histo_Multiset {
  public:
    multiset <int> Bins;
    double Bin_Size;
};

/* As with the map version, pretty much everything is identical to Histo_Vector.
   The only changes are to Add_Values() and Get_Data(). */

Histogram::Histogram()
{
  Histo_Multiset *hv;

  hv = new Histo_Multiset;
  hv->Bin_Size = -1;

  state = (void *) hv;
}

Histogram::~Histogram()
{
  Histo_Multiset *hv;

  hv = (Histo_Multiset *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_Multiset *hv;

  hv = new Histo_Multiset;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Multiset *hv_original, *hv_copy;

  hv_original = (Histo_Multiset *) h.state;
  hv_copy = (Histo_Multiset *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_Multiset *hv;

  hv = (Histo_Multiset *) state;
  hv->Bins.clear();
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Multiset *hv;

  hv = (Histo_Multiset *) state;
  if (hv->Bins.size() != 0) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_Multiset *hv;

  hv = (Histo_Multiset *) state;
  return hv->Bin_Size;
}

/* Simply insert the bin into the multiset. */

bool Histogram::Add_Value(double d)
{
  Histo_Multiset *hv;
  int bin;

  hv = (Histo_Multiset *) state;

  if (d < 0) return false;                   
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);
  hv->Bins.insert(bin);
  return true;
}

/* Get data now requires a little work -- you need to traverse the multiset
   and calculate the number of elements in each bin */

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_Multiset *hv;
  multiset <int>::iterator bit;
  int lastbin, index;

  hv = (Histo_Multiset *) state;
  if (hv->Bin_Size < 0) return false;

  bin_ids.clear();
  num_elts.clear();
  lastbin = -1;
  index = -1;

  for (bit = hv->Bins.begin(); bit != hv->Bins.end(); bit++) {

    /* If we haven't seen this bin before, add it to bin_ids and num_elts */

    if (*bit != lastbin) {
      bin_ids.push_back(*bit);
      num_elts.push_back(0);
      index++;
      lastbin = *bit;
    }
    
    /* Index is pointing to the correct entry in the vector -- add one to num_elts. */

    num_elts[index]++;
  }

  return true;
};
