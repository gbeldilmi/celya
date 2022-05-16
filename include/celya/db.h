#pragma once


/*
 * Database utilities
 */

#define C_DB_CONTENT_MAX_LEN 128

typedef struct dbitem_s {
  int *ncols;
  char **cols;
  char **content;
} dbitem_t;

typedef struct db_s {
  int size;
  int nitems;
  int ncols;
  char **cols;
  dbitem_t *items;
} db_t;

void c_db_free_item(dbitem_t *item);
void c_db_free(db_t *db);
db_t *c_db_new(int cap, int ncols, char **cols);
