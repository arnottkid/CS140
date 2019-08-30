/* This program illustrates how easy it is to make a copy of a potentially
   very large data structure.  It creates a 4x5 matrix of doubles, and then
   creates a copy of it with a single statement.  I then change a few values
   in the copy to verify that it is indeed a copy. */
   
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector < vector <double> > v, vcopy;
  vector <double> dv;
  double val;
  size_t i, j;

  /* First create the matrix v.  Mathmatically, entry i,j of v contains (5i+j+1)/9.0.  
     I's not really important what it contains -- I'm just filling it with some numbers. 
     Not also that I'm not using resize here, but I'm calling v.push_back() with a
     vector, which makes a copy of that vector. */

  val = 1.0;
  for (i = 0; i < 4; i++) {
    dv.clear();
    for (j = 0; j < 5; j++) {
      dv.push_back(val / 9.000);
      val++;
    }
    v.push_back(dv);
  }

  /* This single statement makes a copy of v. */

  vcopy = v;

  /* Zero the elements in the even columns of vcopy. */

  for (i = 0; i < vcopy.size(); i++) {
    for (j = 0; j < vcopy[i].size(); j += 2) vcopy[i][j] = 0;
  }
  
  /* Now print both v and vcopy */

  printf("V:\n\n");

  for (i = 0; i < v.size(); i++) {
    for (j = 0; j < v[i].size(); j++) printf("%8.3lf", v[i][j]);
    printf("\n");
  }
  
  printf("\nVCopy:\n\n");

  for (i = 0; i < vcopy.size(); i++) {
    for (j = 0; j < vcopy[i].size(); j++) printf("%8.3lf", vcopy[i][j]);
    printf("\n");
  }

  return 0;
}
