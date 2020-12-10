// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_io.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <src> <des>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // open src file
    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0)
    {
        fprintf(stderr, "open src failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: close(fd_src);

    // open dsc file
    int fd_des = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_des < 0)
    {
        fprintf(stderr, "open des failed: %s\n", strerror(errno));
        close(fd_src);
        return errno;
    }
    // TODO: close(fd_des);

    int result = copy(fd_src, fd_des);
    if (result != 0)
    {
        fprintf(stderr, "copy failed: %s\n", strerror(errno));
        close(fd_des);
        close(fd_src);
        return errno;
    }

    close(fd_des);
    close(fd_src);
    return EXIT_SUCCESS;
}
