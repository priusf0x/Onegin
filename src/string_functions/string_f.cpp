#include "not_stdio.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int MyWrite(const void* buf)
{
    const char * buf_pointer = (const char *) buf;

    if (putc(*buf_pointer, stdout) == EOF)
    {
        return 1;
    }

    return 0;
}

int put_s(const char* string)
{
    char symbol = *string;

    while (symbol != '\0')
    { //fwrite (maybe)
        if (MyWrite(&symbol) != 0) // ONE write
        {
            return EOF;
        }
        string++;
        symbol = * string;
    }

    MyWrite(&"\n");

    return 0;
}

const char* str_chr(const char* string, int target_symbol)
{
    const char *pointer_to_target = string;
    char symbol = *string;

    while ((symbol != target_symbol) && (symbol !='\0'))
    {
        pointer_to_target++;
        symbol = *pointer_to_target;
    }

    if (symbol != target_symbol)
    {
        return NULL;
    }

    return pointer_to_target;
}

size_t str_len(const char* string)
{
    size_t symbol_counter = 0;

    while (* string != '\0')
    {
        symbol_counter++;
        string++;
    }

    return symbol_counter;
}

char * str_cpy(char* dest, const char* src)
{
    assert(dest != NULL);

    int counter = 0;

    while ((dest[counter] = src[counter]) != '\0')
    {
        counter++;
    }

    dest[counter] = '\0';

    return dest;
}

char* strn_cpy(char* dest, const char* src, size_t count)
{
    assert(dest != NULL);

    size_t counter = 0;

    while (((dest[counter] = src[counter]) != '\0') && (counter < count))
    {
        counter++;
    }

    dest[counter] = '\0';

    return dest;
}

char* str_cat(char* destptr, const char* srcptr)
{
    assert(destptr != NULL);

    str_cpy(destptr + str_len(destptr), srcptr);

    return destptr;
}

char* strn_cat(char* destptr, const char* srcptr, size_t count)
{
    assert(destptr != NULL);

    size_t counter = str_len(destptr);

    strn_cpy(destptr + counter, srcptr, count - counter -1);

    return destptr;
}

char* f_gets(char* str, int num, FILE* stream)
{
    assert(str != NULL);
    assert(stream != NULL);

    int counter = 0;
    char character = (char) fgetc(stream);

    while (character != EOF && character != '\n' && counter < num - 1)
    {
        str[counter] = character;
        counter++;
        character = (char) fgetc(stream);
    }

    str[counter] = '\0';

    return str;
}

char* str_dup(const char* str)
{
    char* duplicate = (char*) malloc(sizeof(char) * (str_len(str) + 1)); // calloc

    str_cpy(duplicate, str);

    return duplicate;
}

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
    const int BUFFER_START_SIZE = 8;
    char character = 0;
    ssize_t count = 0;

    assert(lineptr != NULL);
    assert(n != NULL);
    assert(stream != NULL);

    if (*lineptr == NULL)
    {
        if (*n == 0)
        {
            *lineptr = (char*) malloc(BUFFER_START_SIZE * sizeof(char));
            *n = BUFFER_START_SIZE;
        }
        else
        {
            return -1;
        }
    }


    while (((character = (char) fgetc(stream)) != '\n'))
    {
        if ((size_t) count >= *n - 1)
        {
            (*n) *= 2;

            if ((*lineptr = (char*) realloc(*lineptr, *n)) == NULL)
            {
                return -1;
            }
        }

        (*lineptr)[count] = character;

        count++;
    }

    (*lineptr)[count] = '\0';

    return count;
}

int str_cmp(const char *s1, const char *s2)
{
    size_t index = 0;

    assert(s1 != NULL);
    assert (s2 != NULL);

    char character1 = s1[index], character2 = s2[index];

    while (true)
    {
        if ((character1 == '\0') && (character2 == '\0'))
        {
            return 0;
        }
        else if ((character1 == '\0') || character1 < character2)
        {
            return -1;
        }
        else if ((character2 == '\0') || character2 < character1)
        {
            return 1;
        }
        else
        {
            index++;
            character1 = s1[index];
            character2 = s2[index];
        }
    }
}
