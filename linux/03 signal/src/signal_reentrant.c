// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#define LEN 10

int global_arr[LEN];

void demo(int n)
{
    sigset_t set;
    sigfillset(&set);
    if (sigprocmask(SIG_BLOCK, &set, NULL) < 0)
    {
        fprintf(stderr, "sigprocmask failed: %s\n", strerror(errno));
        return;
    }
    int local_arr[LEN];
    for (int i = 0; i < LEN; i++)
    {
        global_arr[i] = n;
        *(local_arr + i) = n;
        sleep(1);
    }

    for (int i = 0; i < LEN; i++)
    {
        if (i == 0)
            printf("global_arr: ");
        printf("%d ", *(global_arr + i));
        if (i == LEN - 1)
            printf("\n");
    }

    for (int i = 0; i < LEN; i++)
    {
        if (i == 0)
            printf("local_arr: ");
        printf("%d ", local_arr[i]);
        if (i == LEN - 1)
            printf("\n");
    }
    if (sigprocmask(SIG_UNBLOCK, &set, NULL) < 0)
    {
        fprintf(stderr, "sigprocmask failed: %s\n", strerror(errno));
        return;
    }
}

void handle_signal(int signo)
{
    printf("handle_signal: start ...\n");
    demo(20);
    printf("handle_signal: finish !\n");
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, &handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s\n", strerror(errno));
        return errno;
    }

    demo(10);

    printf("bye!\n");

    return EXIT_SUCCESS;
}