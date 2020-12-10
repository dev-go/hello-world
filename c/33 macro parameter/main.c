// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define OUT(NAME)                           \
    {                                       \
        printf("#NAME = %s\n", #NAME);      \
        printf("n##NAME = %ld\n", n##NAME); \
    }

typedef struct
{
    char *name;
    void (*func)();
} cmd;

#define NEW_CMD(NAME)     \
    {                     \
#NAME, NAME##_cmd \
    }

void quit_cmd()
{
    printf("Quit!!!\n");
    return;
}

void help_cmd()
{
    printf("Help!!!\n");
    return;
}

int main(int argc, char const *argv[])
{
    int64_t n1 = 33;
    int64_t n2 = 57;
    int64_t n3 = 85;
    OUT(1);
    OUT(2);
    OUT(3);

    cmd cmds[] = {NEW_CMD(quit), NEW_CMD(help)};
    for (int i = 0; i < sizeof(cmds) / sizeof(cmd); ++i)
    {
        cmd c = cmds[i];
        printf("c.name: %s\n", c.name);
        c.func();
    }

    return EXIT_SUCCESS;
}