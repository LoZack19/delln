#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filelib.h"

int streq(char* str1, char* str2, int size)
{
    for(int i = 0; i < size; i++)
        if(str1[i] != str2[i])
            return 0;
    else return 1;
}

void help()
{
    printf("delln - deletes a line from a file\n"
           "delln [FILE] -n [LINE]\n");
}

int main(int argc, char* argv[])
{
    FILE* File;
    char* buffer;
    int line;

    if(argc == 2 && streq(argv[1], "-h", 3) || streq(argv[1], "--help", 7))
    {
        help();
        exit(0);
    }
    else if(argc != 4 || !streq(argv[2], "-n", 3)) {
        fputs("Wrong arguments!\nUse the following systax:\ndelln [FILE] -n [NUMBER]\n", stderr);
        exit(-1);
    }

    File = fopen(argv[1], "r");
    if(!File) {
        fputs("Failed to open this file\n", stderr);
        exit(-1);
    }
    buffer = loadfile(File);
    fclose(File);

    line = atoi(argv[3]);
    --line;
    buffer = delline(buffer, line, '\n');

    File = fopen(argv[1], "w");
    if(!File) {
        fputs("Failed to open this file\n", stderr);
        free(buffer);
        exit(-1);
    }
    savebuffer(File, buffer);
    fclose(File);

    free(buffer);
    return 0;
}