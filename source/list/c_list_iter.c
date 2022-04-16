#include <celya.h>

/*
 * c_list_iter
 *
 * apply a given function to each element of a list
 *
 * @list:
 *   list to iterate over
 * @fn:
 *   function to call for each element
 *
 * return:
 *   void
 */

void c_list_iter(list_t *list, void (*fn)(list_t *)) {
  list_t *l;

  if (list && fn) {
    l = list;
    while (l) {
      fn(l);
      l = l->next;
    }
  }
}
