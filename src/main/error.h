#ifndef ERROR_H
#define ERROR_H

enum ErrorTypes
{
    SUCCES = 0,
    MEMORY_ERROR =1,
    INPUT_ERROR = 2,
    READ_ERROR = 3,
    EMPTY_FILE_ERROR = 4,
    SYSTEM_ERROR = 5
};

int CheckError(enum ErrorTypes return_value);

#endif
