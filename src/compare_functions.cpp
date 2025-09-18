#include "compare_functions.h"

#include <assert.h>
#include <stdlib.h>

size_t CountStringLength(const char* string)
{
    size_t symbol_counter = 0;

    while (* string != '\n')
    {
        symbol_counter++;
        string++;
    }

    return symbol_counter;
}

int CompareStringReversed(const char *s1, const char *s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    int count_1 = (int) (CountStringLength(s1)), count_2 = (int) (CountStringLength(s2));

    count_1--;
    count_2--;

    if ((count_1 == 0) && (count_2 == 0))
    {
        return 0;
    }
    else if (count_1 <= 0)
    {
        return -1;
    }
    else if (count_2 <= 0)
    {
        return 1;
    }

    char character1 = s1[count_1], character2 = s2[count_2];

    while (count_1 > 0 && count_2 > 0)
    {
        if (character1 < character2)
        {
            return -1;
        }
        else if (character2 < character1)
        {
            return 1;
        }
        else
        {
            count_1--;
            count_2--;
            character1 = s1[count_1];
            character2 = s2[count_2];
        }
    }
    return 0;
}

int CompareStringModified(const char *s1, const char *s2)
{
    size_t index = 0;

    assert(s1 != NULL);
    assert (s2 != NULL);

    char character1 = s1[index];
    char character2 = s2[index];

    while (true)
    {
        if ((character1 == '\n') && (character2 == '\n'))
        {
            return 0;
        }
        else if ((character1 == '\n') || character1 < character2)
        {
            return -1;
        }
        else if ((character2 == '\n') || character2 < character1)
        {
            return 1;
        }
        else
        {
            index++;
            character1 = s1[index];
            character2 = s2[index];
        }
    }
}

