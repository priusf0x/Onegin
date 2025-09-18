#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "help.h"
#include "not_stdio.h"
#include "sorting.h"
#include "string_functions/not_stdio.h"
#include "compare_functions.h"

const char * INPUT_NAME = "input.txt";
const char * OUTPUT_NAME = "output.txt";

int main(void)
{
    struct timespec start, end;

    FILE* file_input = fopen(INPUT_NAME, "r");
    FILE* file_output = fopen(OUTPUT_NAME, "w");

    assert(file_input != NULL);
    assert(file_output != NULL);

    size_t str_count = CountStrNumber(file_input);
    char** array_of_pointers =(char**) calloc(str_count, sizeof(char*));

    EnterData(array_of_pointers, str_count, file_input);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    QSort(array_of_pointers, str_count, str_cmp_reversed);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    for (size_t i = 0; i < str_count; i++)
    {
        fprintf(file_output, "%s\n", array_of_pointers[i]);
    }

    FreeData(array_of_pointers, str_count);

    fclose(file_output);
    fclose(file_input);

    long delta_us = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec)/1000000;
    printf("Sorting time = %ld ms\n", delta_us);

    return 0;
}
//TODO - функция количества строк

//TODO -stat fstat

//TODO - buffer enter


//TODO - increase sort count

//TODO - add parser logger
