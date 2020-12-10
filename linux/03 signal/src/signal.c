// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void handle_signal(int signo);

int main(int argc, char const *argv[])
{
    __sighandler_t handler = &handle_signal;

    if (signal(SIGINT, handler) != NULL)
    {
        fprintf(stderr, "[%d] signal failed: %s, signo = %d\n", getpid(), strerror(errno), SIGINT);
        return errno;
    }

    if (signal(SIGTERM, handler) != NULL)
    {
        fprintf(stderr, "[%d] signal failed: %s, signo = %d\n", getpid(), strerror(errno), SIGTERM);
        return errno;
    }

    // if (signal(SIGKILL, handler) != NULL)
    // {
    //     fprintf(stderr, "[%d] signal failed: %s, signo = %d\n", getpid(), strerror(errno), SIGTERM);
    //     return errno;
    // }

    for (int i = 0; i < __INT_MAX__; i++)
    {
        printf("[%d] i = %d\n", getpid(), i);
        sleep(1);
    }

    return EXIT_SUCCESS;
}

void handle_signal(int signo)
{
    printf("[%d] receive signal: signo = %d\n", getpid(), signo);
    sleep(10);
}
