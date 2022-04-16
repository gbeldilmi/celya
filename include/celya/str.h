#pragma once


/*
 * Strings
 */

void c_str_iter(char *str, void (*fn)(char *));
char *c_str_map(const char *str, char (*fn)(char));
char *c_str_new(size_t size);
