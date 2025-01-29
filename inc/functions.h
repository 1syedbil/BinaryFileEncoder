#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ERROR_EXIT            -1
#define HELP                   1
#define FILE_TO_FILE           2
#define FILE_TO_SREC_FILE      3
#define FILE_TO_DEF_FILE       4
#define FILE_TO_DEF_SREC_FILE  5
#define STDIN_TO_FILE          6
#define STDIN_TO_SREC_FILE     7
#define STDIN_TO_STDOUT        8

int validateCmdLine(char* argv[]);

#endif
