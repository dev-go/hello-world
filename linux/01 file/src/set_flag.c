// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include "file_io.h"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file> <msg>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd < 0)
    {
        fprintf(stderr, "open %s failed: %s\n", argv[1], strerror(errno));
        return errno;
    }
    // TODO: close(fd);
    int set_result = set_flag(fd, O_WRONLY | O_CREAT | O_APPEND);
    if (set_result != 0)
    {
        fprintf(stderr, "set flag failed: %s\n", strerror(set_result));
        close(fd);
        return set_result;
    }

    int msg_len = strlen(argv[2]);
    if (write(fd, argv[2], msg_len) != msg_len)
    {
        fprintf(stderr, "write failed: %s, file = %s, msg = %s\n", strerror(errno), argv[1], argv[2]);
        close(fd);
        return errno;
    }

    close(fd);
    return EXIT_SUCCESS;
}