// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (setpgid(getpid(), getpid()) < 0)
    {
        fprintf(stderr, "setpgid failed: %s\n", strerror(errno));
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
        printf("[C] pid = %d, ppid = %d, pgid = %d\n", getpid(), getppid(), getpgrp());
        sleep(30);
        printf("[C] process wakeup: pid = %d, ppid = %d, pgid = %d\n", getpid(), getppid(), getpgrp());
    }
    else
    {
        // parent process
        printf("[P] pid = %d, ppid = %d, pgid = %d\n", getpid(), getppid(), getpgrp());
        printf("[P] child process exit: %d\n", wait(NULL));
    }

    return EXIT_SUCCESS;
}