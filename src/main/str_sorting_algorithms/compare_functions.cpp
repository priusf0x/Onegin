#include "compare_functions.h"

#include <ctype.h>
#include <stdlib.h>

#include "assert.h"

size_t CountStringLength(const char* string)
{
    ASSERT(string != NULL);

    size_t symbol_counter = 0;

    while ((*string) != '\n')
    {
        symbol_counter++;
        string++;
    }

    return symbol_counter;
}

int CompareStringReversed(const char *s1, const char *s2)
{
    ASSERT(s1 != NULL);
    ASSERT(s2 != NULL);

    int count_1 = (int) (CountStringLength(s1)), count_2 = (int) (CountStringLength(s2));

    do
    {
        char character1 = 0;
        char character2 = 0;

        while((--count_1 >= 0) && !isalnum(character1 = s1[count_1]))
        {
            continue;
        }

        while((--count_2 > 0) && !isalnum(character2 = s2[count_2]))
        {
            continue;
        }

        if (!isalnum(character1) && !isalnum(character2))
        {
            return 0;
        }
        else if (!isalnum(character1))
        {
            return -1;
        }
        else if (!isalnum(character2))
        {
            return 1;
        }

        if (tolower(character1) < tolower(character2))
        {
            return -1;
        }
        else if (tolower(character2) < tolower(character1))
        {
            return 1;
        }
    } while (count_1 >= 0 && count_2 >= 0);

    return 0;
}

int CompareStringModified(const char *s1, const char *s2)
{
    ASSERT(s1 != NULL);
    ASSERT(s2 != NULL);

    size_t index1 = 0;
    size_t index2 = 0;

    char character1 = s1[index1];
    char character2 = s2[index2];

    while (true)
    {
        while(!isalnum(character1) && (character1 !='\n'))
        {
            index1++;
            character1 = s1[index1];
        }

        while(!isalnum(character2) && (character2 !='\n'))
        {
            index2++;
            character2 = s2[index2];
        }

        if ((character1 == '\n') && (character2 == '\n'))
        {
            return 0;
        }
        else if ((character1 == '\n') || tolower(character1) < tolower(character2))
        {
            return -1;
        }
        else if ((character2 == '\n') || tolower(character2) < tolower(character1))
        {
            return 1;
        }
        else
        {
            index1++;
            index2++;
            character1 = s1[index1];
            character2 = s2[index2];
        }
    }
}

