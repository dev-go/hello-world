// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>

atomic_long c1 = 0;

int64_t c2;

int th_atomic_type(void *p);

int th_atomic_func(void *p);

typedef struct
{
    atomic_flag f;
    int64_t n;
} demo_t;

demo_t *create_demo();

void delete_demo(demo_t *d);

int64_t get_demo(demo_t *d);

int64_t set_demo(demo_t *d, int64_t n);

int th_demo(void *);

int main(int argc, char const *argv[])
{
    thrd_t t1;
    thrd_create(&t1, &th_atomic_type, NULL);

    thrd_t t2;
    thrd_create(&t2, &th_atomic_type, NULL);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    printf("----------------------------\n");

    thrd_t t3;
    thrd_create(&t3, &th_atomic_func, NULL);

    thrd_t t4;
    thrd_create(&t4, &th_atomic_func, NULL);

    thrd_join(t3, NULL);
    thrd_join(t4, NULL);

    printf("----------------------------\n");

    demo_t *d = create_demo();
    thrd_t t5;
    int64_t n5 = 888;
    void *args5[] = {d, &n5};
    thrd_create(&t5, &th_demo, (void *)args5);

    thrd_t t6;
    int64_t n6 = 666;
    void *args6[] = {d, &n6};
    thrd_create(&t6, &th_demo, (void *)args6);

    thrd_join(t5, NULL);
    thrd_join(t6, NULL);

    return EXIT_SUCCESS;
}

int th_atomic_type(void *p)
{
    struct timespec t = {.tv_sec = 0, .tv_nsec = 100000000};
    for (int64_t i = 0; i < 10; ++i)
    {
        c1 += i;
        printf("thread#%ld c1 = %ld\n", thrd_current(), c1);
        thrd_sleep(&t, NULL);
    }
    printf("thread#%ld >>> c1 = %ld\n", thrd_current(), c1);
    return thrd_success;
}

int th_atomic_func(void *p)
{
    struct timespec t = {.tv_sec = 0, .tv_nsec = 100000000};
    for (int64_t i = 0; i < 10; ++i)
    {
        atomic_fetch_add(&c2, i);
        printf("thread#%ld c2 = %ld\n", thrd_current(), atomic_load(&c2));
        thrd_sleep(&t, NULL);
    }
    printf("thread#%ld >>> c2 = %ld\n", thrd_current(), atomic_load(&c2));
    return thrd_success;
}

demo_t *create_demo()
{
    demo_t *ret = (demo_t *)malloc(sizeof(demo_t));
    ret->n = 0;
    atomic_flag_clear(&(ret->f));
    return ret;
}

void delete_demo(demo_t *d)
{
    free(d);
}

int64_t get_demo(demo_t *d)
{
    for (; atomic_flag_test_and_set(&(d->f));)
    {
        printf("#%ld get: wait to unlock ...\n", thrd_current());
    }
    struct timespec t = {.tv_sec = 0, .tv_nsec = 1000000};
    thrd_sleep(&t, NULL);
    int64_t ret = d->n;
    atomic_flag_clear(&(d->f));
    return ret;
}

int64_t set_demo(demo_t *d, int64_t n)
{
    for (; atomic_flag_test_and_set(&(d->f));)
    {
        printf("#%ld set: wait to unlock ...\n", thrd_current());
    }
    struct timespec t = {.tv_sec = 0, .tv_nsec = 1000000};
    thrd_sleep(&t, NULL);
    int64_t ret = d->n;
    d->n = n;
    atomic_flag_clear(&(d->f));
    return ret;
}

int th_demo(void *p)
{
    void **args = (void **)p;
    demo_t *d = (demo_t *)args[0];
    int64_t *n = (int64_t *)*(args + 1);
    printf("#%ld: d.n: prev=%ld\n", thrd_current(), get_demo(d));
    printf("#%ld: d.n: old=%ld\n", thrd_current(), set_demo(d, *n));
    printf("#%ld: d.n: now=%ld\n", thrd_current(), get_demo(d));
    return thrd_success;
}