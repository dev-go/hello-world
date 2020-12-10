// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>
#include <time.h>

/*
(1) cnd_t	
        条件变量标识符

(2) int cnd_init(cnd_t* cond)
        初始化新的条件变量。设置 cond 所指的对象为标识该条件变量的值。
    参数:
        cond:   指针，指向要存储条件变量标识符到的对象
    返回值:
        若成功创建条件变量则为 thrd_success 。否则若内存量不足则返回 thrd_nomem ，若出现其他错误则返回 thrd_error 。

(3) int cnd_signal(cnd_t *cond)
        除阻当前在 cond 所指向的条件变量上等待的一个线程。若无线程被阻塞，则不做任何事并返回 thrd_success 。
    参数:
        cond:	指向条件变量的指针
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(4) int cnd_broadcast(cnd_t *cond)
        除阻所有当前在 cond 所指向的条件变量上等待的线程。若无被阻塞的线程，则不做任何事并返回 thrd_success 。
    参数:
        cond:	指向条件变量的指针
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(5) int cnd_wait(cnd_t* cond, mtx_t* mutex)
        原子地解锁 mutex 所指向的互斥，并在 cond 所指向的条件变量上阻塞，直至线程被 cnd_signal 或 cnd_broadcast 发信号，或直至虚假唤醒出现。在此函数返回前，重新锁定该互斥。
        若调用方线程未锁定该互斥，则行为未定义。
    参数:
        cond:	指向要在上面阻塞的条件变量的指针
        mutex:	指向要在阻塞期解锁的互斥的指针
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(6) int cnd_timedwait(cnd_t* restrict cond, mtx_t* restrict mutex, const struct timespec* restrict time_point)
        原子地解锁 mutex 所指向的互斥，并在 cond 所指向的条件变量上阻塞，直到线程被 cnd_signal 或 cnd_broadcast 发信号，或直至抵达 time_point 所指向的基于 TIME_UTC 的时间点，或直至虚假唤醒出现。在函数返回前重新锁定该互斥。
        若调用方线程未锁定该互斥，则行为未定义。
    参数:
        cond:	    指向要在上面阻塞的条件变量的指针
        mutex:	    指向要在阻塞期间解锁的互斥的指针
        time_point:	指向指定等待时限时间的对象的指针
    返回值:
        若成功则为 thrd_success ，若在锁定互斥前抵达时限则为 thrd_timedout ，若出现错误则为 thrd_error 。    

(7) void cnd_destroy(cnd_t* cond)
        销毁 cond 所指向的条件变量。
        若有线程在 cond 上等待，则行为未定义。
    参数:
        cond:	指向要销毁的条件变量的指针
    返回值:
        (无)
*/

typedef struct
{
    void *value;
    mtx_t locker;
    cnd_t read;
    cnd_t write;
} channel_t;

channel_t *create_channel()
{
    channel_t *ch = (channel_t *)malloc(sizeof(channel_t));
    ch->value = NULL;
    mtx_init(&(ch->locker), mtx_plain);
    cnd_init(&(ch->read));
    cnd_init(&(ch->write));
    return ch;
}

void delete_channel(channel_t *ch)
{
    mtx_destroy(&(ch->locker));
    cnd_destroy(&(ch->read));
    cnd_destroy(&(ch->write));
    return;
}

void *read(channel_t *ch)
{
    void *ret;
    mtx_lock(&(ch->locker));
    for (;;)
    {
        if (ch->value == NULL)
        {
            printf("[%ld] wait to read ...\n", thrd_current());
            cnd_wait(&(ch->read), &(ch->locker));
            printf("[%ld] can read now: \n", thrd_current());
        }
        else
        {
            break;
        }
    }
    ret = ch->value;
    ch->value = NULL;
    mtx_unlock(&(ch->locker));
    cnd_signal(&(ch->write));
    return ret;
}

void write(channel_t *ch, void *value)
{
    mtx_lock(&(ch->locker));
    for (;;)
    {
        if (ch->value != NULL)
        {
            printf("[%ld] wait to write ...\n", thrd_current());
            cnd_wait(&(ch->write), &(ch->locker));
            printf("[%ld] can write now: \n", thrd_current());
        }
        else
        {
            break;
        }
    }
    ch->value = value;
    mtx_unlock(&(ch->locker));
    cnd_signal(&(ch->read));
    return;
}

int th_read(void *p)
{
    channel_t *ch = (channel_t *)p;
    int64_t *n = (int64_t *)read(ch);
    printf("[%ld] read: n=%ld\n", thrd_current(), *n);
    return thrd_success;
}

int th_write(void *p)
{
    void **args = (void **)p;
    channel_t *ch = (channel_t *)args[0];
    int64_t *n = (int64_t *)args[1];
    write(ch, (void *)n);
    printf("[%ld] write: n=%ld\n", thrd_current(), *n);
    return thrd_success;
}

int main(int argc, char const *argv[])
{
    channel_t *ch = create_channel();

    thrd_t r_th1;
    thrd_create(&r_th1, th_read, ch);

    thrd_t r_th2;
    thrd_create(&r_th2, th_read, ch);

    thrd_t w_th1;
    int64_t w_n1 = 100;
    void *w_args1[] = {ch, &w_n1};
    thrd_create(&w_th1, th_write, (void *)w_args1);

    thrd_t w_th2;
    int64_t w_n2 = 200;
    void *w_args2[] = {ch, &w_n2};
    thrd_create(&w_th2, th_write, (void *)w_args2);

    thrd_join(r_th1, NULL);
    thrd_join(r_th2, NULL);
    thrd_join(w_th1, NULL);
    thrd_join(w_th2, NULL);

    delete_channel(ch);

    return EXIT_SUCCESS;
}