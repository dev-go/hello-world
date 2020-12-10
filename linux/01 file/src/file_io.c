// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "file_io.h"

int copy(int fd_src, int fd_des)
{
    int const BUFFER_LEN = 1 << 12;
    char buffer[BUFFER_LEN];
    for (;;)
    {
        int read_bytes = read(fd_src, buffer, sizeof(char) * BUFFER_LEN);
        if (read_bytes < 0)
        {
            fprintf(stderr, "read from src failed: %s\n", strerror(errno));
            return read_bytes;
        }
        if (read_bytes == 0)
        {
            break;
        }

        int write_bytes = write(fd_des, buffer, read_bytes);
        if (write_bytes != read_bytes)
        {
            fprintf(stderr, "write to des failed: %s\n", strerror(errno));
            return write_bytes;
        }
    }
    return 0;
}

int get_size(int fd)
{
    int len = lseek(fd, 0, SEEK_END);
    if (len < 0)
    {
        fprintf(stderr, "lseek failed: %s\n", strerror(errno));
        return errno;
    }
    return len;
}

int set_flag(int fd, int flag)
{
    if (fcntl(fd, F_SETFL, flag) < 0)
    {
        fprintf(stderr, "set flag failed: %s\n", strerror(errno));
        return errno;
    }
    return 0;
}

int add_flag(int fd, int flag)
{
    int old_flag;
    if (old_flag = fcntl(fd, F_GETFD) < 0)
    {
        fprintf(stderr, "get flag failed: %s\n", strerror(errno));
        return errno;
    }
    return set_flag(fd, old_flag | flag);
}

int rm_flag(int fd, int flag)
{
    int old_flag;
    if (old_flag = fcntl(fd, F_GETFD) < 0)
    {
        fprintf(stderr, "get flag failed: %s\n", strerror(errno));
        return errno;
    }

    return set_flag(fd, old_flag | ~flag);
}

int lock_file(int fd, int cmd, int type, int whence, int start, int len)
{
    struct flock locker = {
        .l_type = type,
        .l_whence = whence,
        .l_start = start,
        .l_len = len,
    };
    return fcntl(fd, cmd, &locker);
}