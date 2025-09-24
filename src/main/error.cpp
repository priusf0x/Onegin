#include "error.h"

#include <stdio.h>
#include <stdlib.h>

#include "logger.h"

int
CheckError(enum ErrorTypes return_value)
{
    switch(return_value)
    {
    case SUCCESS:
        break;
    case MEMORY_ERROR:
        LOGSHIT(DETALIZATION_LEVEL_ERROR, "Memory error was occupied");
        printf("Error memory was occupied.\n");
        exit(MEMORY_ERROR);
        break;
    case INPUT_ERROR:
        LOGSHIT(DETALIZATION_LEVEL_ERROR, "Input error was occupied");
        printf("Incorrect input.\n");
        exit(INPUT_ERROR);
        break;
    case READ_ERROR:
        LOGSHIT(DETALIZATION_LEVEL_ERROR, "Read error was occupied");
        printf("Unable to read file.\n");
        exit(READ_ERROR);
        break;
    case EMPTY_FILE_ERROR:
        LOGSHIT(DETALIZATION_LEVEL_ERROR, "Empty file error was occupied");
        printf("Input file is empty.\n");
        exit(EMPTY_FILE_ERROR);
        break;
    case SYSTEM_ERROR:
        LOGSHIT(DETALIZATION_LEVEL_ERROR, "System error was occupied");
        printf("System didn't find the file.\n");
        exit(SYSTEM_ERROR);
        break;
    default: return 0;
    }

    return 0;
}
