// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void *th_start_func(void *arg)
{
    printf("[%ld] start ...\n", pthread_self());
    sleep(2);
    printf("[%ld] finish ...\n", pthread_self());
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t th_id;

    printf("[%ld] create thread ...\n", pthread_self());

    pthread_create(&th_id, NULL, &th_start_func, NULL);

    sleep(1);

    printf("[%ld] cancel thread ...\n", pthread_self());

    pthread_cancel(th_id);

    printf("[%ld] finish ...\n", pthread_self());

    return EXIT_SUCCESS;
}