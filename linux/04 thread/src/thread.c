// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

typedef struct th_arg_t
{
    int64_t from;
    int64_t to;
} th_arg_t;

void *th_start_func(void *);

int main(int argc, char const *argv[])
{
    pthread_t th_id1;
    th_arg_t th_arg1 = {.from = 0, .to = 100};
    pthread_t th_id2;
    th_arg_t th_arg2 = {.from = 100, .to = 200};

    pthread_create(&th_id1, NULL, &th_start_func, &th_arg1);
    pthread_create(&th_id2, NULL, &th_start_func, &th_arg2);

    int64_t *th_ret1 = NULL;
    int64_t *th_ret2 = NULL;

    pthread_join(th_id1, (void **)&th_ret1);
    pthread_join(th_id2, (void **)&th_ret2);

    printf("[%ld] *th_ret1 = %ld\n", pthread_self(), *th_ret1);
    printf("[%ld] *th_ret2 = %ld\n", pthread_self(), *th_ret2);
    printf("[%ld] sum = %ld\n", pthread_self(), (*th_ret1) + (*th_ret2));

    return EXIT_SUCCESS;
}

void *th_start_func(void *arg)
{
    th_arg_t *th_arg = (th_arg_t *)arg;
    int64_t *ret = calloc(1, sizeof(int64_t));
    for (int64_t i = th_arg->from; i < th_arg->to; i++)
    {
        *ret += i;
        printf("[%ld] i = %ld, *ret = %ld\n", pthread_self(), i, *ret);
        usleep(10);
    }
    return (void *)ret;
}