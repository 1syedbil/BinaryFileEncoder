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
#define STDIN_TO_SREC_STDOUT   9

#define INPUT_NAME             0
#define OUTPUT_NAME            1
#define OUTPUT_ASM_NAME        2
#define OUTPUT_SREC_NAME       3

#define MAX_STRING             255

#define MAX_SREC               43
#define S1_DATA_SIZE           16
#define S0_COUNT               8

int validateCmdLine(int argc, char* argv[]);
int checkSwitch(char* str);
char* getFileName(char* argv[], int choice);
char* retrieveArg(char* argv[], int choice);

void encodeToAsm(char* input, char* output);

void encodeToSrec(char* input, char* output);
char* createS0(char s0[MAX_SREC]);
int getCheckSum(int sum); 

#endif
