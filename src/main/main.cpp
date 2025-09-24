#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "assert.h"
#include "compare_functions.h"
#include "tools.h"
#include "logger.h"
#include "read_print_file.h"
#include "sorting.h"
#include "simple_parser.h"
#include "error.h"

int
main(int          argc,
     const char* const* argv)
{
    LOGSHIT(DETALIZATION_LEVEL_DEBUG, "Program started");

    const char*  input_name = NULL;
    const char*  output_name = NULL;
    char*  input_buffer = NULL; //REVIEW - можно сделать стракт в будущем
    char** array_of_pointers = NULL;
    size_t str_count = 0;

    PrintLogo();

    LOGSHIT(DETALIZATION_LEVEL_DEBUG, "Program started reading flags.");
    CheckError(ReadFlags(argc, argv, &input_name, &output_name));

    LOGSHIT(DETALIZATION_LEVEL_DEBUG, "Program started reading file.");
    CheckError(ReadFile(&input_buffer, &array_of_pointers, &str_count, input_name));

    LOGSHIT(DETALIZATION_LEVEL_DEBUG, "Program started sorting.");
    QSort(array_of_pointers, str_count, CompareStringReversed);


    LOGSHIT(DETALIZATION_LEVEL_DEBUG, "Program started started writing to file.");
    CheckError(WriteInFile(array_of_pointers, str_count, output_name));

    free(array_of_pointers);
    free(input_buffer);

    LOGSHIT(DETALIZATION_LEVEL_DEBUG, "Program ended successful");
    return 0;
}

    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    // long delta_us = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec)/1000000;
    // printf("Sorting time = %ld ms\n", delta_us);
