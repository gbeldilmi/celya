#include <celya.h>

/*
 * c_btree_iter
 *
 * apply a given function to each element of a binary tree
 *
 * @tree:
 *   binary tree to iterate over
 * @fn:
 *   function to call for each element
 *
 * return:
 *   void
 */

void c_btree_iter(btree_t *tree, void (*fn)(btree_t *)) {
  if (tree && fn) {
    fn(tree);
    c_btree_iter(tree->left, fn);
    c_btree_iter(tree->right, fn);
  }
}
