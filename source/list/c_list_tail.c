#include <celya.h>

/*
 * c_list_tail
 *
 * return the tail of a list
 *
 * @list:
 *   list to get the tail from
 *
 * return:
 *   tail of the list
 */

list_t *c_list_tail(list_t *list) {
  list_t *tail;

  tail = list;
  while (tail->next) {
    tail = tail->next;
  }

  return (tail);
}
