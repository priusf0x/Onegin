#include "main.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "help.h"
#include "not_stdio.h"

int main(void)
{
    size_t str_count = CountStrNumber(OpenSafely(INPUT_NAME, "r"));

    char** array_of_pointers =(char**) calloc(str_count, sizeof(char*));

    EnterData(array_of_pointers, str_count, OpenSafely(INPUT_NAME, "r"));

    printf("%d", str_cmp("meow", "bar"));//array_of_pointers[2]);

    FreeData(array_of_pointers, str_count);

    CloseSafely(OpenSafely(INPUT_NAME, "r"));

    return 0;
}
