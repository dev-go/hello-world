// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef struct channel_t
{
    void *value;

    pthread_mutex_t locker;
    pthread_cond_t read_cond;
    pthread_cond_t write_cond;
} channel_t;

channel_t *ch;

void *th_start_write(void *arg)
{
    printf("[%ld] write: arg = %p\n", pthread_self(), arg);
    pthread_mutex_lock(&(ch->locker));
    while (ch->value != NULL)
    {
        printf("[%ld] write wait: arg = %p\n", pthread_self(), arg);
        pthread_cond_wait(&(ch->write_cond), &(ch->locker));
        printf("[%ld] write wakeup: arg = %p\n", pthread_self(), arg);
    }
    ch->value = arg;
    pthread_cond_signal(&(ch->read_cond));
    pthread_mutex_unlock(&(ch->locker));
    return NULL;
}

void *th_start_read(void *arg)
{
    printf("[%ld] read\n", pthread_self());
    pthread_mutex_lock(&(ch->locker));
    while (ch->value == NULL)
    {
        printf("[%ld] read wait\n", pthread_self());
        pthread_cond_wait(&(ch->read_cond), &(ch->locker));
        printf("[%ld] read wakeup\n", pthread_self());
    }
    void *ret = ch->value;
    ch->value = NULL;
    pthread_cond_signal(&(ch->write_cond));
    pthread_mutex_unlock(&(ch->locker));
    return ret;
}

int main(int argc, char const *argv[])
{
    ch = calloc(1, sizeof(channel_t));
    pthread_mutex_init(&(ch->locker), NULL);
    pthread_cond_init(&(ch->read_cond), NULL);
    pthread_cond_init(&(ch->write_cond), NULL);

    pthread_t th_id_read;
    pthread_t th_id_write;
    char *data = "hello world";

    pthread_create(&th_id_read, NULL, &th_start_read, NULL);
    sleep(1);
    pthread_create(&th_id_write, NULL, &th_start_write, (void *)data);

    void *value;
    pthread_join(th_id_read, (void **)&value);
    printf("[%ld] value = %s\n", pthread_self(), (char *)value);
    return EXIT_SUCCESS;
}