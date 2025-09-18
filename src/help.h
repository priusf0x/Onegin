#ifndef HELP_H
#define HELP_H

#include <stdio.h>

FILE * OpenSafely(const char* file_name, const char* access_level);
int CloseSafely(FILE* file_pointer);
size_t CountStrNumber(FILE * file_pointer);
size_t FindMaxStrSize(FILE * file_pointer);
void EnterData(char** array_of_pointers, size_t str_count, FILE * input_file);
void FreeData(char* array_of_pointers[], size_t str_count);

#endif
