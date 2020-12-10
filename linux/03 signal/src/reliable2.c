// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

/*
int pause(void);
　　作用：使调用进程（线程）进入休眠状态（就是挂起）；直到接收到信号且信号函数成功返回 pause函数才会返回
　　返回值：始终返回-1
*/

int flag = 0;

void handle_signal(int signo)
{
    printf("handle signal: start ...\n");
    flag = 1;
    printf("clean up ...\n");
    sleep(5);
    printf("handle signal: finish!\n");
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, &handle_signal) != NULL)
    {
        fprintf(stderr, "signal failed: %s, signo = %d\n", strerror(errno), SIGINT);
        return errno;
    }
    // for (int i = 0; i < 1 << 10; i++)
    // {
    //     if (flag != 0)
    //     {
    //         break;
    //     }
    //     printf("i = %d\n", i);
    //     sleep(1);
    // }
    pause();
    printf("bye!\n");
    return EXIT_SUCCESS;
}