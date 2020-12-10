// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file> <bytes>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char const *file = argv[1];
    int bytes = 0;
    if (sscanf(argv[2], "%d", &bytes) != 1)
    {
        fprintf(stderr, "convert %s to int failed: %s\n", argv[2], strerror(EINVAL));
        return EINVAL;
    }
    // fprintf(stdout, "%s --> %d\n", argv[2], bytes);
    if (truncate(file, bytes) < 0)
    {
        fprintf(stderr, "truncate failed: %s\n", strerror(errno));
        return errno;
    }
    return EXIT_SUCCESS;
}