// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void *th_start_func(void *);

int main(int argc, char const *argv[])
{
    pthread_t th_id;
    pthread_create(&th_id, NULL, &th_start_func, NULL);
    printf("[%ld] thread prepare to exit ...\n", pthread_self());
    pthread_exit(EXIT_SUCCESS);
    printf("[%ld] thread exited: should not show this ...\n", pthread_self());
    return EXIT_SUCCESS;
}

void *th_start_func(void *arg)
{
    printf("[%ld] start ...\n", pthread_self());
    sleep(1);
    printf("[%ld] finish ...\n", pthread_self());
    return NULL;
}