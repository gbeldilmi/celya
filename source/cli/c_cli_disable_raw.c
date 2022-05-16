#include <celya.h>

/*
 * c_cli_disable_raw
 *
 * disable raw mode
 *
 * @void
 *
 * return:
 *   void
 */

void c_cli_disable_raw(void) {
  struct termios tty_attr;
  
  tcgetattr(0, &tty_attr);
  tty_attr.c_lflag |= ((ICANON | ECHO));
  tcsetattr(0, TCSAFLUSH, &tty_attr);
}
