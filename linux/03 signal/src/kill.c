// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <assert.h>

void handle_signal(int signo)
{
    printf("### handle_signal; signo = %d\n", signo);
    exit(0);
}

void demo(int m, int n)
{
    assert(m <= n);
    for (int i = m; i < n; i++)
    {
        printf("[%d] i = %d\n", getpid(), i);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, &handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s\n", strerror(errno));
        return errno;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return errno;
    }
    else if (pid == 0)
    {
        // child process
        demo(1, 100);
    }
    else
    {
        // parent process
        kill(pid, SIGINT);
        demo(100, 200);
    }
}