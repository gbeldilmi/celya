#include <celya.h>

/*
 * c_str_map
 *
 * apply a given function to each character of a string
 * 
 * @str:
 *   string to iterate over
 * @fn:
 *   function to call for each character
 * 
 * return:
 *   string resulting from the application of the function
 */

char *c_str_map(const char *str, char (*fn)(char)) {
  char *s;
  size_t l;
  size_t i;

  s = NULL;
  if (str && fn) {
    l = strlen(str);
    s = (char *) malloc(sizeof(char) * (l + 1));
  }
  if (s) {
    i = 0;
    while (i < l) {
      s[i] = (*fn)(str[i]);
      i++;
    }
    s[i] = '\0';
  }
  return (s);
}
