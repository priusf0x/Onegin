#ifndef SIMPLE_PARSER_H
#define SIMPLE_PARSER_H

#include "error.h"

enum ErrorTypes ReadFlags(int argc, const char* const* argv, const char** input_file,const char** output_file);

#endif
