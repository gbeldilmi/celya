#include <celya.h>

/*
 * c_btree_free
 *
 * free a binary tree and every nodes in it
 *
 * warning:
 *   the content of each node is not freed
 *
 * @tree:
 *   binary tree to free
 *
 * return:
 *   void
 */

void c_btree_free(btree_t *tree) {
  if (tree) {
    c_btree_free(tree->left);
    c_btree_free(tree->right);
    free(tree);
  }
}
