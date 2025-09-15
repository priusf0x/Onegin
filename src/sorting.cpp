#include "sorting.h"

#include <stdlib.h>
#include <assert.h>

#include "help.h"

char** QSort(char* pointers_array[], size_t array_size, int (*CompareCriteria) (const char*, const char*))
{
    assert(pointers_array != NULL);

    char** array_less = (char**) calloc(array_size, sizeof(char*));
    char** array_more_or_eq = (char**) calloc(array_size, sizeof(char*));

    size_t size_less = 0, size_more_or_eq = 0;

    char* compare_string = pointers_array[0];

    for (size_t count = 0; count < array_size; count++)
    {
        if (CompareCriteria(pointers_array[count], compare_string) == -1)
        {
            array_less[size_less] = pointers_array[count];
            size_less++;
        }
        else if (pointers_array[count] != compare_string)
        {
            array_more_or_eq[size_more_or_eq] = pointers_array[count];
            size_more_or_eq++;
        }
    }

    if (size_less > 1)
    {
        array_less = QSort(array_less, size_less, CompareCriteria);
    }

    if (size_more_or_eq > 1)
    {
        array_more_or_eq = QSort(array_more_or_eq, size_more_or_eq, CompareCriteria);
    }

    free(pointers_array);

    char** sort_result = MergeArray(array_less, array_more_or_eq, size_less, size_more_or_eq, compare_string);

    return sort_result;
}

char** MergeArray(char** array_1, char** array_2, size_t size_1, size_t size_2, char* compare_string)
{
    size_t sum_size = size_1 + size_2 + 1;

    char** merged_array = (char**) calloc(sum_size, sizeof(char*));

    for (size_t index = 0; index < size_1; index++)
    {
        merged_array[index] = array_1[index];
    }

    merged_array[size_1] = compare_string;

    for (size_t index = size_1 + 1; index < sum_size; index++)
    {
        merged_array[index] = array_2[index - size_1 - 1];
    }

    free(array_1);
    free(array_2);

    return merged_array;
}
