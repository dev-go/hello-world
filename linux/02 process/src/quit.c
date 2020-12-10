// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file> {return | exit | _exit}\n", argv[0]);
        return EXIT_FAILURE;
    }

    char const *file = argv[1];
    FILE *f = fopen(file, "w");
    if (f == NULL)
    {
        fprintf(stderr, "fopen failed: %s, file = %s\n", strerror(errno), file);
        return errno;
    }
    char const *msg = "Hello, World!";
    fprintf(f, "%s", msg);

    char const *cmd = argv[2];
    if (strcmp(cmd, "return") == 0)
    {
        return 0;
    }
    if (strcmp(cmd, "exit") == 0)
    {
        exit(0);
    }
    if (strcmp(cmd, "_exit") == 0)
    {
        _exit(0);
    }
    fprintf(stderr, "unknown cmd: cmd = %s\n", cmd);

    return EXIT_SUCCESS;
}