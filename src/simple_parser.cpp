#include <simple_parser.h>

#include <stdlib.h>

int ReadFlags(int argc, char **argv, char** input_name, char** output_name)
{
    if (argc < 3)
    {
        return 1;
    }

    (*input_name) = argv[1];
    (*output_name) = argv[2];

    return 0;
}
