#pragma once


/*
 * Binary tree
 */

typedef struct btree_s {
  void *content;
  struct btree_s *left;
  struct btree_s *right;
} btree_t;

void c_btree_free(btree_t *tree);
void c_btree_iter(btree_t *tree, void (*fn)(btree_t *));
btree_t *c_btree_map(btree_t *tree, btree_t *(*fn)(btree_t *));
btree_t *c_btree_new(void *content, btree_t *left, btree_t *right);
