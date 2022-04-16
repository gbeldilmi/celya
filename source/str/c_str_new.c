#include <celya.h>

/*
 * c_str_new
 *
 * create a new empty string
 *
 * @size:
 *   size of the string
 *
 * return:
 *   string newly created
 */

char *c_str_new(size_t size) {
  return ((char *) calloc((size + 1), sizeof(char)));
}
