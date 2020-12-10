// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>
#include <time.h>

/*
(1) #define thread_local _Thread_local
        便利宏，用于指定对象拥有线程局域存储期。
        C11提供了TLS方法，可以像一般变量的方式去访问线程私有变量。
        做法很简单，在声明和定义线程私变量时指定_Thread_local存储修饰符即可，关于_Thread_local，C11 有如下的描述：
            在声明式中，_Thread_local只能单独使用，或者跟static或extern一起使用。
            在某一区快中声明某一对象，如果声明存储修饰符有_Thread_local，那么必须同时有static或extern。
            如果_Thread_local出现在一对象的某个声明式中，那么此对象的其余各处声明式都应该有_Thread_local存储修饰符。
            如果某一对象的声明式中出现_Thread_local存储修饰符，那么它有线程储存期。该对象的生命周期为线程的整个执行周期，它在线程出生时创建，并在线程启动时初始化。每个线程均有一份该对象，使用声明时的名字即可引用正在执行当前表达式的线程所关联的那个对象。
            TLS方式与传统的全局变量或static变量的使用方式完全一致，不同的是，TLS变量在不同的线程上均有各自的一份。
            线程访问TLS时不会产生data race，因为不需要任何加锁机制。
            TLS方式需要编译器的支持，对于任何_Thread_local变量，编译器要将之编译并生成放到各个线程的private memory区域，并且访问这些变量时，都要获得当前线程的信息，从而访问正确的物理对象，当然这一切都是在链接过程早已安排好的。

(2) tss_t	
        线程特定存储的指针

(3) #define TSS_DTOR_ITERATIONS // unspecified 
        展开成正的整数常量表达式，它定义 thrd_exit 将对线程局域存储指针调用析构器的最大次数。
        此常量等价于 POSIX 的 PTHREAD_DESTRUCTOR_ITERATIONS 。

(4) tss_dtor_t
        函数指针类型 void(*)(void*) ，用作 TSS 析构器

(5) int tss_create(tss_t* tss_key, tss_dtor_t destructor)
        创建新的线程特定存储key，并将它存储于 tss_key 所指向的对象。尽管不同线程可能使用相同的key-value，由 tss_set 绑定到key的value在每个线程基础上维护，并且在调用方线程的生命中保持存在。
        所有既存线程中，新建的key被关联到值 NULL ，而在创建线程时，将所有 TSS key关联的value被初始化为 NULL 。
        若 destructor 不是空指针，则亦关联在 thrd_exit （但不是 tss_delete 且不是在以 exit 终止程序时）释放存储时调用的析构器。
        在线程特定存储的析构器内调用 tss_create 导致未定义行为。
    参数:
        tss_key:	指向要存储新的线程特定存储key的内存位置的指针
        destructor:	指向要在线程退出时调用的函数的指针
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(6) void *tss_get(tss_t tss_key)
        返回 tss_key 所标识的，当前线程的线程特定存储中保有的value。不同线程可能获取同一key所标识的不同value。
        线程启动时（见 thrd_create ），与所有 TSS key关联的value均为 NULL 。可以用 tss_set 将相异的value置入线程指定存储。
    参数:
        tss_key:	从 tss_create 获得，且未被 tss_delete 删除的线程特定存储value
    返回值:
        成功时为值，失败时为 NULL 。

(7) int tss_set(tss_t tss_id, void *val)
        设置当前线程的 tss_id 所标识的线程特定存储的值为 val 。不同线程可以设置不同value给同一key。
        若析构器可用，则不调用它。
    参数:
        tss_id:	    从 tss_create 获得，且未被 tss_delete 删除的线程特定存储关键
        val:	    要设置给线程特定存储的值
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(8) void tss_delete(tss_t tss_id)
        销毁 tss_id 所标识的线程特定存储。
        若以 tss_create 注册了一个析构器，则不调用它（仅在线程退出时调用，无论是由 thrd_exit 还是通过从线程函数返回）。
        程序员负责确保在调用 tss_delete 前，每个知晓 tss_id 的线程都进行了必要的清理。
        若在另一线程执行 tss_id 的析构器时调用 tss_delete ，则这是否会更改关联析构器的调用次数是未指定的。 
        若在调用方线程执行析构器时调用 tss_delete ，则与 tss_id 关联的析构器将不会在此线程上再次执行。
    参数:
        tss_id:	先前 tss_create 所返回，且仍未被 tss_delete 删除的线程特定存储关键
    返回值:
        (无)
*/

thread_local int64_t num = 100;

tss_t key;

int th_local_demo(void *p);

int th_tss_demo(void *p);

void destructor(void *p);

void output(void);

int main(int argc, char const *argv[])
{
    thrd_t th1;
    int64_t n1 = 666;
    thrd_create(&th1, th_local_demo, (void *)(&n1));
    thrd_t th2;
    int64_t n2 = 888;
    thrd_create(&th2, th_local_demo, (void *)(&n2));
    thrd_join(th1, NULL);
    thrd_join(th2, NULL);

    thrd_t th3;
    thrd_t th4;
    int code3 = 0;
    int code4 = 0;
    if (tss_create(&key, destructor) != thrd_success)
        return EXIT_FAILURE;
    if (thrd_create(&th3, th_tss_demo, "th3") != thrd_success ||
        thrd_create(&th4, th_tss_demo, "th4") != thrd_success)
        return EXIT_FAILURE;
    thrd_join(th3, &code3);
    thrd_join(th4, &code4);
    if (code3 != 0 || code4 != 0)
    {
        return EXIT_FAILURE;
    }
    printf("over\n");
    tss_delete(key);
    struct timespec t = {.tv_sec = 3, .tv_nsec = 0};
    thrd_sleep(&t, NULL);

    return EXIT_SUCCESS;
}

int th_local_demo(void *p)
{
    printf("thread#[%ld] num = %ld\n", thrd_current(), num);
    int64_t *n = (int64_t *)p;
    num = *n;
    printf("thread#[%ld] num = %ld\n", thrd_current(), num);
    struct timespec t = {.tv_sec = 3, .tv_nsec = 0};
    thrd_sleep(&t, NULL);
    printf("thread#[%ld] >>> num = %ld\n", thrd_current(), num);
    return thrd_success;
}

int th_tss_demo(void *p)
{
    char *name = (char *)p;
    size_t size = strlen(name) + 1;
    if (tss_set(key, malloc(size)) != thrd_success)
        return -1;
    strcpy((char *)tss_get(key), name);
    output();
    return 0;
}

void destructor(void *p)
{
    printf("destructor: %s\n", (char *)p);
    free(p);
    return;
}

void output(void)
{
    printf("output: %s\n", (char *)tss_get(key));
    return;
}
