#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector <int *> v1;
  vector <int *> v2;
  vector <int> v3;
  vector <int> *v4;
  vector <int *> *v5;
  size_t i;

  for (i = 0; i < 5; i++) {
    v1.push_back(new int);
    *v1[i] = i*10;
  }

  for (i = 0; i < 5; i++) v2.push_back(v1[5-i-1]);

  for (i = 0; i < 5; i++) v3.push_back(*v1[i]);
  
  v4 = &v3;
  v5 = &v1;

  for (i = 0; i < 5; i++) *v1[i] += 100;
  v3[2] += 1000;
  *(v5->at(2)) += 10000;

  cout << "V1";  for (i = 0; i < 5; i++) cout << " " << *v1[i];  cout << endl;
  cout << "V2";  for (i = 0; i < 5; i++) cout << " " << *v2[i];  cout << endl;
  cout << "V3";  for (i = 0; i < 5; i++) cout << " " << v3[i];  cout << endl;
  cout << "V4";  for (i = 0; i < 5; i++) cout << " " << (*v4)[i];  cout << endl;
  cout << "V5";  for (i = 0; i < 5; i++) cout << " " << *((*v5)[i]);  cout << endl;
  return 0;
} 
