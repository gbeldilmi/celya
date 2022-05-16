#include <celya.h>

/*
 * c_db_new
 *
 * create a new empty database
 *
 * @cap:
 *   initial capacity of the database
 * @ncols:
 *   number of columns
 * @cols:
 *   column names
 *
 * return:
 *   database newly created
 */

db_t *c_db_new(int cap, int ncols, char **cols) {
  db_t *db;
  int i;

  db = malloc(sizeof(db_t));
  db->size = cap;
  db->nitems = 0;
  db->ncols = ncols;
  db->cols = malloc(sizeof(char*) * ncols);
  for (i = 0; i < ncols; i++) {
    db->cols[i] = strdup(cols[i]);
  }
  db->items = malloc(sizeof(dbitem_t) * cap);
  
  return (db);
}
