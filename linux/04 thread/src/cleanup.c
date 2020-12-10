// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

void th_cleanup_func(void *arg)
{
    char *msg = (char *)arg;
    printf("[%ld] cleanup: msg = %s\n", pthread_self(), msg);
    return;
}

void *th_start_func(void *arg)
{
    int *code = (int *)arg;
    printf("[%ld] th_start_func: *code = %d >\n", pthread_self(), *code);
    pthread_cleanup_push(&th_cleanup_func, "Hello, C!");
    pthread_cleanup_push(&th_cleanup_func, "Hello, Linux!");
    printf("[%ld] th_start_func: *code = %d >>>\n", pthread_self(), *code);
    pthread_cleanup_pop(*code);
    pthread_cleanup_pop(*code);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t th_id1;
    int *arg1 = malloc(sizeof(int));
    *arg1 = 0;

    pthread_t th_id2;
    int *arg2 = malloc(sizeof(int));
    *arg2 = 1;

    pthread_create(&th_id1, NULL, &th_start_func, (void *)arg1);
    pthread_create(&th_id2, NULL, &th_start_func, (void *)arg2);

    int *ret1 = NULL;
    int *ret2 = NULL;

    pthread_join(th_id1, (void **)&ret1);
    pthread_join(th_id2, (void **)&ret2);

    return EXIT_SUCCESS;
}