#include "main.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "help.h"
#include "not_stdio.h"
#include "sorting.h"
#include "string_functions/not_stdio.h"
#include <assert.h>

int main(void)
{
    FILE* file_input = fopen(INPUT_NAME, "r");
    FILE* file_output = fopen(OUTPUT_NAME, "w");

    assert(file_input != NULL);
    assert(file_output != NULL);

    size_t str_count = CountStrNumber(file_input);
    char** array_of_pointers =(char**) calloc(str_count, sizeof(char*));

    EnterData(array_of_pointers, str_count, file_input);
    array_of_pointers = QSort(array_of_pointers, str_count, str_cmp);

    for (size_t i = 0; i < str_count; i++)
    {
        fprintf(file_output, "%s\n", array_of_pointers[i]);
    }

    FreeData(array_of_pointers, str_count);

    fclose(file_output);
    fclose(file_input);

    return 0;
}
