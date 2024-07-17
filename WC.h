#ifndef TESTWC_H
#define TESTWC_H

//const char *programName;


#include <stdio.h>

void print_help(FILE *stream, int exitCode, const char *programName);
int maxArray(int *array, int size);
int charMax(FILE *stream);
int countLine(FILE *stream);
int countWord(FILE *stream);
int maxCharLine(FILE *stream);


#endif