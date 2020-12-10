// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "file_io.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failed: %s\n", argv[1], strerror(errno));
        return errno;
    }
    // TODO: close(fd);
    int size = get_size(fd);
    if (size < 0)
    {
        fprintf(stderr, "get_size failed: %s\n", strerror(errno));
        close(fd);
        return size;
    }
    printf("%s size = %d\n", argv[1], size);
    close(fd);
    return EXIT_SUCCESS;
}