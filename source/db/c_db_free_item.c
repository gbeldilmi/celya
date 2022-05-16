#include <celya.h>

/*
 * c_db_free_item
 *
 * free a database item
 *
 * @item:
 *   database item to free
 *
 * return:
 *   void
 */

void c_db_free_item(dbitem_t *item) {
  int i;

  for (i = 0; i < *(item->ncols); i++) {
    free(item->content[i]);
  }
  free(item);
}
