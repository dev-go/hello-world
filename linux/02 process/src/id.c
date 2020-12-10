// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    printf("UID: %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    printf("GID: %d\n", getgid());
    printf("EGID: %d\n", getegid());

    return EXIT_SUCCESS;
}