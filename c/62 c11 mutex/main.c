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
(1) mtx_t	
        互斥标识符

(2) int mtx_init(mtx_t* mutex, int type)
        创建新的拥有 type 类型的互斥。设置 mutex 所指向的对象为新创建互斥的标识符。
        type 必须拥有下列值之一：
            mtx_plain:                  创建简单的，非递归互斥。
            mtx_timed:                  创建非递归的，支持时间限制的互斥。
            mtx_plain | mtx_recursive:  创建递归互斥。
            mtx_timed | mtx_recursive:  创建递归的支持时限的互斥。
    参数:
        mutex:		指向要初始化的互斥的指针
        type:		互斥的类型
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(3) int mtx_lock(mtx_t* mutex)
        阻塞当前线程，直至锁定 mutex 所指向的互斥。
        若该互斥已被当前线程锁定且非递归，则行为未定义。
        先前在同一互斥上对 mtx_unlock 的调用同步于此操作，而且任何给定互斥上的所有锁定/解锁操作构成单独全序（类似原子对象的修改顺序）。

    参数:
        mutex:	指向要锁定的互斥的指针
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(4) int mtx_timedlock(mtx_t *restrict mutex, const struct timespec *restrict time_point)
        阻塞当前线程，直到 mutex 所指向的互斥被锁，或直到抵达 time_point 所指向的基于 TIME_UTC 的时间点。
        若当前线程已经锁定该互斥且该互斥非递归，则行为未定义。
        若该互斥不支持时限，则行为未定义。
        先前在同一互斥上对 mtx_unlock 的调用同步于此操作（若此操作成功），而且任何给定的互斥上的所有锁定/解锁组成单独全序（类似原子对象上的修改顺序）。
    参数:
        mutex:  	指向要锁定的互斥的指针
        time_point:	指向要等待到的时限时间点的指针
    返回值:
        若成功则为 thrd_success ，若已在锁定互斥前抵达时限则为 thrd_timedout ，若出现错误则为 thrd_error 。

(5) int mtx_trylock(mtx_t *mutex)
        尝试锁定 mutex 所指向的互斥而不阻塞。若该互斥已被锁定则立即返回。
        同一互斥上对 mtx_unlock 的先前调用同步于此操作（若此操作成功），而且任何给定互斥上的所有锁定/解锁操作构成单独全序（类似于原子对象上的修改顺序）。
    参数:
        mutex:	指向要锁定的互斥的指针
    返回值:
        若成功则为 thrd_success ，若已锁定该互斥或由于获取可用互斥的虚假失败 (C17 起)则为 thrd_busy ，若出现错误则为 thrd_error 。

(6) int mtx_unlock(mtx_t *mutex)
        解锁 mutex 所指向的互斥。
        若调用方线程未锁定该互斥，则行为未定义。
        在同一互斥上，此函数同步于后继的 mtx_lock 、 mtx_trylock 或 mtx_timedlock 。何给定互斥上的所有锁/解锁操作构成单独全序（类似原子对象上的修改顺序）。
    参数:
        mutex:	指向要解锁的互斥的指针
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(7) void mtx_destroy(mtx_t *mutex)
        销毁 mutex 所指向的互斥。
        若有线程在 mutex 上等待，则行为未定义。
    参数:
        mutex:	指向要销毁的互斥的指针
    返回值:
        (无)

(8) enum {
        mtx_plain = ,       // unspecified
        mtx_recursive = ,   // unspecified
        mtx_timed = ,       // unspecified
    };
        传递给 mtx_init 时，标识要创建的互斥类型。
        同一个线程可以多次获取同一个递归锁，不会产生死锁。而如果一个线程多次获取同一个非递归锁，则会产生死锁。
        常量	         解释
        mtx_plain	    平常互斥
        mtx_recursive	递归互斥
        mtx_timed	    定时互斥

*/

int64_t const NAME_LEN = 32;

typedef struct
{
    mtx_t locker;
    int64_t id;
    int64_t balance;
    char name[];
} user_t;

user_t *create_user(int64_t id, char name[]);

void delete_user(user_t *user);

int safe_change_money(user_t *user, int64_t money);

char *unsafe_tostring_user(user_t *user);

char *safe_tostring_user(user_t *user);

int transfer_money(user_t *u1, user_t *u2, int64_t money);

int start_func(void *p);

