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
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return errno;
    }
    else if (pid == 0)
    {
        // 子进程
        for (int i = 60; i >= 0; i--)
        {
            sleep(1);
            printf("[C] I'm child process, pid = %d, ppid = %d\n", getpid(), getppid());
        }
    }
    else
    {
        // 父进程
        for (int i = 10; i >= 0; i--)
        {
            sleep(1);
            printf("[P] I'm parent process, pid = %d\n", getpid());
        }
    }
    return EXIT_SUCCESS;
}

// int main(int argc, char const *argv[])
// {
//     pid_t pid = fork();
//     if (pid < 0)
//     {
//         fprintf(stderr, "fork failed: %s\n", strerror(errno));
//         return errno;
//     }
//     else if (pid == 0)
//     {
//         // 子进程
//         for (int i = 10; i >= 0; i--)
//         {
//             sleep(1);
//             printf("[C] I'm child process, pid = %d, ppid = %d\n", getpid(), getppid());
//         }
//     }
//     else
//     {
//         // 父进程
//         for (int i = 60; i >= 0; i--)
//         {
//             sleep(1);
//             printf("[P] I'm parent process, pid = %d\n", getpid());
//         }
//     }
//     return EXIT_SUCCESS;
// }