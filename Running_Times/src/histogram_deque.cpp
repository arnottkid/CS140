#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include "histogram.hpp"
using namespace std;

/* We're going to use a deque now, where index 0 if Elts corresponds to Min_Bin.
   That way, you don't have to store any elements lower than
   the minimum value. */

class Histo_Deque {
  public:
    deque <int> Elts;
    int Min_Bin;
    double Bin_Size;
};

/* As with the map version, pretty much everything is identical to Histo_Vector.
   The only changes are to Add_Values() and Get_Data(). */

Histogram::Histogram()
{
  Histo_Deque *hv;

  hv = new Histo_Deque;
  hv->Bin_Size = -1;
  hv->Min_Bin = -1;

  state = (void *) hv;
}

Histogram::~Histogram()
{
  Histo_Deque *hv;

  hv = (Histo_Deque *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_Deque *hv;

  hv = new Histo_Deque;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Deque *hv_original, *hv_copy;

  hv_original = (Histo_Deque *) h.state;
  hv_copy = (Histo_Deque *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_Deque *hv;

  hv = (Histo_Deque *) state;
  hv->Elts.clear();
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Deque *hv;

  hv = (Histo_Deque *) state;
  if (hv->Elts.size() != 0) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_Deque *hv;

  hv = (Histo_Deque *) state;
  return hv->Bin_Size;
}

bool Histogram::Add_Value(double d)
{
  Histo_Deque *hv;
  int bin;
  int index, count;

  hv = (Histo_Deque *) state;

  if (d < 0) return false;
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);

  /* If this is the first value, set Min_Bin and
     add the element to index 0.  */

  if (hv->Elts.size() == 0) {
    hv->Min_Bin = bin;
    hv->Elts.push_back(1);
    return true;
  }

  /* If we need to add elements to the beginning,
     do it here, set the element to 1 and return. */

  if (bin < hv->Min_Bin) {
    count = hv->Min_Bin - bin;
    hv->Min_Bin = bin;
    hv->Elts.insert(hv->Elts.begin(), count, 0);
    hv->Elts[0] = 1;
    return true;
  }

  /* If we need to add elements to the end, 
     do it here, set the element to 1 and return. */

  index = bin - hv->Min_Bin;
  if (index >= (int) hv->Elts.size()) {
    hv->Elts.resize(index+1, 0);
    hv->Elts[index] = 1;
    return true;
  }

  hv->Elts[index]++;
  return true;
}

/* Get data now looks a little like the vector version, but the
   ids start at Min_Bin */

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_Deque *hv;
  int i;

  hv = (Histo_Deque *) state;
  if (hv->Bin_Size < 0) return false;
  
  bin_ids.clear();
  num_elts.clear();

  for (i = 0; i < (int) hv->Elts.size(); i++) {
    if (hv->Elts[i] > 0) {
      bin_ids.push_back(hv->Min_Bin+i);
      num_elts.push_back(hv->Elts[i]);
    }
  }
  return true;
};
