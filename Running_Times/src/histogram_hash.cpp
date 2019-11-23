#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include "MOA.hpp"
#include "histogram.hpp"
using namespace std;

/* We use two vectors, Bins and Elts, which are both fixed-size hash tables, keyed on 
   the bin number.  We're going to use double-hashing for this implementation, using
   the MOA random number generator to generate the second hash.  Our hash table size
   will be 500009, which is a prime number.  It also means that we can't have more than
   500009 bins.  */

class Histo_Hash {
  public:
    vector <int> Bins;
    vector <int> Elts;
    double Bin_Size;
    bool Empty;
    int Find(int bin) const;    /* This is a helper method, because I'll need to find bins
                             in both Add_Value() and Get_Data(). */
};

/* As with the map version, pretty much everything is identical to Histo_Vector.
   The only changes are to Add_Values() and Get_Data(). */

Histogram::Histogram()
{
  Histo_Hash *hv;

  hv = new Histo_Hash;
  hv->Bin_Size = -1;

  state = (void *) hv;
  Clear();
}

Histogram::~Histogram()
{
  Histo_Hash *hv;

  hv = (Histo_Hash *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_Hash *hv;

  hv = new Histo_Hash;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Hash *hv_original, *hv_copy;

  hv_original = (Histo_Hash *) h.state;
  hv_copy = (Histo_Hash *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_Hash *hv;

  hv = (Histo_Hash *) state;
  hv->Bins.clear();
  hv->Elts.clear();
  hv->Bins.resize(500009, -1);
  hv->Elts.resize(500009, 0);
  hv->Empty = true;
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Hash *hv;

  hv = (Histo_Hash *) state;
  if (!hv->Empty) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_Hash *hv;

  hv = (Histo_Hash *) state;
  return hv->Bin_Size;
}

/* Pretty standard double-hashing implementation of find.  It returns
   the index if it finds the hash value, or if it finds where the hash
   value should go.  It returns -1 if the hash table is full. */

int Histo_Hash::Find(int bin) const
{
  MOA rng;
  int index;
  int probes;
  int tsize;
  int h2;

  tsize = Bins.size();

  index = bin % tsize;
  if (Bins[index] == -1 || Bins[index] == bin) return index;
  rng.Seed(bin);

  do {
    h2 = rng.Random_Integer() % tsize;
  } while (h2 == 0);

  for (probes = 0; probes < tsize; probes++) {
    index += h2;
    index %= tsize;
    if (Bins[index] == -1 || Bins[index] == bin) return index;
  }
  return -1;
}

bool Histogram::Add_Value(double d)
{
  Histo_Hash *hv;
  int bin;
  int index;

  hv = (Histo_Hash *) state;

  if (d < 0) return false;
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);

  /* Find the index of the bin.  If -1 is returned, the index can't
     be found, and the hash table is full.  Otherwise, it is the index
     of where the value should go. */

  index = hv->Find(bin);
  if (index == -1) return false;

  /* If the bin isn't there, put it where it belongs. 
     Then add one to the val. */

  if (hv->Bins[index] == -1) hv->Bins[index] = bin;
  hv->Elts[index]++;
  hv->Empty = false;
  
  return true;
}

/* Get data creates the bin_ids vector from all of the bins and sorts it. Then it
   traverses the vector, and for each bin, it finds the bin in the hash table and
   sets the element from the bin. */

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_Hash *hv;
  size_t i;
  int index;

  hv = (Histo_Hash *) state;
  if (hv->Bin_Size < 0) return false;

  bin_ids.clear();
  num_elts.clear();

  for (i = 0; i < hv->Bins.size(); i++) {
    if (hv->Bins[i] != -1) bin_ids.push_back(hv->Bins[i]);
  }
  
  sort(bin_ids.begin(), bin_ids.end());

  for (i = 0; i < bin_ids.size(); i++) {
    index = hv->Find(bin_ids[i]);
    num_elts.push_back(hv->Elts[index]);
  }
  return true;
};
