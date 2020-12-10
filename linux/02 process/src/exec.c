// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

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
//         char *argv[] = {"cat", "/etc/hosts", NULL};
//         char *envp[] = {"PATH = /bin", "SHELL = bash", NULL};
//         sleep(10);
//         int ret = execve("/bin/cat", argv, envp);
//         printf("[C] ret = %d\n", ret);
//     }
//     else
//     {
//         // 父进程
//         printf("[P] cpid = %d\n", pid);
//         printf("[P] receive child process exit: cpid = %d\n", wait(NULL));
//     }

//     return EXIT_SUCCESS;
// }

// void exec_bash(char *cmd)
// {
//     printf("[%d] exec_bash start: cmd = %s\n", getpid(), cmd);
//     pid_t pid = fork();
//     if (pid < 0)
//     {
//         fprintf(stderr, "fork failed: %s\n", strerror(errno));
//         return;
//     }
//     else if (pid == 0)
//     {
//         // child process
//         int ret = system(cmd);
//         printf("[C: %d] system exit: ret = %d, cmd = %s\n", getpid(), ret, cmd);
//     }
//     else
//     {
//         // parent process
//         pid = wait(NULL);
//         printf("[P: %d] receive child exit signal: pid = %d\n", getpid(), pid);
//     }
//     printf("[%d] exec_bash finished!\n", getpid());
//     return;
// }

// int main(int argc, char const *argv[])
// {
//     exec_bash("cat /etc/hosts");
//     printf("[%d] main finished!\n", getpid());
//     return EXIT_SUCCESS;
// }

void exec_bash(char *cmd)
{
    printf("[%d] exec_bash start: cmd = %s\n", getpid(), cmd);
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return;
    }
    else if (pid == 0)
    {
        // child process
        printf("[C: %d] cmd: %s\n", getpid(), cmd);
        int ret = execl("/bin/bash", "bash", "-c", cmd, NULL);
        printf("[C: %d] system exit: ret = %d, cmd = %s\n", getpid(), ret, cmd);
    }
    else
    {
        // parent process
        pid = wait(NULL);
        printf("[P: %d] receive child exit signal: pid = %d\n", getpid(), pid);
    }
    printf("[%d] exec_bash finished!\n", getpid());
    return;
}

int main(int argc, char const *argv[])
{
    exec_bash("cat /etc/hosts");
    printf("[%d] main finished!\n", getpid());
    return EXIT_SUCCESS;
}
