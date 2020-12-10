// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "file_io.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0)
    {
        fprintf(stderr, "open %s failed: %s\n", argv[1], strerror(errno));
        return errno;
    }
    // TODO: close(fd_src);
    int result = copy(fd_src, STDOUT_FILENO);
    if (result != 0)
    {
        fprintf(stderr, "copy failed: %s\n", strerror(result));
        close(fd_src);
        return result;
    }
    return EXIT_SUCCESS;
}