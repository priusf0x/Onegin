#ifndef HELP_H
#define HELP_H

#include <stdio.h>

FILE* OpenSafely(const char* file_name, const char* access_level);
int CloseSafely(FILE* file_pointer);
size_t CountStrNumber(FILE* file_pointer);
size_t FindMaxStrSize(FILE* file_pointer);
char* MakeBuffer(size_t char_number, FILE* file_input);
size_t CountCharInStr(char character, const char* str);
int EnterData(char** array_of_pointers, size_t str_count, char* input_buffer);
int PrintStr(const char* string, FILE* output_file);
int PrintLogo(void);

#endif
