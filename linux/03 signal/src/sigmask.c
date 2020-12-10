// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

void handle_signal(int signo)
{
    printf("!!! receive signal: signo = %d\n", signo);
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s\n", strerror(errno));
        return errno;
    }

    sigset_t mask_set;
    sigemptyset(&mask_set);
    sigaddset(&mask_set, SIGINT);
    if (sigprocmask(SIG_BLOCK, &mask_set, NULL) < 0)
    {
        fprintf(stderr, "sigprocmask failed: %s\n", strerror(errno));
        return errno;
    }

    sleep(20);

    sigset_t pend_set;
    sigemptyset(&pend_set);
    if (sigpending(&pend_set) < 0)
    {
        fprintf(stderr, "sigpending failed: %s\n", strerror(errno));
        return errno;
    }
    if (sigismember(&pend_set, SIGINT) == 1)
    {
        printf("SIGINT is pending\n");
    }
    else
    {
        printf("SIGINT is not pending\n");
    }

    if (sigprocmask(SIG_UNBLOCK, &mask_set, NULL) < 0)
    {
        fprintf(stderr, "sigprocmask failed: %s\n", strerror(errno));
        return errno;
    }
    printf("SIGINT is unblock now!\n");

    sleep(20);

    printf("bye!\n");

    return EXIT_SUCCESS;
}