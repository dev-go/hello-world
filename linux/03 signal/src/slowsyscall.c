// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

void handle_signal(int signo)
{
    printf("[%d] handle signal: signo = %d\n", getpid(), signo);
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, &handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s, signo = %d\n", strerror(errno), SIGINT);
        return errno;
    }

    int const LEN = 1 << 12;
    char buffer[LEN];
    int bytes = read(STDIN_FILENO, buffer, LEN * sizeof(char));
    if (bytes < 0)
    {
        fprintf(stderr, "read failed: %s\n", strerror(errno));
        return errno;
    }

    if (write(STDOUT_FILENO, buffer, bytes) != bytes)
    {
        fprintf(stderr, "write failed: %s\n", strerror(errno));
        return errno;
    }

    return EXIT_SUCCESS;
}