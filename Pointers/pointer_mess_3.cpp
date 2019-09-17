#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef vector <int> IVec;

class VP {
  public:
    IVec iv;
};

main()
{
  IVec iv;
  IVec *ivp;
  vector <IVec *> *ivpp;
  int i, j;
  VP *vp;

  for (i = 0; i < 10; i++) iv.push_back(lrand48()%100);

  for (i = 0; i < iv.size(); i++) printf("%2d ", iv[i]); printf("\n");

  ivp = &iv;
  for (i = 0; i < ivp->size(); i++) printf("%2d ",ivp->at(i)); printf("\n");

  ivp->resize(4);
  for (i = 0; i < iv.size(); i++) printf("%2d ", iv[i]); printf("\n");

  ivpp = new vector <IVec *>;
  ivpp->push_back(ivp);
  ivpp->push_back(ivp);

  for (i = 0; i < ivpp->size(); i++) {
    printf("Element %d of ivpp points to the vector:", i);
    ivp = ivpp->at(i);
    for (j = 0; j < ivp->size(); j++) printf(" %2d", ivp->at(j)); printf("\n");
  }

  iv[0] = -50;
  for (i = 0; i < ivpp->size(); i++) {
    printf("Element %d of ivpp points to the vector:", i);
    ivp = ivpp->at(i);
    for (j = 0; j < ivp->size(); j++) printf(" %2d", ivp->at(j)); printf("\n");
  }

  vp = new VP;
  for (i = 0; i < 10; i++) vp->iv.push_back(lrand48()%100);
  for (i = 0; i < vp->iv.size(); i++) printf("%2d ", vp->iv[i]); printf("\n");
}
