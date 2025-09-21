#ifndef READ_PRINT_FILE_H
#define READ_PRINT_FILE_H

#include <stdlib.h>

#include "error.h"

enum ErrorTypes ReadFile(char** input_buffer, char*** array_of_pointers, size_t* str_count, const char* input_name);
int             WriteInFile(char** array_of_pointers, size_t str_count, const char* output_name);

#endif
