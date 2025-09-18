#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <sys/stat.h>

#include "tools.h"
#include "sorting.h"
#include "compare_functions.h"

const char * INPUT_NAME = "input1.txt";
const char * OUTPUT_NAME = "output.txt";

int main(void)
{
    FILE* file_input = fopen(INPUT_NAME, "r");
    FILE* file_output = fopen(OUTPUT_NAME, "w");

    struct stat file_stat = {0};
    stat(INPUT_NAME, &file_stat);
    size_t char_number = (size_t) (file_stat.st_size + 1); //узнать количество чаров

    char* input_buffer = MakeBuffer(char_number, file_input);

    size_t str_count = CountCharInStr('\n', input_buffer);
    char** array_of_pointers =(char**) calloc(str_count, sizeof(char*));

    EnterData(array_of_pointers, &str_count, input_buffer);

    QSort(array_of_pointers, str_count, CompareStringModified);

    for (size_t i = 0; i < str_count; i++)
    {
        char* pointer = array_of_pointers[i];
        while (*pointer != '\n')
        {
            fputc(*pointer, file_output);
            pointer++;
        }
        fputc(*pointer, file_output);
    }

    fclose(file_output);
    fclose(file_input);

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
