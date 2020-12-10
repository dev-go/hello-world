// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/*
int link(const char *oldpath, const char *newpath);
   –参数*oldpath：已有的文件路径。
   –参数*newpath：新建的硬链接文件路径。
   –返回值：成功返回0，错误返回-1。

int symlink(const char *oldpath, const char *newpath);     
     –参数*oldpath：已有的文件路径
     –参数*newpath：新建的符号链接文件路径
     –返回值：成功返回0，错误返回-1

int unlink(const char *pathname);
    –参数*pathname：链接文件的路径
    –返回值：成功返回0，错误返回-1
    – unlink指向软链接，删除软链接；指向最后一个硬链接，相当于删除文件
*/

/*
int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <src> <des>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (access(argv[1], F_OK) != 0)
    {
        fprintf(stderr, "access failed: %s, src = %s\n", strerror(errno), argv[1]);
        return errno;
    }
    if (symlink(argv[1], argv[2]) < 0)
    {
        fprintf(stderr, "symlink failed: %s\n", strerror(errno));
        return errno;
    }

    int fd = open(argv[2], O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: close(fd);
    int const BUF_LEN = 1 << 12;
    char buf[BUF_LEN];
    int byte_count;
    for (;;)
    {
        if ((byte_count = read(fd, buf, sizeof(char) * BUF_LEN)) > 0)
        {
            if (write(STDOUT_FILENO, buf, byte_count) != byte_count)
            {
                fprintf(stderr, "write failed: %s\n", strerror(errno));
                break;
            }
        }
        else if (byte_count == 0)
        {
            break;
        }
        else
        {
            fprintf(stderr, "read failed: %s\n", strerror(errno));
            break;
        }
    }
    close(fd);

    printf("==========================\n");

    memset(&buf, 0, BUF_LEN);
    int size = readlink(argv[2], buf, sizeof(char) * BUF_LEN);
    if (size < 0)
    {
        fprintf(stderr, "readlink failed: %s\n", strerror(errno));
        return errno;
    }
    fprintf(stdout, "--> size = \n%d\n--> content = \n%s\n", size, buf);

    return EXIT_SUCCESS;
}
*/

int main(int argc, char const *argv[])
{
    char *origin = "hi.txt";
    char *new = "hi_link.txt";
    if (link(origin, new) != 0)
    {
        fprintf(stderr, "link failed: %s, origin = %s, new = %s\n", strerror(errno), origin, new);
        return errno;
    }
    sleep(20);
    if (unlink(origin) != 0)
    {
        fprintf(stderr, "unlink failed: %s, origin = %s\n", strerror(errno), origin);
        return errno;
    }
    return EXIT_SUCCESS;
}
