#include <celya.h>

/*
 * c_list_map
 *
 * apply a given function to each element of a list
 *
 * @list:
 *   list to iterate over
 * @fn:
 *   function to call for each element
 *
 * return:
 *   list resulting from the application of the function
 */

list_t *c_list_map(list_t *list, list_t *(*fn)(list_t *)) {
  list_t *e;
  list_t *ne;
  list_t *nl;

  nl = NULL;
  if (list && fn) {
    e = list;
    ne = fn(e);
    nl = ne;
    while (e->next)
    {
      ne->next = fn(e->next);
      ne = ne->next;
      e = e->next;
    }
  }

  return (nl);
}
