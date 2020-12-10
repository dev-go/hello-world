// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void *th_start_func(void *arg)
{
    printf("C\n");
    printf("Go\n");
    printf("Linux\n");

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t th_id;
    pthread_attr_t th_attr;
    pthread_attr_init(&th_attr);
    pthread_attr_setdetachstate(&th_attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_setscope(&th_attr, PTHREAD_SCOPE_SYSTEM);
    pthread_create(&th_id, &th_attr, &th_start_func, NULL);
    pthread_exit(0);
    return EXIT_SUCCESS;
}