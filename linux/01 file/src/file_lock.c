// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "file_io.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file> <msg>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fd = open(argv[1], O_WRONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failed: %s\n", argv[1], strerror(errno));
        return errno;
    }
    // TODO: close(fd);

    WRITE_LOCKW(fd, SEEK_SET, 0, 0);
    if (lseek(fd, 0, SEEK_END) < 0)
    {
        fprintf(stderr, "seek failed: %s\n", strerror(errno));
        close(fd);
        return errno;
    }
    for (int i = 0; i < strlen(argv[2]); i++)
    {
        if (write(fd, (argv[2] + i), 1) != 1)
        {
            fprintf(stderr, "write failed: %s\n", strerror(errno));
            close(fd);
            return errno;
        }
        fprintf(stdout, "[D] <%d> write %c\n", getpid(), *(argv[2] + i));
        sleep(1);
    }
    UN_LOCK(fd, SEEK_SET, 0, 0);
    close(fd);
    return EXIT_SUCCESS;
}