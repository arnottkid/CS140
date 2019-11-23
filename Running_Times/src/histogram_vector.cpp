#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include "histogram.hpp"
using namespace std;

/* This is my internal definition of a vector version of the histo vector. */

class Histo_Vector {
  public:
    vector <int> Elts;
    double Bin_Size;
};

/* The constructor allocates an instance of Histo_Vector, and then sets the
   state member variable to that instance. */

Histogram::Histogram()
{
  Histo_Vector *hv;

  hv = new Histo_Vector;
  hv->Bin_Size = -1;

  state = (void *) hv;
}

/* The destructor calls the Histo_Vector destructor, which will clear out the
   Elts vector, and release the memory of the instance. */

Histogram::~Histogram()
{
  Histo_Vector *hv;

  hv = (Histo_Vector *) state;
  delete hv;
}

/* The copy constructor creates a new Histo_Vector, and then uses the
   assignment overload to copy from h. */
   
Histogram::Histogram(const Histogram &h)
{
  Histo_Vector *hv;

  hv = new Histo_Vector;
  state = (void *) hv;
  *this = h;
}

/* The assignment overload allocates a new instance of Histo_Vector, and 
   copies it from h's Histo_Vector. */

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Vector *hv_original, *hv_copy;

  hv_original = (Histo_Vector *) h.state;
  hv_copy = (Histo_Vector *) state;
  *hv_copy = *hv_original;
  return *this;
}

/* Clear() gets rid of the data by 
   clearint the Elts vector. */

void Histogram::Clear()
{
  Histo_Vector *hv;

  hv = (Histo_Vector *) state;
  hv->Elts.clear();
}
  
/* Set_Bin_Size() error checks its argument,
   and also error checks that there no data
   (because it wouldn't make sense to change
   the bin size if we have already assigned
   data to bins).  It then sets the bin size. */

bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Vector *hv;

  hv = (Histo_Vector *) state;

  if (bs <= 0) return false;
  if (hv->Elts.size() != 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
/* Get_Bin_Size simply returns the bin size
   from the Histo_Vector. */

double Histogram::Get_Bin_Size() const
{
  Histo_Vector *hv;

  hv = (Histo_Vector *) state;
  return hv->Bin_Size;
}

bool Histogram::Add_Value(double d)
{
  Histo_Vector *hv;
  int bin;

  hv = (Histo_Vector *) state;

  if (d < 0) return false;                      // Error check
  if (hv->Bin_Size < 0) return false;

  bin = (int) floor(d/hv->Bin_Size);            // Calculate the bin and make sure there's room
  if (bin >= (int) hv->Elts.size()) {           // for it in the Elts vector.
    hv->Elts.resize(bin+1, 0);
  }

  hv->Elts[bin]++;                              // Add one to the bin.
  return true;
}

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_Vector *hv;
  size_t i;

  hv = (Histo_Vector *) state;
  if (hv->Bin_Size < 0) return false;

  bin_ids.clear();                          // Clear out the vectors if they have any elements.
  num_elts.clear();

  for (i = 0; i < hv->Elts.size(); i++) {   // Push the bins onto id's and Elts[bin] onto num_elts.
    if (hv->Elts[i] != 0) {
      bin_ids.push_back(i);
      num_elts.push_back(hv->Elts[i]);
    }
  }
  return true;
};
