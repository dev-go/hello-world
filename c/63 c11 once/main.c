// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

// void call_once(once_flag* flag, void (*func)(void));
// typedef /* unspecified */ once_flag
// #define ONCE_FLAG_INIT /* unspecified */
//      1) 准确调用函数 func 一次，即使从多个线程调用。函数 func 的完成与先前或后继的用同一 flag 对象的对 call_once 调用同步。
//      2) 足以保有 call_once 所用标志的完整对象类型。
//      3) 展开成能用于初始化 once_flag 类型对象的值。
//  参数:
//      flag:	指向用于确保只调用一次 func 的 call_once 对象的指针
//      func:	只执行一次的函数
//  返回值:
//      (无)
//

static once_flag flag = ONCE_FLAG_INIT;

void func(void);

int th_start(void *p);

int main(int argc, char const *argv[])
{
    thrd_t th1;
    thrd_t th2;
    thrd_t th3;
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    void *p1[] = {&n1, &flag, &func};
    void *p2[] = {&n2, &flag, &func};
    void *p3[] = {&n3, &flag, &func};
    thrd_create(&th1, &th_start, (void *)p1);
    thrd_create(&th2, &th_start, (void *)p2);
    thrd_create(&th3, &th_start, (void *)p3);

    int result;
    thrd_join(th1, &result);
    printf("th1: over, result = %d\n", result);
    thrd_join(th2, &result);
    printf("th2: over, result = %d\n", result);
    thrd_join(th3, &result);
    printf("th3: over, result = %d\n", result);
}

void func(void)
{
    printf("func: call once\n");
    return;
}

int th_start(void *p)
{
    void **args = (void **)p;
    int *n = (int *)(args[0]);
    once_flag *flag = (once_flag *)(*(args + 1));
    void (*func)(void) = (void (*)(void))(*(args + 2));
    call_once(flag, func);
    printf("thread#%ld: n=%d\n", thrd_current(), *n);
    return EXIT_SUCCESS;
}