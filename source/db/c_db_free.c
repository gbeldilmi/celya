#include <celya.h>

/*
 * c_db_free
 *
 * free a database
 *
 * @db:
 *   database to free
 *
 * return:
 *   void
 */

void c_db_free(db_t *db) {
  int i;

  for (i = 0; i < db->nitems; i++) {
    c_db_free_item(&(db->items[i]));
  }
  free(db->items);
  for (i = 0; i < db->ncols; i++) {
    free(db->cols[i]);
  }
  free(db->cols);
  free(db);
}
