#ifndef SIMPLE_PARSER_H
#define SIMPLE_PARSER_H

#include "error.h"

enum ErrorTypes ReadFlags(int argc, char** argv, char** input_file, char** output_file);

#endif
