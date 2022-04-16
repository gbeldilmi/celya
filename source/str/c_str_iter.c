#include <celya.h>

/*
 * c_str_iter
 *
 * apply a given function to each character of a string
 *
 * @str:
 *   string to iterate over
 * @fn:
 *   function to call for each character
 *
 * return:
 *   void
 */

void c_str_iter(char *str, void (*fn)(char *)) {
  size_t i;

  if (str && fn) {
    i= 0;
    while (str[i]) {
      fn(&str[i]);
      i++;
    }
  }
}
