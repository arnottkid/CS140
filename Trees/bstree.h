#include <iostream>
#include <vector>
using namespace std;

class BSTNode {
  public:
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
    string key;
    void *val;
};

class BSTree {
  public:
    BSTree();
    ~BSTree();
    int Insert(string key, void *val);
    void *Find(string key);
    int Delete(string key);
    void Print();
    int Size();
    int Empty();
    vector <void *> Sorted_Vector();
  protected:
    BSTNode *sentinel;
    int size;
    vector <void *> array;
   
    void recursive_inorder_print(int level, BSTNode *n);
    void recursive_make_vector(BSTNode *n);
    void recursive_destroy(BSTNode *n);

};
