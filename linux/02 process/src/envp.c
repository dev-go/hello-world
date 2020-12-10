// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern char **environ;

void show_envp();

int main(int argc, char const *argv[])
{
    show_envp();
    return EXIT_SUCCESS;
}

void show_envp()
{
    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("[%d]  %s\n\n", i, environ[i]);
    }
}