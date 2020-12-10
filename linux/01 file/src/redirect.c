// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fd_out = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd_out < 0)
    {
        fprintf(stderr, "open %s failed: %s\n", argv[1], strerror(errno));
        return errno;
    }
    // TODO: close(fd_out);

    if (dup2(fd_out, STDOUT_FILENO) < 0)
    {
        fprintf(stderr, "dup2 failed: %s\n", strerror(errno));
        close(fd_out);
        return errno;
    }

    fprintf(stdout, "Hello, C!\n");
    fprintf(stdout, "Hello, Linux!\n");

    close(fd_out);
    return EXIT_SUCCESS;
}