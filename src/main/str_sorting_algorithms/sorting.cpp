#include "sorting.h"

#include <stdlib.h>

#include "tools.h"
#include "assert.h"

int
QSort(char** pointers_array,
      size_t array_size,
      int    (*compare_criteria) (const char*, const char*))
{
    ASSERT(pointers_array != NULL);
    ASSERT(compare_criteria != NULL);

    size_t bigger_index = array_size - 1;
    size_t current_index = 0;
    char* buffer_element = NULL;
    while(current_index != bigger_index)
    {
        if (compare_criteria(pointers_array[current_index + 1], pointers_array[current_index]) <= 0)
        {
            buffer_element = pointers_array[current_index + 1];
            pointers_array[current_index + 1] = pointers_array[current_index]; //УМОМ - копипаст, функция
            pointers_array[current_index] = buffer_element;
            current_index++;
        }
        else
        {
            if (compare_criteria(pointers_array[bigger_index], pointers_array[current_index]) <= 0)
            {
                buffer_element = pointers_array[bigger_index];
                pointers_array[bigger_index] = pointers_array[current_index + 1];
                pointers_array[current_index + 1] = buffer_element;
            }
            else
            {
                bigger_index--;
            }
        }
    }

    if (current_index >= 1)
    {
        QSort(pointers_array, current_index, compare_criteria);
    }

    if (array_size - current_index - 1 >= 2)
    {
        QSort(pointers_array + current_index + 1, array_size - current_index - 1, compare_criteria);
    }

    return 0;
}
