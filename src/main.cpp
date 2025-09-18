#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "tools.h"
#include "sorting.h"
#include "compare_functions.h"
#include "read_print_file.h"

const char * INPUT_NAME = "input1.txt";
const char * OUTPUT_NAME = "output.txt";

int main(void)
{
    char* input_buffer = NULL;
    char** array_of_pointers = NULL;
    size_t str_count = 0;

    ReadFile(&input_buffer, &array_of_pointers, &str_count, INPUT_NAME);

    QSort(array_of_pointers, str_count, CompareStringModified);

    FILE* file_output = fopen(OUTPUT_NAME, "w");

    for (size_t i = 0; i < str_count; i++)
    {
        char* pointer = array_of_pointers[i];
        while (*pointer != '\n')
        {
            fputc(*pointer, file_output); // optimize
            pointer++;
        }
        fputc(*pointer, file_output);
    }

    fclose(file_output);

    free(array_of_pointers);
    free(input_buffer);
    return 0;
}

//TODO - increase sort count

//TODO - add parser logger

    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    // clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    // long delta_us = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec)/1000000;
    // printf("Sorting time = %ld ms\n", delta_us);

    // assert(file_input != NULL);
    // assert(file_output != NULL);
