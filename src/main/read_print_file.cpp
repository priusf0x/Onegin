#include "read_print_file.h"

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

#include "tools.h"
#include "compare_functions.h"
#include "error.h"

int ReadFile(char** input_buffer, char*** array_of_pointers, size_t* str_count, const char* input_name)
{
    ASSERT(input_buffer != NULL);
    ASSERT(array_of_pointers != NULL);
    ASSERT(str_count != NULL);
    ASSERT(input_name != NULL);

    struct stat file_stat = {};
    FILE* file_input = fopen(input_name, "r");

    if (file_input == NULL)
    {
        return READ_ERROR;
    }

    stat(input_name, &file_stat); //ПОПКА-БУДЕТ-КРАСНАЯ - ретарн
    size_t char_number = (size_t) (file_stat.st_size + 1);

    *input_buffer = (char*) calloc(char_number, sizeof(char));
    size_t read_count = fread(*input_buffer, sizeof(char), char_number, file_input);

//     if (*input_buffer == NULL)
//     {
//
//     }

    if (fclose(file_input) != 0)
    {
        return READ_ERROR;
    }

    memset(input_buffer + read_count, 0, char_number - read_count - 1);

    *str_count = CountCharInStr('\n', *input_buffer); //УМОМ -  - добавить \n
    *array_of_pointers = (char**) calloc(*str_count, sizeof(char*)); //ПОПКА-БУДЕТ-КРАСНАЯ - calloc pr

    EnterData(*array_of_pointers, *str_count, *input_buffer);

    return 0;
}

int WriteInFile(char** array_of_pointers, size_t str_count, const char* output_name)
{
    ASSERT(array_of_pointers != NULL);
    ASSERT(output_name != NULL);

    FILE* file_output = fopen(output_name, "w");

    if (file_output == NULL)
    {
        return READ_ERROR;
    }

    for (size_t i = 0; i < str_count; i++)
    {
        const char* pointer = array_of_pointers[i];
        fwrite(pointer, CountStringLength(pointer), sizeof(char), file_output); //УМОМ +1
        fputc('\n',file_output);
    }

    if (fclose(file_output) != 0)
    {
        return READ_ERROR;
    }

    return 0;
}
