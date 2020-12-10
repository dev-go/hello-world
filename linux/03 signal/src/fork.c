// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void handle_signal(int signo)
{
    printf("[%d] receive signal: signo = %d\n", getpid(), signo);
    sleep(10);
}

int main(int argc, char const *argv[])
{

    if (signal(SIGINT, &handle_signal) != NULL)
    {
        fprintf(stderr, "[%d] signal failed: %s, signo = %d\n", getpid(), strerror(errno), SIGINT);
        return errno;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "[%d] fork failed: %s\n", getpid(), strerror(errno));
        return errno;
    }
    else if (pid == 0)
    {
        // child process
        printf("[%d] child process: ppid = %d\n", getpid(), getppid());
    }
    else
    {
        // parent process
        printf("[%d] parent process: cpid = %d\n", getpid(), pid);
    }

    for (int i = 0; i < __INT_MAX__; i++)
    {
        printf("[%d] i = %d\n", getpid(), i);
        sleep(1);
    }

    return EXIT_SUCCESS;
}