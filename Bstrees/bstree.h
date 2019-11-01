#ifndef _BSTREE_H_
#define _BSTREE_H_

/* Routines for binary search trees.  Keys are strings, and ordering
   is done via strcmp.  The tree will not hold duplicates.  Thus,
   if you try to insert a duplicate key into the tree, it will replace
   the key and the jval of the node with that key.  That may not be
   what you want, but that's what it does. */

#include "jval.h"

typedef struct bstreenode {
  char *key;
  Jval val;
  struct bstreenode *left;
  struct bstreenode *right;
} BstreeNode;

typedef struct {
  BstreeNode *root;
} Bstree;


/* Create and destroy binary search trees */
extern Bstree     *new_bstree();
extern void        free_bstree(Bstree *);

/* Insert and find.  Bstree_find() returns NULL if it can't
   find the key.  */

extern BstreeNode *bstree_insert(Bstree *, char *, Jval);
extern BstreeNode *bstree_find(Bstree *, char *);
extern void        bstree_delete_node(Bstree *, BstreeNode *);
extern BstreeNode *bstree_find_max(Bstree *);
extern BstreeNode *bstree_find_min(Bstree *);

#endif
