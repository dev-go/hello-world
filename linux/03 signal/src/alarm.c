// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

void handle_signal(int signo)
{
    printf("handle_signal: signo = %d\n", signo);
    sleep(10);
}

int main(int argc, char const *argv[])
{
    if (signal(SIGALRM, &handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s\n", strerror(errno));
        return errno;
    }

    alarm(5);

    for (int i = 0; i < __INT_MAX__; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

    return EXIT_SUCCESS;
}