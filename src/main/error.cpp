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
        LogShit(DETALIZATION_LEVEL_ERROR, "Memory error was occupied in %d in %s.", __LINE__, __FILE__);
        printf("Error memory was occupied.\n");
        exit(EXIT_FAILURE);
        break;
    case INPUT_ERROR:
        LogShit(DETALIZATION_LEVEL_ERROR, "Input error was occupied in %d in %s.", __LINE__, __FILE__);
        printf("Incorrect input.\n");
        exit(EXIT_FAILURE);
        break;
    case READ_ERROR:
        LogShit(DETALIZATION_LEVEL_ERROR, "Read error was occupied in %d in %s.", __LINE__, __FILE__);
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
        break;
    case EMPTY_FILE_ERROR:
        LogShit(DETALIZATION_LEVEL_ERROR, "Empty file error was occupied in %d in %s.", __LINE__, __FILE__);
        printf("Input file is empty.\n");
        exit(EXIT_FAILURE);
        break;
    case SYSTEM_ERROR:
        LogShit(DETALIZATION_LEVEL_ERROR, "System error was occupied in %d in %s.", __LINE__, __FILE__);
        printf("System didn't find the file.\n");
        exit(EXIT_FAILURE);
        break;
    default: return 0;
    }

    return 0;
}
