#include <celya.h>

/*
 * c_btree_new
 *
 * create a new binary tree
 *
 * @content:
 *   content of the new tree
 * @left:
 *   left node
 * @right:
 *   right node
 *
 * return:
 *   binary tree newly created
 */

btree_t *c_btree_new(void *content, btree_t *left, btree_t *right) {
  btree_t *t;

  if ((t = (btree_t *) malloc(sizeof(btree_t)))) {
    t->content = content;
    t->left = left;
    t->right = right;
  }

  return (t);
}
