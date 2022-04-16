#include <celya.h>

/*
 * c_list_length
 *
 * return the length of a list
 *
 * @list:
 *   list to be measured
 *
 * return:
 *   length of the list
 */

size_t c_list_length(list_t *list) {
  size_t len;

  len = 0;
  while (list) {
    list = list->next;
    len++;
  }

  return (len);
}
