#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "tools.h"
#include "sorting.h"
#include "compare_functions.h"
#include "read_print_file.h"
#include "simple_parser.h"

int main(int argc, char **argv)
{
    char * input_name = NULL;
    char * output_name = NULL;
    char* input_buffer = NULL;
    char** array_of_pointers = NULL;
    size_t str_count = 0;

    ReadFlags(argc, argv, &input_name, &output_name);

    ReadFile(&input_buffer, &array_of_pointers, &str_count, input_name);

    QSort(array_of_pointers, str_count, CompareStringReversed);

    WriteInFile(array_of_pointers, str_count, output_name);

    free(array_of_pointers);
    free(input_buffer);
    return 0;
}

//TODO - increase sort count

//TODO - add parser logger


    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    // long delta_us = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec)/1000000;
    // printf("Sorting time = %ld ms\n", delta_us);

    // assert(file_input != NULL);
    // assert(file_output != NULL);
