#ifndef NOT_STDIO
#define NOT_STDIO

#include <stdio.h>

//int MyWrite(const void* buf);
int put_s(const char * string);
const char * str_chr(const char * string, int target_symbol);
size_t str_len(const char * string);
char * str_cpy(char* dest, const char* src);
char * strn_cpy(char* dest, const char* src, size_t count);
char * str_cat(char * destptr, const char * srcptr);
char * strn_cat(char * destptr, const char * srcptr, size_t count);
char * f_gets(char *str, int num, FILE *stream);
char * str_dup(const char *str);
ssize_t get_line(char ** lineptr, size_t * n, FILE * stream);
int str_cmp(const char *s1, const char *s2);

#endif
