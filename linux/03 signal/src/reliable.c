// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>

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

    if (signal(SIGTSTP, &handle_signal) != NULL)
    {
        fprintf(stderr, "[%d] signal failed: %s, signo = %d\n", getpid(), strerror(errno), SIGTERM);
        return errno;
    }

    for (int i = 0; i < 1 << 10; i++)
    {
        printf("[%d] i = %d\n", getpid(), i);
        sleep(1);
    }

    return EXIT_SUCCESS;
}