#include <simple_parser.h>

#include <stdlib.h>

#include "assert.h"
#include "error.h"

int ReadFlags(int argc, char **argv, char** input_name, char** output_name)
{
    ASSERT(argv != NULL);

    if (argc < 3)
    {
        return INPUT_ERROR;
    }

    (*input_name) = argv[1];
    (*output_name) = argv[2];

    return 0;
}
