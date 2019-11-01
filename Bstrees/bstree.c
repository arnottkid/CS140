#include <stdio.h>
#include "bstree.h"

/* -------------------------------------- */
/* Create and destroy binary search trees */

Bstree *new_bstree()
{
  Bstree *b;

  b = (Bstree *) malloc(sizeof(Bstree));
  if (b == NULL) { perror("malloc"); exit(1); }
  b->root = NULL;
  return b;
}

static void recursive_free_bstree(BstreeNode *bn)
{
  if (bn->left != NULL) recursive_free_bstree(bn->left);
  if (bn->right != NULL) recursive_free_bstree(bn->right);
  free(bn);
  return;
}

void free_bstree(Bstree *b)
{
  BstreeNode *bn;

  if (b->root != NULL) recursive_free_bstree(b->root);
  free(b);
  return;
}
  
/* --------------------------- */
/* Insert a node into a tree. */

BstreeNode *bstree_insert(Bstree *b, char *key, Jval val)
{
  BstreeNode *bs, *tmp;
  int cmp;

  /* First, create the new node */

  bs = (BstreeNode *) malloc(sizeof(BstreeNode));
  bs->left = NULL;
  bs->right = NULL;
  bs->key = key;
  bs->val = val;

  /* If it is the first node, put it there */

  if (b->root == NULL) {
    b->root = bs;
    return bs;
  }

  /* Otherwise, find where it should go, and insert it there */

  tmp = b->root;
  while (1) {
    cmp = strcmp(tmp->key, key);
    if (cmp == 0) {                /* If the key is found. */
      tmp->key = key;
      tmp->val = val;
      free(bs);
      return tmp;
    } else if (cmp > 0) {
      if (tmp->left == NULL) {    /* If the key is less than tmp */
        tmp->left = bs;
        return bs;
      } else { 
        tmp = tmp->left;
      }
    } else {
      if (tmp->right == NULL) {    /* If the key is greater than tmp */
        tmp->right = bs;
        return bs;
      } else { 
        tmp = tmp->right;
      }
    }
  }
}

/* ------------------------------------------ */
/* Find a node in the tree with the given key */

BstreeNode *bstree_find(Bstree *b, char *key)
{
  BstreeNode *tmp;
  int cmp;

  tmp = b->root;
  while (tmp != NULL) {
    cmp = strcmp(tmp->key, key);
    if (cmp == 0) return tmp;
    if (cmp > 0) {
      tmp = tmp->left;
    } else {
      tmp = tmp->right;
    }
  }
  return NULL;
}

/* ------------------- */
/* Delete a given node */

static BstreeNode *find_parent(Bstree *t, BstreeNode *bn)
{
  int cmp;
  BstreeNode *tmp;

  tmp = t->root;

  if (tmp == bn) return NULL;

  while(1) {
    cmp = strcmp(tmp->key, bn->key);
    if (cmp == 0) {
      fprintf(stderr, "Internal Error: two nodes with the same key (%s)\n",
                       tmp->key);
      exit(1);
    }
    if (cmp > 0) {
      if (tmp->left == NULL) {
        fprintf(stderr, "Internal Error finding parent -- left child empty\n");
        exit(1);
      } else if (tmp->left == bn) {
        return tmp;
      } else {
        tmp = tmp->left;
      }
    } else {
      if (tmp->right == NULL) {
        fprintf(stderr, "Internal Error finding parent -- right child empty\n");
        exit(1);
      } else if (tmp->right == bn) {
        return tmp;
      } else {
        tmp = tmp->right;
      }
    }
  }
}
  
void bstree_delete_node(Bstree *b, BstreeNode *bn)
{
  BstreeNode *parent, *replacement;
  int cmp;
  char *key;
  Jval val;

  parent = find_parent(b, bn);

  if (bn->left != NULL && bn->right != NULL) {
    replacement = bn->right;
    while (replacement->left != NULL) {
      replacement = replacement->left;
    }
    key = replacement->key;
    val = replacement->val;
    bstree_delete_node(b, replacement);
    bn->key = key;
    bn->val = val;
    return;
  } else {
    if (bn->left == NULL && bn->right == NULL) {
      replacement = NULL;
    } else if (bn->left == NULL) {
      replacement = bn->right;
    } else {
      replacement = bn->left;
    }
    if (parent == NULL) {
      b->root = replacement;
    } else if (parent->left == bn) {
      parent->left = replacement;
    } else {
      parent->right = replacement;
    }
    free(bn);
    return;
  }
}

BstreeNode *bstree_find_min(Bstree *b) 
{
  BstreeNode *bn;

  if (b->root == NULL) return NULL;
  bn = b->root; 
  while (bn->left != NULL) bn = bn->left;
  return bn;
}

BstreeNode *bstree_find_max(Bstree *b)
{
  BstreeNode *bn;

  if (b->root == NULL) return NULL;
  bn = b->root; 
  while (bn->right != NULL) bn = bn->right;
  return bn;
}
