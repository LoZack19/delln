#ifndef FILELIB_H
#define FILELIB_H

#include <stdio.h>

#define FILE_SIZE   0x4000
#define STR_SIZE    0x400

void empty(char* buffer, int size);
char* loadfile(FILE* File);
char* delline(char* buffer, int line, char fs);
char* selline(char* buffer, int line, char fs);
int savebuffer(FILE* File, char* buffer);

#endif