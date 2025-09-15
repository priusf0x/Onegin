#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>

char** QSort(char* pointers_array[], size_t array_size, int (*compare_criteria) (const char*, const char*));
char** MergeArray(char** array_1, char** array_2, size_t size_1, size_t size_2, char* compare_string);

#endif
