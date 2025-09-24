#include <simple_parser.h>

#include <stdlib.h>

#include "assert.h"
#include "error.h"
#include "logger.h"

enum ErrorTypes
ReadFlags(int    argc,
          const char* const* argv,
          const char** input_name,
          const char** output_name)
{
    ASSERT(argv != NULL);
    ASSERT(input_name != NULL);
    ASSERT(output_name != NULL);

    if (argc < 3)
    {
        LOGSHIT(DETALIZATION_LEVEL_ERROR, "Input error was occupied in %d", __LINE__);
        return INPUT_ERROR;
    }

    (*input_name) = argv[1];
    (*output_name) = argv[2];

    return SUCCESS;
}
