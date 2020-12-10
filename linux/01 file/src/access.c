// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (access(argv[1], R_OK) == 0)
    {
        fprintf(stdout, "%s 可读\n", argv[1]);
    }
    else
    {
        fprintf(stdout, "%s 不可读\n", argv[1]);
    }

    if (access(argv[1], W_OK) == 0)
    {
        fprintf(stdout, "%s 可写\n", argv[1]);
    }
    else
    {
        fprintf(stdout, "%s 不可写\n", argv[1]);
    }

    if (access(argv[1], X_OK) == 0)
    {
        fprintf(stdout, "%s 可执行\n", argv[1]);
    }
    else
    {
        fprintf(stdout, "%s 不可执行\n", argv[1]);
    }

    return EXIT_SUCCESS;
}