#include <celya.h>

/*
 * c_list_free
 *
 * free a list and every elements in it
 *
 * warning:
 *   the content of each element is not freed
 *
 * @list:
 *   list to free
 *
 * return:
 *   void
 */

void c_list_free(list_t *list) {
  list_t *next;

  while (list) {
    next = list->next;
    free(list);
    list = next;
  }
}
