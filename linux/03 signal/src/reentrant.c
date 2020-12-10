// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

/*
满足下面条件之一的多数是不可重入函数：

(1)使用了静态数据结构或者全局变量;
(2)调用了malloc或free;
(3)调用了标准I/O函数;标准io库很多实现都以不可重入的方式使用全局数据结构。
(4)进行了浮点运算.许多的处理器/编译器中，浮点一般都是不可重入的 (浮点运算大多使用协处理器或者软件模拟来实现。
(5)调用printf。
*/

#define LEN 10

int global_arr[LEN];

void out(int n)
{
    int local_arr[LEN];
    for (int i = 0; i < LEN; i++)
    {
        global_arr[i] = n;
        *(local_arr + i) = n;
        sleep(1);
    }
    printf("global_arr:  ");
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", *(global_arr + i));
        if (i == LEN - 1)
        {
            printf("\n");
        }
    }
    printf("local_arr:  ");
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", local_arr[i]);
        if (i == LEN - 1)
        {
            printf("\n");
        }
    }
}

void handle_signal(int signo)
{
    printf("handle signal: start ...\n");
    out(20);
    printf("handle signal: finish!\n");
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, &handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s\n", strerror(errno));
        return errno;
    }

    out(10);

    return EXIT_SUCCESS;
}