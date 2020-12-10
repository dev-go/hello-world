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
    printf("STDIN_FILENO = %d\n", STDIN_FILENO);
    printf("STDOUT_FILENO = %d\n", STDOUT_FILENO);
    printf("STDERR_FILENO = %d\n", STDERR_FILENO);

    int fd = open("/etc/hosts", O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open file failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: close(fd);
    printf("fd = %d\n", fd);
    close(fd);

    return EXIT_SUCCESS;
}