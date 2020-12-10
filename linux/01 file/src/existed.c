// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd < 0)
    {
        fprintf(stdout, "%s is existed\n", argv[1]);
        return EXIT_SUCCESS;
    }
    // TODO: close(fd);
    fprintf(stdout, "%s is not existed\n", argv[1]);
    close(fd);
    return EXIT_SUCCESS;
}