#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>

int QSort(char** pointers_array, size_t array_size, int (*compare_criteria) (const char*, const char*));

#endif
