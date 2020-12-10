// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
quick_exit: 
    (1) 一种终止程序的方式, 当exit()失败时用以终止程序
    (2) 对于退出操作, 目前有: abort quick_exit exit,
        abort:      直接退出什么都不管
        exit:       会先执行atexit注册的操作, 随后各种额外处理, 如: 刷新缓冲区, 刷新文件描述符 ...
        quick_exit  处理流程非常简单, 先执行at_quick_exit注册函数, 随后交给_exit直接退出
    (3) 如果at_quick_exit中调用了exit, 则行为未定义
*/

void f1(void)
{
    printf("f1\n");
}

void f2(void)
{
    printf("f2\n");
}

int main(int argc, char const *argv[])
{
    at_quick_exit(f1);
    at_quick_exit(f2);

    quick_exit(1);

    return EXIT_SUCCESS;
}