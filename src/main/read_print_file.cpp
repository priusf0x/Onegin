#include "read_print_file.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <assert.h>

#include "tools.h"
#include "compare_functions.h"

int ReadFile(char** input_buffer, char*** array_of_pointers, size_t* str_count, const char* input_name)
{
    struct stat file_stat = {0};
    FILE* file_input = fopen(input_name, "r");

    ASSERT(input_buffer != NULL);
    ASSERT(array_of_pointers != NULL);
    ASSERT(str_count != NULL);
    ASSERT(input_name != NULL);

    if (file_input == NULL)
    {
        return 1;
    }

    stat(input_name, &file_stat);
    size_t char_number = (size_t) (file_stat.st_size + 1);

    *input_buffer = (char*) calloc(char_number, sizeof(char));
    size_t read_count = fread((void*) *input_buffer, sizeof(char), char_number, file_input);
    (*input_buffer)[read_count] = '\0';
    memset(input_buffer + read_count, 0, char_number - read_count - 1);

    *str_count = CountCharInStr('\n', *input_buffer);
    *array_of_pointers =(char**) calloc(*str_count, sizeof(char*));

    EnterData(*array_of_pointers, str_count, *input_buffer);

    if (fclose(file_input) != 0)
    {
        return 1;
    }

    return 0;
}

int WriteInFile(char** array_of_pointers, size_t str_count, const char* output_name)
{
    ASSERT(array_of_pointers != NULL);
    ASSERT(output_name != NULL);

    FILE* file_output = fopen(output_name, "w");

    if (file_output == NULL)
    {
        return 1;
    }

    for (size_t i = 0; i < str_count; i++)
    {
        const char* pointer = array_of_pointers[i];
        fwrite(pointer, CountStringLength(pointer), sizeof(char), file_output);
        fputc('\n',file_output);
    }

    if (fclose(file_output) != 0)
    {
        return 1;
    }

    return 0;
}
