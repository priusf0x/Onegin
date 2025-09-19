#include "error.h"

#include <stdio.h>
#include <stdlib.h>

int CheckError(enum ErrorTypes return_value)
{
    switch(return_value)
    {
    case SUCCES:
        break;
    case MEMORY_ERROR:
        printf("Error memory was occupied.\n");
        exit(EXIT_FAILURE);
        break;
    case INPUT_ERROR:
        printf("Incorrect input.\n");
        exit(EXIT_FAILURE);
        break;
    case READ_ERROR:
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
        break;
    case EMPTY_FILE_ERROR:
        printf("Input file is empty.\n");
        exit(EXIT_FAILURE);
        break;
    case SYSTEM_ERROR:
        printf("System didn't find the file.\n");
        exit(EXIT_FAILURE);
        break;
    default: return 0;
    }

    return 0;
}
