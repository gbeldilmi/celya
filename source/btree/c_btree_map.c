#include <celya.h>

/*
 * c_btree_map
 *
 * apply a given function to each element of a binary tree
 *
 * @tree:
 *   binary tree to iterate over
 * @fn:
 *   function to call for each element
 *
 * return:
 *   binary tree resulting from the application of the function
 */

btree_t *c_btree_map(btree_t *tree, btree_t *(*fn)(btree_t *)) {
  btree_t *t;

  t = NULL;
  if (tree && fn) {
    t = fn(tree);
    t->left = c_btree_map(tree->left, fn);
    t->right = c_btree_map(tree->right, fn);
  }

  return (t);
}
