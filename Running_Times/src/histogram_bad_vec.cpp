#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include "histogram.hpp"
using namespace std;

/* We're going to use two vectors now -- Bins and Elts, which is like first and second
   in the map version.  Id's will be sorted, so we can use binary search to find
   them.  However, insertion into a vector is O(n), so it will be expensive.  That's
   why I call this "bad". */

class Histo_Bad_Vec {
  public:
    vector <int> Bins;
    vector <int> Elts;
    double Bin_Size;
};

/* As with the map version, pretty much everything is identical to Histo_Vector.
   The only changes are to Add_Values() and Get_Data(). */

Histogram::Histogram()
{
  Histo_Bad_Vec *hv;

  hv = new Histo_Bad_Vec;
  hv->Bin_Size = -1;

  state = (void *) hv;
}

Histogram::~Histogram()
{
  Histo_Bad_Vec *hv;

  hv = (Histo_Bad_Vec *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_Bad_Vec *hv;

  hv = new Histo_Bad_Vec;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Bad_Vec *hv_original, *hv_copy;

  hv_original = (Histo_Bad_Vec *) h.state;
  hv_copy = (Histo_Bad_Vec *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_Bad_Vec *hv;

  hv = (Histo_Bad_Vec *) state;
  hv->Bins.clear();
  hv->Elts.clear();
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Bad_Vec *hv;

  hv = (Histo_Bad_Vec *) state;
  if (hv->Elts.size() != 0) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_Bad_Vec *hv;

  hv = (Histo_Bad_Vec *) state;
  return hv->Bin_Size;
}

bool Histogram::Add_Value(double d)
{
  Histo_Bad_Vec *hv;
  int bin;
  int high, low;
  int index, i;

  hv = (Histo_Bad_Vec *) state;

  if (d < 0) return false;
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);

  /* Do a binary search to find the bin, if it's there. */

  low = 0;
  high = hv->Bins.size();
  high--;
  index = 0;
 
  while (high >= low) {
    index = (low + high)/2;
    if (hv->Bins[index] == bin) {
      hv->Elts[index]++;
      return true;
    } else if (hv->Bins[index] < bin) {
      low = index+1;
    } else {
      high = index-1;
    }
  }

  /* If it's not there, then have index point to the place where
     it should go after we resize the vector. */

  if (index < 0) {
    index = 0;
  } else if (index < (int) hv->Bins.size()) {
    if (hv->Bins[index] < bin) index++;
  }
    
  /* Resize the vectors and move everything over so there's room 
     for the new bin. */

  hv->Bins.push_back(0);
  hv->Elts.push_back(0);
  for (i = hv->Bins.size()-1; i > index; i--) {
    hv->Bins[i] = hv->Bins[i-1];
    hv->Elts[i] = hv->Elts[i-1];
  }

  /* Create the new bin. */

  hv->Bins[index] = bin;
  hv->Elts[index] = 1;
  return true;
}

/* Get data is pretty simple -- just copy the vectors. */

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_Bad_Vec *hv;

  hv = (Histo_Bad_Vec *) state;
  if (hv->Bin_Size < 0) return false;

  bin_ids = hv->Bins;
  num_elts = hv->Elts;
  return true;
};
