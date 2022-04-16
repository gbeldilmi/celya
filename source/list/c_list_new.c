#include <celya.h>

/*
 * c_list_new
 *
 * create a new list
 *
 * @content:
 *   content of the new list
 * @next:
 *   next node
 *
 * return:
 *   list newly created
 */

list_t *c_list_new(void *content, list_t *next) {
  list_t *l;

  if ((l = (list_t *) malloc(sizeof(list_t)))) {
    l->content = content;
    l->next = next;
  }

  return (l);
}
