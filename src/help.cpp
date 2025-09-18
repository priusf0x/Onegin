#include "help.h"

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "not_stdio.h"

size_t CountStrNumber(FILE * file_pointer)
{
    assert(file_pointer != NULL);

    size_t str_count = 0;
    int character = 0;
    bool flag = false;

    do
    {
        character = (char) fgetc(file_pointer);

        if (!isspace(character))
        {
            flag = true;
        }

        if (((character == '\n') || (character == EOF)) && flag)
        {
            str_count++;
            flag = false;
        }
        //printf("%d\n", str_count);
    } while (character != EOF);

    fseek(file_pointer, 0L, SEEK_SET);

    return str_count - 1;
}

void EnterData(char* array_of_pointers[], size_t str_count, FILE * input_file)
{
    size_t n = 0;
    char character = 0;
    for (size_t index = 0; index < str_count; index++)
    {
        n = 0;

        while (isspace(character = (char) fgetc(input_file)))
        {
            continue;
        }
        ungetc(character, input_file);

        get_line(&(array_of_pointers[index]), &n, input_file);
    }

    fseek(input_file, 0L, SEEK_SET);
}

void FreeData(char* array_of_pointers[], size_t str_count)
{
    for (size_t index = 0; index < str_count; index++)
    {
        free(array_of_pointers[index]);
    }

    free(array_of_pointers);
}
