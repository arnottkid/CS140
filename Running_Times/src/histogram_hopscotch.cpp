#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdint.h>
#include "histogram.hpp"
using namespace std;

class Element {
  public:
    int Key;
    int Val;
    uint32_t B;
};

class Histo_Hopscotch {
  public:
    double Bin_Size;
    bool Empty;
    vector <Element> Table;
    int H;
    int Mask;
    int Find(int bin) const;
    int Insert(int bin);               /* Returns the index into which it was inserted. 
                                          Sets the val to one. */
    void Resize();
    void Print();
    void Double_Check();
};

void Histo_Hopscotch::Double_Check()
{
  size_t i;
  int index, diff;

  for (i = 0; i < Table.size(); i++) {
    if (Table[i].Key != -1) {
      index = Table[i].Key & Mask;
      diff = (i - index) & Mask;
      if ((Table[index].B & (1 << diff)) == 0) {
        printf("Bad Table.  Key = 0x%x.  Index %d.  Base %d.  Base.B = 0x%x\n",
           Table[i].Key, (int) i, index, Table[index].B);
        exit(1);
      }
    }
  }
}

void Histo_Hopscotch::Print()
{
  size_t i;

  Double_Check();
  for (i = 0; i < Table.size(); i++) {
    if (Table[i].Key != -1 || Table[i].B != 0) {
      printf("%3d - %8d %8d 0x%x\n", (int) i, Table[i].Key, Table[i].Val, Table[i].B);
    }
  }
}

void Histo_Hopscotch::Resize()
{
  int oldmask, i, diff, ibase, highbit, key, val, index, craftymask;
  int craftymask2, hbm1;
  Element e;

  e.Key = -1;
  e.Val = -1;
  e.B = 0;

  oldmask = Mask;
  highbit = Mask+1;

  hbm1 = (highbit >> 1);
  craftymask = highbit | hbm1;
  craftymask2 = highbit | (1 << 31);
  Table.resize(Table.size()<<1, e);
  Mask = ((int) Table.size())-1;

//  printf("After resize: \n");
//  Print();

 
    /* Do a first pass only on the first H elements.  If a key here is wrapped around,
       then we can move it directly into the second half of the table, and we don't
       update B.. */

  for (i = 0; i < H; i++) {
    /* I should explain this one... */
    if ((Table[i].Key & craftymask) == hbm1) {
      Table[i|highbit].Key = Table[i].Key;
      Table[i|highbit].Val = Table[i].Val;
      Table[i].Key = -1;
      Table[i].Val = -1;
    }
  }

  /* In our second pass, we move keys who belong in the second half of the table. */

  for (i = 0; i < highbit; i++) {
    /* I should explain this too */
    if ((Table[i].Key & craftymask2) == highbit) {
      key = Table[i].Key;
      val = Table[i].Val;
      ibase = (key & oldmask);            /* Delete the old key */
      diff = (i - ibase) & oldmask;
      Table[ibase].B &= (~(1 << diff));
      Table[i].Key = -1;
      Table[i].Val = -1;
 //     printf("After deleting the element in index %d\n", i); Print();
      index = Insert(key);
      Table[index].Val = val;
//      printf("After inserting it back\n"); Print();
    }
  }
}

int Histo_Hopscotch::Find(int bin) const
{
  int index;
  uint32_t bitmap;

  index = bin & Mask;
  bitmap = Table[index].B;
  while (bitmap != 0) {
    if ((bitmap & 0x1) && Table[index].Key == bin) return index;
    index++;
    index &= Mask;
    bitmap >>= 1;
  }
  return -1;
}

