// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char const *file = argv[1];
    struct stat stat_buf;
    if (stat(file, &stat_buf) < 0)
    {
        fprintf(stderr, "stat failed: %s, file = %s\n", strerror(errno), file);
        return errno;
    }
    mode_t mode = stat_buf.st_mode;
    fprintf(stdout, "old: %c%c%c %c%c%c %c%c%c\n",
            (mode & S_IRUSR) ? 'r' : '-',
            (mode & S_IWUSR) ? 'w' : '-',
            (mode & S_IXUSR) ? 'x' : '-',

            (mode & S_IRGRP) ? 'r' : '-',
            (mode & S_IWGRP) ? 'w' : '-',
            (mode & S_IXGRP) ? 'x' : '-',

            (mode & S_IROTH) ? 'r' : '-',
            (mode & S_IWOTH) ? 'w' : '-',
            (mode & S_IXOTH) ? 'x' : '-');

    if (chmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    {
        fprintf(stderr, "chmod failed: %s\n", strerror(errno));
        return errno;
    }

    return EXIT_SUCCESS;
}