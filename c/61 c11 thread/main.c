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
(1) thrd_t	
        实现定义的标识线程的完整对象类型

(2)`thrd_start_t
        函数指针类型 int(*)(void*) 的 typedef ，为 thrd_create 所用

(3) int thrd_create(thrd_t *thr, thrd_start_t func, void *arg)
        创建一个执行函数 func 的新线程，以 func(arg) 调用此函数。
        若成功，则设置 thr 所指向的对象为新线程的标识符。
        此函数的完成同步于线程的开始。
    参数:
        thr:	指向放置新线程标识符的内存位置的指针
        func:	要执行的函数
        arg:	传递给函数的参数
    返回值:
        若新线程创建成功则为 thrd_success 。
        否则若内存不足则返回 thrd_nomem ，若出现其他错误则返回 thrd_error 。

(4) thrd_t thrd_current(void)
        返回调用方线程的标识符。
    参数:
        (无)
    返回值:
        调用方线程的标识符。

(5) int thrd_equal(thrd_t lhs, thrd_t rhs)
        检查 lhs 与 rhs 是否表示同一线程。
        thrd_t是标准约定的类型,可能是一个基础类型,也可能会是结构体。
        开发者应该使用thrd_equal来判断两者是否相等,不能直接使用==。
        即便==在某个平台下表现出来是正确的,但它不是标准的做法,也不可跨平台。
    参数:
        lhs, rhs:	要比较的线程
    返回值:
        若 lhs 与 rhs 表示同一线程则为非零值，否则为 ​0​ 。

(6) int thrd_sleep(const struct timespec* duration, struct timespec* remaining)
        阻塞当前线程的执行，至少直至经过 duration 所指向的基于 TIME_UTC 的时长。
        若收到不忽略的信号（ signal ），则可以较早地从休眠恢复。
        此情况下，若 remaining 非 NULL ，则存储剩余时长到 remaining 所指向的对象中。
    参数:
        duration:	指向要休眠的时长的指针
        remaining:	指向要放置中断剩余时间的对象的指针。可为 NULL ，此情况下忽略它
    返回值:
        成功休眠时为 ​0​，若出现信号则为 -1 ，若出现错误则为其他负值。

(7) void thrd_yield(void)
        向实现提供一个重新安排线程执行的提示，允许其他线程运行。
        此函数的准确行为取决于实现，特别是使用中的 OS 编排机制和系统状态。
    参数:
        (无)
    返回值:
        (无)

(8) _Noreturn void thrd_exit(int res)
        首先，对于每个以非空析构器创建，关联value非空的（见 tss_create ）线程特定存储key， thrd_exit 设置与key关联的value为 NULL ，然后以该key的先前value调用析构器。
        析构器的调用顺序是未指定的。
        若在此后，有剩余key拥有非空的析构器和value（例如若析构器执行了 tss_set ），则至多重复 TSS_DTOR_ITERATIONS 次处理。
        最后， thrd_exit 函数终止调用方线程的执行，并设置其结果码为 res 。
        若程序中的最后线程以 thrd_exit 退出，则如同通过以 EXIT_SUCCESS 为参数调用 exit 一般终止整个程序（故 atexit 所注册的函数在最后线程的环境中执行）。
    参数:
        res:	要返回的值
    返回值:
        (无)

(9) int thrd_detach(thrd_t thr)
        将 thr 所标识的线程从当前环境中分离。一旦该线程退出，就自动释放其保有的资源。
    参数:
        thr:    要分离的线程的标识符
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。

(10) int thrd_join(thrd_t thr, int *res)
        阻塞当前线程，直到 thr 所标识的线程完成执行。
        若 res 不是空指针，则将该线程的结果码放置到 res 所指向的位置。
        该线程的终止同步于此函数的完成。
        若该线程之前已被另一线程分离或合并，则行为未定义。
    参数:
        thr:	要合并的线程的标识符
        res:	放置结果码到的位置
    返回值:
        若成功则为 thrd_success ，否则为 thrd_error 。
    
(11) enum {
        thrd_success = ,    // unspecified 
        thrd_nomem = ,      // unspecified
        thrd_timedout = ,   // unspecified 
        thrd_busy = ,       // unspecified
        thrd_error = ,      // unspecified 
    }
        鉴别线程状态和错误。
        thrd_success:	    指示成功的返回值
        thrd_timedout:	    指示时间用尽的返回值
        thrd_busy:	        指示因资源暂时不可用而不成功的返回值
        thrd_nomem:	        指示因内存耗尽而不成功的返回值
        thrd_error:	        指示不成功的返回值
*/

int sum(void *arg);

int output(void *arg);

void atexit_func(void);

int main(int argc, char const *argv[])
{
    atexit(&atexit_func);

    int code;
    int exit_code;

    thrd_t th1;
    thrd_t th2;
    int64_t arg1[] = {0, 1, 101};
    int64_t arg2[] = {0, 101, 201};
    code = thrd_create(&th1, &sum, (void *)arg1);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] create thread #1 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    code = thrd_create(&th2, &sum, (void *)arg2);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] create thread #2 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }

    code = thrd_join(th1, &exit_code);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] join thread #1 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    printf("[%s:%d] [thread#%ld] thread #1 exit_code=%d, ret=%ld\n",
           __FILE__, __LINE__, thrd_current(), exit_code, arg1[0]);
    code = thrd_join(th2, &exit_code);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] join thread #2 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    printf("[%s:%d] [thread#%ld] thread #2: exit_code=%d, ret=%ld\n",
           __FILE__, __LINE__, thrd_current(), exit_code, arg2[0]);

    printf("[%s:%d] [thread#%ld] result=%ld\n",
           __FILE__, __LINE__, thrd_current(), arg1[0] + arg2[0]);

    printf("==================================================\n");

    thrd_t th3;
    int64_t arg3 = 10;
    code = thrd_create(&th3, &output, &arg3);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] create thread #3 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    code = thrd_detach(th3);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] detach thread #3 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    // code = thrd_join(th3, &exit_code);
    // if (code != 0)
    // {
    //     printf("[%s:%d] [thread#%ld] join thread #3 failed: %s\n",
    //            __FILE__, __LINE__, thrd_current(), strerror(code));
    //     return code;
    // }

    thrd_t th4;
    int64_t arg4 = 6;
    code = thrd_create(&th4, &output, &arg4);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] create thread #4 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] join thread #4 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }
    code = thrd_join(th4, &exit_code);
    if (code != 0)
    {
        printf("[%s:%d] [thread#%ld] join thread #4 failed: %s\n",
               __FILE__, __LINE__, thrd_current(), strerror(code));
        return code;
    }

    printf("-----------------------------------------------------\n");

    thrd_exit(EXIT_SUCCESS);

    printf("you should not see this line\n");
}

int sum(void *arg)
{
    int64_t *p = (int64_t *)arg;
    printf("[%s:%d] [thread#%ld] ret: %ld, start: %ld, end: %ld\n",
           __FILE__, __LINE__, thrd_current(), p[0], *(p + 1), *(p + 2));
    for (int64_t i = p[1]; i < *(p + 2); ++i)
    {
        *(p + 0) += i;
    }
    struct timespec sleep_time = {.tv_sec = 1, .tv_nsec = 0};
    struct timespec remain_time = {.tv_sec = 0, .tv_nsec = 0};
    thrd_sleep(&sleep_time, &remain_time);
    printf("[%s:%d] [thread#%ld] sleep_time: tv_sec=%ld, nsec=%ld    remain_time: tv_sec=%ld, nsec=%ld\n",
           __FILE__, __LINE__, thrd_current(), sleep_time.tv_sec, sleep_time.tv_nsec, remain_time.tv_sec, remain_time.tv_nsec);
    printf("[%s:%d] [thread#%ld] ret: %ld, start: %ld, end: %ld\n",
           __FILE__, __LINE__, thrd_current(), p[0], *(p + 1), *(p + 2));

    return thrd_success;
}

int output(void *arg)
{
    int64_t *end = (int64_t *)arg;
    for (int64_t i = 0; i < *end; ++i)
    {
        printf("[%s:%d] [thread#%ld] devgo.club, i=%ld\n",
               __FILE__, __LINE__, thrd_current(), i);
        thrd_yield();
        // 1毫秒 = 1 000 000纳秒
        struct timespec sleep_time = {.tv_sec = 1, .tv_nsec = 0};
        struct timespec remain_time = {.tv_sec = 0, .tv_nsec = 0};
        int code = thrd_sleep(&sleep_time, &remain_time);
        printf("[%s:%d] [thread#%ld] thrd_sleep: %s, remain_time: tv_sec=%ld, tv_nsec=%ld, i=%ld\n",
               __FILE__, __LINE__, thrd_current(), strerror(code), remain_time.tv_sec, remain_time.tv_nsec, i);
    }
    return thrd_success;
}

void atexit_func(void)
{
    printf("!!!atexit_func!!!\n");
}