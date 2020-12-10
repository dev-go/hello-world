// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

// int main(int argc, char const *argv[])
// {
//     if (argc != 2)
//     {
//         fprintf(stderr, "Usage: %s <file>\n", argv[0]);
//         return EXIT_FAILURE;
//     }
//     struct stat buf;
//     if (stat(argv[1], &buf) < 0)
//     {
//         fprintf(stderr, "stat failed: %s, file = %s\n", strerror(errno), argv[1]);
//         return errno;
//     }
//     fprintf(stdout, "%s length = %ld\n", argv[1], buf.st_size);
//     return EXIT_SUCCESS;
// }

/*
stat    函数是穿透（追踪）函数，即对软链接文件进行操作时，操作的是链接到的那一个文件，不是软链接文件本身
lstat   函数是不穿透（不追踪）函数，对软链接文件进行操作时，操作的是软链接文件本身
*/

void show_mode(char const *f, mode_t mode);
void show_access(mode_t access);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    struct stat stat_buf;
    if (stat(argv[1], &stat_buf) < 0)
    {
        fprintf(stderr, "stat failed: %s, file = %s\n", strerror(errno), argv[1]);
        return errno;
    }

    show_mode(argv[1], stat_buf.st_mode);
    show_access(stat_buf.st_mode);

    printf("=================================\n");

    memset(&stat_buf, 0, sizeof(struct stat));

    if (lstat(argv[1], &stat_buf) < 0)
    {
        fprintf(stderr, "lstat failed: %s, file = %s\n", strerror(errno), argv[1]);
        return errno;
    }

    show_mode(argv[1], stat_buf.st_mode);
    show_access(stat_buf.st_mode);

    return EXIT_SUCCESS;
}

void show_mode(char const *f, mode_t mode)
{
    if (S_ISREG(mode))
    {
        printf("%s is regular file\n", f);
    }
    if (S_ISDIR(mode))
    {
        printf("%s is directory file\n", f);
    }
    if (S_ISBLK(mode))
    {
        printf("%s is block special file\n", f);
    }
    if (S_ISCHR(mode))
    {
        printf("%s is charactor special file\n", f);
    }
    if (S_ISFIFO(mode))
    {
        printf("%s is named pipe\n", f);
    }
    if (S_ISSOCK(mode))
    {
        printf("%s is socket\n", f);
    }
    if (S_ISLNK(mode))
    {
        printf("%s is symbolic link\n", f);
    }
    return;
}

void show_access(mode_t access)
{
    // owner
    if (access & S_IRUSR)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (access & S_IWUSR)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (access & S_IXUSR)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    // group
    if (access & S_IRGRP)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (access & S_IWGRP)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (access & S_IXGRP)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    // other
    if (access & S_IROTH)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (access & S_IWOTH)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (access & S_IXOTH)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    printf("\n");
    return;
}