#include <vector>
#include <string>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

BSTree::BSTree()
{
}

BSTree::BSTree(const BSTree &t)
{
  (void) t;
}

BSTree& BSTree::operator= (const BSTree &t)
{
  (void) t;
  return *this;
}

BSTree::~BSTree()
{
}

void BSTree::Clear()
{
}
                                      
bool BSTree::Insert(const string &key, void *val)
{
  (void) key;
  (void) val;
  return false;
}
    
void *BSTree::Find(const string &key) const
{
  (void) key;
  return NULL;
}
          
bool BSTree::Delete(const string &key)
{
  (void) key;
  return false;
}
               
void BSTree::Print() const
{
}
                                
size_t BSTree::Size() const
{
  return 0;
}

bool BSTree::Empty() const
{
  return false;
}


vector <string> BSTree::Ordered_Keys() const
{
  vector <string> rv;
  return rv;
}
    
vector <void *> BSTree::Ordered_Vals() const
{
  vector <void *> rv;
  return rv;
}
         

/* You'll write these as part of your lab. */

int BSTree::Depth(const string &key) const
{
  (void) key;
  return -1;
}
           
int BSTree::Height() const
{
  return -1;
}
                                

void BSTree::recursive_inorder_print(int level, const BSTNode *n) const
{
  (void) level;
  (void) n;
}
                
void BSTree::recursive_destroy(BSTNode *n)
{
  (void) n;
}
                                       
void BSTree::make_val_vector(const BSTNode *n, vector<void *> &v) const
{
  (void) n;
  (void) v;
}
           

/* You'll write this as part of your lab. */

void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  (void) n;
  (void) v;
}
     
BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
                            const vector<void *> &vals,
                            size_t first_index,
                            size_t num_indices) const
{
  (void) sorted_keys;
  (void) vals;
  (void) first_index;
  (void) num_indices;
  return NULL;
}