int Histo_Hopscotch::Insert(int bin)
{
  int index, baseindex, i, j;
  int jindex, jbase, ijdiff, jdiff;
  uint32_t bit;

  baseindex = bin & Mask;
  index = baseindex;
  bit = 1;

  /* Here's the good case. */

  for (i = 0; i < H; i++) {
    if (Table[index&Mask].Key == -1) {
      index &= Mask;
      Table[baseindex].B |= bit;
      Table[index].Key = bin;
      Table[index].Val = 1;
      return index;
    }
    index++;
    bit <<= 1;
  }
  
  /* Now, here's the bad case -- gotta go outside of H */

  while (i < (int) Table.size()) {
 
    /* If we can't find a slot, move onto the next slot. */
    if (Table[index&Mask].Key != -1) {
      index++;
      i++;

    /* Now, we've found a slot.  We need to do the hopscotch thing */

    } else {

      for (j = i-1; j > 0; j--) {
        jindex = baseindex + j;
        jbase = Table[jindex&Mask].Key & Mask;
        ijdiff = (index - jbase) & Mask;
        // printf("i: %d  j: %d  jindex: %d  jbase: %d  ijdiff: %d  index: %d\n", 
        //   i, j, jindex, jbase, ijdiff, index);
        if (ijdiff < H) {
          jdiff = (jindex - jbase) & Mask;
          Table[jbase&Mask].B &= (~(1 << jdiff));
          Table[jbase&Mask].B |= (1 << ijdiff);
          Table[index&Mask].Key = Table[jindex&Mask].Key;
          Table[index&Mask].Val = Table[jindex&Mask].Val;
          Table[jindex&Mask].Key = -1;                    // This should be unnecessary.
          i = j;
          index = jindex;
          if (i < H) {
            index &= Mask;
            Table[baseindex].B |= (1 << i);
            Table[index].Key = bin;
            Table[index].Val = 1;
            return index;
          }
        }
      }
      Resize();       /* Hopscotch failure -- resize and try again. */
      return Insert(bin);
    }
  }
  Resize();          /* The table is full -- resize and try again. */
  return Insert(bin);
}
        

Histogram::Histogram()
{
  Histo_Hopscotch *hv;

  hv = new Histo_Hopscotch;
  state = (void *) hv;

  hv->Bin_Size = -1;
  Clear();
}

Histogram::~Histogram()
{
  Histo_Hopscotch *hv;

  hv = (Histo_Hopscotch *) state;
  delete hv;
}

Histogram::Histogram(const Histogram &h)
{
  Histo_Hopscotch *hv;

  hv = new Histo_Hopscotch;
  state = (void *) hv;
  *this = h;
}

Histogram& Histogram::operator= (const Histogram &h)
{
  Histo_Hopscotch *hv_original, *hv_copy;

  hv_original = (Histo_Hopscotch *) h.state;
  hv_copy = (Histo_Hopscotch *) state;
  *hv_copy = *hv_original;
  return *this;
}

void Histogram::Clear()
{
  Histo_Hopscotch *hv;
  Element e;

  hv = (Histo_Hopscotch *) state;

  e.Key = -1;
  e.Val = -1;
  e.B = 0;
  hv->Table.clear();
  hv->Table.resize(64, e);
  hv->H = 32;
  hv->Mask = 63;
  hv->Empty = true;
}
  
bool Histogram::Set_Bin_Size(double bs)
{
  Histo_Hopscotch *hv;

  hv = (Histo_Hopscotch *) state;
  if (!hv->Empty) return false;
  if (bs <= 0) return false;
  hv->Bin_Size = bs;
  return true;
}
  
double Histogram::Get_Bin_Size() const
{
  Histo_Hopscotch *hv;

  hv = (Histo_Hopscotch *) state;
  return hv->Bin_Size;
}

bool Histogram::Add_Value(double d)
{
  Histo_Hopscotch *hv;
  int bin;
  int index;

  hv = (Histo_Hopscotch *) state;

  if (d < 0) return false;
  if (hv->Bin_Size < 0) return false;
  bin = (int) floor(d/hv->Bin_Size);

  index = hv->Find(bin);
  if (index == -1) {
    (void) hv->Insert(bin);
  } else {
    hv->Table[index].Val++;
  }
  hv->Empty = false;
  return true;
}

/* Get data creates the bin_ids vector from all of the bins and sorts it. Then it
   traverses the vector, and for each bin, it finds the bin in the hash table and
   sets the element from the bin. */

bool Histogram::Get_Data(vector <int> &bin_ids, vector <int> &num_elts) const
{
  Histo_Hopscotch *hv;
  size_t i;
  int index;

  hv = (Histo_Hopscotch *) state;
  if (hv->Bin_Size < 0) return false;

//  hv->Print();
  bin_ids.clear();
  num_elts.clear();

  for (i = 0; i < hv->Table.size(); i++) {
    if (hv->Table[i].Key != -1) bin_ids.push_back(hv->Table[i].Key);
  }
  
  sort(bin_ids.begin(), bin_ids.end());

  for (i = 0; i < bin_ids.size(); i++) {
    index = hv->Find(bin_ids[i]);
    num_elts.push_back(hv->Table[index].Val);
  }
  return true;
};
