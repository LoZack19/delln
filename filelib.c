#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filelib.h"


void empty(char* buffer, int size)
{
    for(int i = 0; i < size; i++)
        buffer[i] = 0;
}

/* File needs to be opened in read mode*/
char* loadfile(FILE* File)
{
    char* buffer = (char*) malloc(FILE_SIZE);
    char* str = NULL;
    size_t size = 0;

    empty(buffer, strlen(buffer));

    while(!size && getline(&str, &size, File) != EOF)
    {
        if(strlen(buffer) + size < FILE_SIZE)
        {
            strcat(buffer, str);
            size = 0;
        }
        else
            size = -1;
        
        free(str);
    }
    
    if(!~size)
    {
        fputs("Failed to read the file into the buffer: Too large File\n", stderr);
        free(buffer);
        return NULL;
    }

    return buffer;    
}


/* 
    The count of the lines starts from 0
    fs = field separator
*/
char* delline(char* buffer, int line, char fs)
{
    if(!buffer || !strlen(buffer))
        return NULL;
    
    int cnt = 0, tmp = 0;
    char* newbuf = (char*) malloc(FILE_SIZE);
    
    int i, size;
    for(i = 0, size = strlen(buffer); i < size; i++)
    {
        if(cnt != line)
            newbuf[i - tmp] = buffer[i];
        else
            ++tmp;

        if(buffer[i] == '\n')
            ++cnt;
    }
    newbuf[i - tmp] = 0;

    return newbuf;
}

/* 
    The count of the lines starts from 0
    fs = field separator
*/
char* selline(char* buffer, int line, char fs)
{
    if(!buffer || !strlen(buffer))
        return NULL;
    
    int cnt = 0, tmp = 0;
    char* newbuf = (char*) malloc(FILE_SIZE);

    int i, size;
    for(i = 0, size = strlen(buffer); i < size; i++)
    {
        if(cnt == line)
            newbuf[i - tmp] = buffer[i];
        else
            ++tmp;

        if(buffer[i] == '\n')
            ++cnt;
    }
    newbuf[i - tmp] = 0;

    return newbuf;
}

/* File needs to be opened in write mode*/
int savebuffer(FILE* File, char* buffer)
{
    if(!File || !buffer || !strlen(buffer))
        return -1;
    
    fseek(File, 0, SEEK_SET);
    return fputs(buffer, File);
}