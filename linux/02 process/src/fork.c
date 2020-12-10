// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    printf("process start ...\n");
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return errno;
    }
    else if (pid > 0)
    {
        // 父进程
        printf("[P] pid = %d, cpid = %d\n", getpid(), pid);
        sleep(1);
    }
    else
    {
        // 子进程
        printf("[C] pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(1);
    }
    printf("process finished\n");
    return EXIT_SUCCESS;
}