int main(int argc, char const *argv[])
{
    char *str;

    user_t *u1 = create_user(135, "liu");
    safe_change_money(u1, 5000);
    str = safe_tostring_user(u1);
    printf("[%s:%d] thread#%ld u1: %s\n",
           __FILE__, __LINE__, thrd_current(), str);
    free(str);

    user_t *u2 = create_user(139, "terrence");
    safe_change_money(u2, 3000);
    str = safe_tostring_user(u2);
    printf("[%s:%d] thread#%ld u2: %s\n",
           __FILE__, __LINE__, thrd_current(), str);
    free(str);

    int res1 = 0;
    int64_t money1 = 3000;
    void *args1[] = {&res1, u1, u2, &money1};
    thrd_t th1;
    thrd_create(&th1, &start_func, (void *)args1);

    int res2 = 0;
    int64_t money2 = 8000;
    void *args2[] = {&res2, u2, u1, &money2};
    thrd_t th2;
    thrd_create(&th2, &start_func, (void *)args2);

    int c1;
    int c2;
    c2 = thrd_join(th1, &c1);
    printf("[%s:%d] thread#%ld c1=%d, c2=%d, res1=%d\n",
           __FILE__, __LINE__, thrd_current(), c1, c2, res1);
    c2 = thrd_join(th2, &c2);
    printf("[%s:%d] thread#%ld c1=%d, c2=%d, res2=%d\n",
           __FILE__, __LINE__, thrd_current(), c1, c2, res2);

    str = safe_tostring_user(u1);
    printf("[%s:%d] thread#%ld u1: %s\n",
           __FILE__, __LINE__, thrd_current(), str);
    free(str);
    str = safe_tostring_user(u2);
    printf("[%s:%d] thread#%ld u2: %s\n",
           __FILE__, __LINE__, thrd_current(), str);
    free(str);

    delete_user(u1);
    delete_user(u2);

    return EXIT_SUCCESS;
}

user_t *create_user(int64_t id, char name[])
{
    user_t *user = (user_t *)malloc(sizeof(user_t) + NAME_LEN * sizeof(char));
    if (user == NULL)
    {
        printf("[%s:%d] create user failed: %s, id=%ld, name=%s\n",
               __FILE__, __LINE__, strerror(errno), id, name);
        return NULL;
    }
    int code = mtx_init(&(user->locker), mtx_plain);
    if (code != 0)
    {
        printf("[%s:%d] create user failed: %s, id=%ld, name=%s\n",
               __FILE__, __LINE__, strerror(code), id, name);
    }
    user->id = id;
    strncpy(user->name, name, strlen(name) > NAME_LEN ? NAME_LEN : strlen(name));
    user->balance = 0;
    return user;
}

void delete_user(user_t *user)
{
    mtx_destroy(&(user->locker));
    free(user);
    return;
}

int safe_change_money(user_t *user, int64_t money)
{
    int res = thrd_success;
    mtx_lock(&(user->locker));
    if (user->balance + money >= 0)
    {
        user->balance += money;
        res = thrd_error;
    }
    mtx_unlock(&(user->locker));
    return res;
}

char *unsafe_tostring_user(user_t *user)
{
    char *str = (char *)malloc(2 * NAME_LEN * sizeof(char));
    sprintf(str, "{id: %ld, name=%s, balance=%ld}", user->id, user->name, user->balance);
    return str;
}

char *safe_tostring_user(user_t *user)
{
    char *str;
    mtx_lock(&(user->locker));
    str = unsafe_tostring_user(user);
    mtx_unlock(&(user->locker));
    return str;
}

int transfer_money(user_t *u1, user_t *u2, int64_t money)
{
    if (u1 == NULL || u2 == NULL || u1->id == u2->id || money <= 0)
    {
        return EINVAL;
    }

    int res = thrd_error;
    if (u1->id < u1->id)
    {
        mtx_lock(&(u1->locker));
        mtx_lock(&(u2->locker));
    }
    else
    {
        mtx_lock(&(u2->locker));
        mtx_lock(&(u1->locker));
    }
    char *s1 = unsafe_tostring_user(u1);
    char *s2 = unsafe_tostring_user(u2);
    printf("[%s:%d] thread#%ld u1: %s, u2: %s, money=%ld\n",
           __FILE__, __LINE__, thrd_current(), s1, s2, money);
    free(s1);
    free(s2);
    if (u1->balance - money > 0)
    {
        u1->balance -= money;
        u2->balance += money;
        res = thrd_success;
    }
    struct timespec t = {.tv_sec = 3, .tv_nsec = 0};
    int code = thrd_sleep(&t, NULL);
    printf("[%s:%d] thread#%ld sleep: code=%d\n",
           __FILE__, __LINE__, thrd_current(), code);
    s1 = unsafe_tostring_user(u1);
    s2 = unsafe_tostring_user(u2);
    printf("[%s:%d] thread#%ld u1: %s, u2: %s, money=%ld\n",
           __FILE__, __LINE__, thrd_current(), s1, s2, money);
    free(s1);
    free(s2);
    if (u1->id < u1->id)
    {
        mtx_unlock(&(u2->locker));
        mtx_unlock(&(u1->locker));
    }
    else
    {
        mtx_unlock(&(u1->locker));
        mtx_unlock(&(u2->locker));
    }

    return res;
}

int start_func(void *p)
{
    void **args = (void **)p;
    int *res = (int *)(args[0]);
    user_t *u1 = (user_t *)(args[1]);
    user_t *u2 = (user_t *)(args[2]);
    int64_t *money = (int64_t *)(args[3]);
    // printf("[%s:%d] thread#%ld res=%p, u1=%p, u2=%p, money=%p\n",
    //        __FILE__, __LINE__, thrd_current(), res, u1, u2, money);
    *res = transfer_money(u1, u2, *money);
    printf("[%s:%d] thread#%ld transfer money: res=%d\n",
           __FILE__, __LINE__, thrd_current(), *res);
    // printf("[%s:%d] thread#%ld start_func: <<<\n",
    //        __FILE__, __LINE__, thrd_current());

    return thrd_success;
}