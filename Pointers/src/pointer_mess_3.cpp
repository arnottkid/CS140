/* This is a program that mixes pointers and vectors.
   It is good practice for you to walk through this one *really* slowly. */

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class VP {
  public:
    vector <int> vec;
};

int main()
{
  vector <int> iv;                     // Vector of integers
  vector <int> *ivp, *jvp;             // Pointers to vector of integers
  vector < vector <int> * > *ivpp;     // Pointer to a vector of pointers to vectors of integers
  VP *vp;                              // Pointer to an instance of the VP class.
  size_t i, j;

  /* Set iv to be the first 10 multiples of 11, and print them out. */

  for (i = 0; i < 10; i++) iv.push_back(11*i);
  for (i = 0; i < iv.size(); i++) printf("%2d ", iv[i]); 
  printf("\n");

  /* Set ivp to point to iv -- as you can see, it prints out the same vector.
     I like to use that at method here, because it looks I think, than (*ivp)[i]. */

  ivp = &iv;
  for (i = 0; i < ivp->size(); i++) printf("%2d ", ivp->at(i));
  printf("\n");

  cout << endl << "Resizing ivp is reflecting by iv being resized." << endl << endl;
  ivp->resize(4);
  for (i = 0; i < iv.size(); i++) printf("%2d ", iv[i]); 
  printf("\n");

  /* I use "new" to create a new vector of pointers to vectors of integers, and then 
     call push_back to put the same pointer, ivp, into both vector entries. */

  cout << endl << "Creating ivpp, and setting both of its elements to ivp." << endl << endl;
  ivpp = new vector < vector <int> *>;
  ivpp->push_back(ivp);
  ivpp->push_back(ivp);

  /* Here (*ivpp)[0] and (*ivpp)[1] are both pointers to the same vector.  This code prints
     out the vectors pointed to by ivpp[0] and ivpp[1].  Since they are the same vector,
     the two lines are the same. */

  printf("(*ivpp)[0]:");
  for (i = 0; i < (*ivpp)[0]->size(); i++) printf(" %2d", (*ivpp)[0]->at(i));
  printf("\n");

  printf("(*ivpp)[1]:");
  for (i = 0; i < (*ivpp)[1]->size(); i++) printf(" %2d", (*ivpp)[1]->at(i));
  printf("\n");

  /* I now change iv[0] to -50.  Remember, ivp points to iv, and both ivpp[0] and
     ivpp[1] were set to ivp, so this change will be reflected when I print out
     (*ivpp)[0] and (*ivpp)[1]: */

  cout << endl << "Setting iv[0] to -50.  This will be reflected in both (*ivpp)[0] and (*ivpp[1])"
       << endl << endl;
  iv[0] = -50;

  /* This code also prints out (*ivpp)[0] and (*ivpp)[1].  It does it in a different
     way, though, by using that temporary variable jvp. */

  for (i = 0; i < ivpp->size(); i++) {
    printf("(*ivpp)[%lu]:", i);
    jvp = ivpp->at(i);
    for (j = 0; j < jvp->size(); j++) printf(" %2d", jvp->at(j));
    printf("\n");
  }
  return 0;

  /* Finally, I use new to allocate an instance of the VP class.  
     I use an arrow to get at vp's member variable.  However, since that member
     variable is a vector, and not a pointer to a vector, you access its methods
     with "." and its elements with "[]": */

  cout << endl << "This code demonstrates a pointer to a class whose member variable is a vector."
       << endl << endl;
  vp = new VP;
  for (i = 0; i < 10; i++) vp->vec.push_back(9*i);
  for (i = 0; i < vp->vec.size(); i++) printf("%2d ", vp->vec[i]); 
  printf("\n");
  return 0;
}
