#include <stdio.h>
#include <string.h>
#include "bstree.h"
#include "fields.h"

prepostorder(int pre, BstreeNode *bn, int depth)
{
  int i;

  if (bn == NULL) return;
  if (pre) {
    for (i = 0; i < depth; i++) printf(" ");
    printf("%s %.2lf\n", bn->key, jval_d(bn->val));
  }
  prepostorder(pre, bn->left, depth+2);
  prepostorder(pre, bn->right, depth+2);
  if (!pre) {
    for (i = 0; i < depth; i++) printf(" ");
    printf("%s %.2lf\n", bn->key, jval_d(bn->val));
  }
}

inorder(BstreeNode *bn)
{
  if (bn == NULL) return;
  inorder(bn->left);
  printf("%-30s %10.2lf\n", bn->key, jval_d(bn->val));
  inorder(bn->right);
}

main()
{
  Bstree *b;
  BstreeNode *bn;
  IS is;
  double dval;

  is = new_inputstruct(NULL);
  b = new_bstree();

  while (1) {
    printf("BSTREE> ");
    fflush(stdout);
    if (get_line(is) < 0) exit(0);
    if (is->NF > 0) {
      if (strcmp(is->fields[0], "INSERT") == 0) {
        if (is->NF != 3) {
          printf("INSERT name value\n");
        } else if (sscanf(is->fields[2], "%lf\n", &dval) != 1) {
          printf("INSERT name value -- value must be a number\n");
        } else {
         (void) bstree_insert(b, strdup(is->fields[1]), new_jval_d(dval));
        }
      } else if (strcmp(is->fields[0], "DELETE") == 0) {
        if (is->NF != 2) {
          printf("DELETE name\n");
        } else {
          bn = bstree_find(b, is->fields[1]);
          if (bn == NULL) {
            printf("No %s in the tree\n", is->fields[1]);
          } else {
            bstree_delete_node(b, bn);
          }
        }
      } else if (strcmp(is->fields[0], "INORDER") == 0) {
        if (is->NF != 1) {
          printf("INORDER takes no arguments\n");
        } else {
          inorder(b->root);
        }
      } else if (strcmp(is->fields[0], "PREORDER") == 0) {
        if (is->NF != 1) {
          printf("PREORDER takes no arguments\n");
        } else {
          prepostorder(1, b->root, 0);
        }
      } else if (strcmp(is->fields[0], "MAX") == 0) {
        if (is->NF != 1) {
          printf("MAX takes no arguments\n");
        } else {
          bn = bstree_find_max(b);
          if (bn == NULL) {
            printf("No maximum element\n");
          } else {
            printf("%s %.2lf\n", bn->key, jval_d(bn->val));
          }
        }
      } else if (strcmp(is->fields[0], "MIN") == 0) {
        if (is->NF != 1) {
          printf("MIN takes no arguments\n");
        } else {
          bn = bstree_find_min(b);
          if (bn == NULL) {
            printf("No minimum element\n");
          } else {
            printf("%s %.2lf\n", bn->key, jval_d(bn->val));
          }
        }
      } else if (strcmp(is->fields[0], "POSTORDER") == 0) {
        if (is->NF != 1) {
          printf("POSTORDER takes no arguments\n");
        } else {
          prepostorder(0, b->root, 0);
        }
      } else if (strcmp(is->fields[0], "QUIT") == 0) {
        exit(0);
      } else {
        printf("Valid commands are INSERT DELETE INORDER PREORDER POSTORDER MAX MIN QUIT\n");
      }
    }
  }
}
