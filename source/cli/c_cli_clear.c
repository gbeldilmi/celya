#include <celya.h>

/*
 * c_cli_clear
 *
 * clear the screen
 *
 * @void
 *
 * return:
 *   void
 */

void c_cli_clear(void) {
  printf("\033[H\033[2J");
}
