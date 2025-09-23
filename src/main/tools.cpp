#include "tools.h"

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int
EnterData(char** array_of_pointers,
          size_t str_count,
          char*  input_buffer)
{
    ASSERT(array_of_pointers != NULL);
    ASSERT(input_buffer != NULL);

    char* current_pointer = input_buffer;
    size_t counter = 0;

    while ((counter < str_count) && (*current_pointer != '\0'))
    {
        array_of_pointers[counter] = current_pointer;
        counter++;
        current_pointer = strchr(current_pointer, '\n') + 1;
    }

    return 0;
}

size_t
CountCharInStr(char        character,
               const char* str)
{
    ASSERT(str != NULL);

    const char* pointer_to_char = str;
    size_t count = 0;

    while (*pointer_to_char != '\0')
    {
        pointer_to_char = strchr(pointer_to_char, character);
        if (pointer_to_char == NULL)
        {
            break;
        }
        count++;
        pointer_to_char++;
    }

    return count;
}

int
PrintLogo(void)
{
    printf(
    "▒█████   ███▄    █ ▓█████   ▄████  ██▓ ███▄    █ \n"
    "▒██▒  ██▒ ██ ▀█   █ ▓█   ▀  ██▒ ▀█▒▓██▒ ██ ▀█   █ \n"
    "▒██░  ██▒▓██  ▀█ ██▒▒███   ▒██░▄▄▄░▒██▒▓██  ▀█ ██▒\n"
    "▒██   ██░▓██▒  ▐▌██▒▒▓█  ▄ ░▓█  ██▓░██░▓██▒  ▐▌██▒\n"
    "░ ████▓▒░▒██░   ▓██░░▒████▒░▒▓███▀▒░██░▒██░   ▓██░\n"
    "░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░░ ▒░ ░ ░▒   ▒ ░▓  ░ ▒░   ▒ ▒ \n"
    "   ░ ▒ ▒░ ░ ░░   ░ ▒░ ░ ░  ░  ░   ░  ▒ ░░ ░░   ░ ▒░\n"
    "░ ░ ░ ▒     ░   ░ ░    ░   ░ ░   ░  ▒ ░   ░   ░ ░ \n"
    "░ ░           ░    ░  ░      ░  ░           ░ \n");

    return 1;
}
