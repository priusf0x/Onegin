#include "compare_functions.h"

#include <assert.h>

#include "string_functions/not_stdio.h"

int str_cmp_reversed(const char *s1, const char *s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    int count_1 = (int) (str_len(s1)), count_2 = (int) (str_len(s2));

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
