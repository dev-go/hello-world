// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>

/*
#include <sys/resource.h>

int getrlimit(int resource, struct rlimit *rlim);
int setrlimit(int resource, const struct rlimit *rlim);

  1) 功能:
        获取或设定资源使用限制。
        每种资源都有相关的软硬限制，软限制是内核强加给相应资源的限制值，硬限制是软限制的最大值。
        非授权调用进程只可以将其软限制指定为0~硬限制范围中的某个值，同时能不可逆转地降低其硬限制。
        授权进程可以任意改变其软硬限制。RLIM_INFINITY的值表示不对资源限制。

  2) 参数：
        @resource：可能的选择有:
            RLIMIT_AS //进程的最大虚内存空间，字节为单位。
            RLIMIT_CORE //内核转存文件的最大长度。
            RLIMIT_CPU //最大允许的CPU使用时间，秒为单位。当进程达到软限制，内核将给其发送SIGXCPU信号，这一信号的默认行为是终止进程的执行。然而，可以捕捉信号，处理句柄可将控制返回给主程序。如果进程继续耗费CPU时间，核心会以每秒一次的频率给其发送SIGXCPU信号，直到达到硬限制，那时将给进程发送 SIGKILL信号终止其执行。
            RLIMIT_DATA //进程数据段的最大值。
            RLIMIT_FSIZE //进程可建立的文件的最大长度。如果进程试图超出这一限制时，核心会给其发送SIGXFSZ信号，默认情况下将终止进程的执行。
            RLIMIT_LOCKS //进程可建立的锁和租赁的最大值。
            RLIMIT_MEMLOCK //进程可锁定在内存中的最大数据量，字节为单位。
            RLIMIT_MSGQUEUE //进程可为POSIX消息队列分配的最大字节数。
            RLIMIT_NICE //进程可通过setpriority() 或 nice()调用设置的最大完美值。
            RLIMIT_NOFILE //指定比进程可打开的最大文件描述词大一的值，超出此值，将会产生EMFILE错误。
            RLIMIT_NPROC //用户可拥有的最大进程数。
            RLIMIT_RTPRIO //进程可通过sched_setscheduler 和 sched_setparam设置的最大实时优先级。
            RLIMIT_SIGPENDING //用户可拥有的最大挂起信号数。
            RLIMIT_STACK //最大的进程堆栈，以字节为单位。
        @rlim：描述资源软硬限制的结构体，原型如下
            struct rlimit {
            　　rlim_t rlim_cur;
            　　rlim_t rlim_max;
            };
  3) 返回值说明：
        成功执行时，返回0。失败返回-1，errno被设为以下的某个值:
            EFAULT：rlim指针指向的空间不可访问
            EINVAL：参数无效
            EPERM：增加资源限制值时，权能不允许
*/

#define LIMIT(res) query_limit(#res, res)

void query_limit(char *name, int res);

int main(int argc, char const *argv[])
{
    LIMIT(RLIMIT_AS);
    LIMIT(RLIMIT_CORE);
    LIMIT(RLIMIT_CPU);
    LIMIT(RLIMIT_DATA);
    LIMIT(RLIMIT_FSIZE);
    LIMIT(RLIMIT_LOCKS);
    LIMIT(RLIMIT_MEMLOCK);
    LIMIT(RLIMIT_NOFILE);

    printf("--------------------------\n");

    struct rlimit limit = {.rlim_cur = 4, .rlim_max = 1024};
    if (setrlimit(RLIMIT_NOFILE, &limit) != 0)
    {
        fprintf(stderr, "setrlimit failed: %s\n", strerror(errno));
        return errno;
    }
    printf("--------------------------\n");

    LIMIT(RLIMIT_NOFILE);

    printf("--------------------------\n");

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char const *f1 = argv[1];
    char const *f2 = argv[2];
    FILE *file1 = fopen(f1, "w");
    if (file1 == NULL)
    {
        fprintf(stderr, "fopen failed: %s, f1 = %s\n", strerror(errno), f1);
        return errno;
    }
    FILE *file2 = fopen(f2, "w");
    if (file2 == NULL)
    {
        fprintf(stderr, "fopen failed: %s, f2 = %s\n", strerror(errno), f2);
        return errno;
    }

    return EXIT_SUCCESS;
}

void query_limit(char *name, int res)
{
    struct rlimit limit;
    if (getrlimit(res, &limit) != 0)
    {
        fprintf(stderr, "getrlimit failed: %s, res = %d\n", strerror(errno), res);
        return;
    }
    printf("%15s", name);
    if (limit.rlim_cur == RLIM_INFINITY)
    {
        fprintf(stdout, " soft (INFINITY)");
    }
    else
    {
        fprintf(stdout, " soft (%8ld)", limit.rlim_cur);
    }
    if (limit.rlim_max == RLIM_INFINITY)
    {
        fprintf(stdout, " hard (INFINITY)");
    }
    else
    {
        fprintf(stdout, " hard (%8ld)", limit.rlim_max);
    }
    fprintf(stdout, "\n");
}