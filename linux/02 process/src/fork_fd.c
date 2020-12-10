// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("process start ...\n");

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT);
    if (fd < 0)
    {
        fprintf(stderr, "open failed: %s, file = %s\n", strerror(errno), argv[1]);
        return errno;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return errno;
    }
    else if (pid > 0)
    {
        // 父进程
        char *msg = "abcdefg";
        if (write(fd, msg, strlen(msg)) != strlen(msg))
        {
            fprintf(stderr, "[P]write failed: %s\n", strerror(errno));
            return errno;
        }
        if (lseek(fd, 10L, SEEK_END) < 0)
        {
            fprintf(stderr, "[P]lseek failed: %s\n", strerror(errno));
            return errno;
        }
        printf("[P]catch child process exit: cpid = %d\n", wait(NULL));
        printf("[C] over\n");
    }
    else
    {
        // 子进程
        sleep(1);
        char *msg = "123456789";
        if (write(fd, msg, strlen(msg)) != strlen(msg))
        {
            fprintf(stderr, "[C]write failed: %s\n", strerror(errno));
            return errno;
        }
        printf("[C] over\n");
    }
    close(fd);
    printf("process finish\n");
    return EXIT_SUCCESS;
}