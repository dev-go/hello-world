// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
timespec:
    (1) time.h新增timespec结构体，时间单位为纳秒，原来的timeval结构体时间单位为毫秒。
    (2) struct timespec有两个成员，一个是秒，一个是纳秒, 所以最高精确度是纳秒。
    (3) 一般由函数int clock_gettime(clockid_t, struct timespec *)获取特定时钟的时间，常用如下4种时钟：
        CLOCK_REALTIME 统当前时间，从1970年1.1日算起
        CLOCK_MONOTONIC 系统的启动时间，不能被设置
        CLOCK_PROCESS_CPUTIME_ID 本进程运行时间
        CLOCK_THREAD_CPUTIME_ID 本线程运行时间
    (4) 相关函数:
        struct tm *localtime(const time_t *clock);                                                  
            // 把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为本地时间 (线程不安全)
        struct tm* localtime_r(const time_t* timer, struct tm* result);                           
            // 把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为本地时间 (线程安全)
        size_t strftime (char* ptr, size_t maxsize, const char* format,const struct tm* timeptr);  
            // 根据区域设置格式化本地时间/日期
*/

void output_nowtime_ns()
{
    printf("time(NULL): %ld\n", time(NULL));
    struct timespec t1;
    clock_gettime(CLOCK_REALTIME, &t1);
    printf("t1: tv_sec=%ld, tv_nsec=%ld\n", t1.tv_sec, t1.tv_nsec);

    struct tm t2;
    char s[64];
    strftime(s, sizeof(s), "%Y/%m/%d %H:%M:%S", localtime_r(&t1.tv_sec, &t2));

    printf("output: time: %s (ns: %ld)\n", s, t1.tv_nsec);

    return;
}

int main(int argc, char const *argv[])
{
    output_nowtime_ns();

    return EXIT_SUCCESS;
}