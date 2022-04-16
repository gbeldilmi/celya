#pragma once


/*
 * Linked list
 */

typedef struct list_s {
  void *content;
  struct list_s *next;
} list_t;

void c_list_free(list_t *list);
void c_list_iter(list_t *list, void (*fn)(list_t *));
size_t c_list_length(list_t *list);
list_t *c_list_map(list_t *list, list_t *(*fn)(list_t *));
list_t *c_list_new(void *content, list_t *next);
list_t *c_list_tail(list_t *list);
