// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>

#include "file_io.h"

/*
// 阻塞式IO
int main(int argc, char const *argv[])
{
    int const BUFFER_LEN = 1 << 12;
    char buffer[BUFFER_LEN];
    int read_bytes = 0;
    while ((read_bytes = read(STDIN_FILENO, buffer, sizeof(char) * BUFFER_LEN)) > 0)
    {
        fprintf(stdout, "read_bytes = %d\n", read_bytes);
        while (write(STDOUT_FILENO, buffer, read_bytes) != read_bytes)
        {
            fprintf(stderr, "write faild: %s\n", strerror(errno));
            return errno;
        }
    }
    return errno;
}
*/

/*
// 非阻塞式IO （一）
int main(int argc, char const *argv[])
{
    int err;
    if ((err = add_flag(STDIN_FILENO, O_NONBLOCK)) < 0)
    {
        fprintf(stderr, "add flag failed: %s\n", strerror(err));
        return err;
    }

    int const BUFFER_LEN = 1 << 12;
    char buffer[BUFFER_LEN];
    int read_bytes;
    while ((read_bytes = read(STDIN_FILENO, buffer, sizeof(char) * BUFFER_LEN)) > 0)
    {
        if (write(STDOUT_FILENO, buffer, read_bytes) != read_bytes)
        {
            fprintf(stderr, "write failed: %s\n", strerror(errno));
            return errno;
        }
    }
    return errno;
}
*/

/*
// 非阻塞式IO （二）
int main(int argc, char const *argv[])
{
    int err;
    if ((err = add_flag(STDIN_FILENO, O_NONBLOCK)) < 0)
    {
        fprintf(stderr, "add flag failed: %s\n", strerror(err));
        return err;
    }
    sleep(10);

    int const BUFFER_LEN = 1 << 12;
    char buffer[BUFFER_LEN];
    int read_bytes;
    while ((read_bytes = read(STDIN_FILENO, buffer, sizeof(char) * BUFFER_LEN)) > 0)
    {
        if (write(STDOUT_FILENO, buffer, read_bytes) != read_bytes)
        {
            fprintf(stderr, "write failed: %s\n", strerror(errno));
            return errno;
        }
    }
    return errno;
}
*/

// 多路转换IO
// int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,struct timeval *timeout);
// (1) 参数值:
//   @nfds
//       是一个整数值，是指集合中所有文件描述符的范围，即所有文件描述符的最大值加1
//   @fd_set *readfds
//       是指向fd_set结构的指针，这个集合中应该包括文件描述符，我们是要监视这些文件描述符的读变化的，即我们关心是否可以从这些文件中读取数据了.
//       如果这个集合中有一个文件可读，select就会返回一个大于0的值，表示有文件可读；
//       如果没有可读的文件，则根据timeout参数再判断是否超时，若超出timeout的时间，select返回0，若发生错误返回负值。
//       可以传入NULL值，表示不关心任何文件的读变化。
//   @fd_set *writefds
//       是指向fd_set结构的指针，这个集合中应该包括文件描述符，我们是要监视这些文件描述符的写变化的，即我们关心是否可以向这些文件中写入数据了。
//       如果这个集合中有一个文件可写，select就会返回一个大于0的值，表示有文件可写;
//       如果没有可写的文件，则根据timeout参数再判断是否超时，若超出timeout的时间，select返回0，若发生错误返回负值。
//       可以传入NULL值，表示不关心任何文件的写变化。
//   @fd_set *errorfds同上面两个参数的意图，用来监视文件错误异常文件。
//   @struct timeval* timeout
//       是select的超时时间，这个参数至关重要，它可以使select处于三种状态，
//       第一，若将NULL以形参传入，即不传入时间结构，就是将select置于阻塞状态，一定等到监视文件描述符集合中某个文件描述符发生变化为止；
//       第二，若将时间值设为0秒0毫秒，就变成一个纯粹的非阻塞函数，不管文件描述符是否有变化，都立刻返回继续执行，文件无变化返回0，有变化返回一个正值；
//       第三，timeout的值大于0，这就是等待的超时时间，即 select在timeout时间内阻塞，超时时间之内有事件到来就返回了，否则在超时后不管怎样一定返回，返回值同上述。
// (2) 返回值:
//       当监视的相应的文件描述符集中满足条件时，比如说读文件描述符集中有数据到来时，内核(I/O)根据状态修改文件描述符集，并返回一个大于0的数。
//       当没有满足条件的文件描述符，且设置的timeval监控时间超时时，select函数会返回一个为0的值。
//       当select返回负值时，发生错误。
// ************************************************************************************************************************************************
// FD_ISSET:
//       判断描述符fd是否在给定的描述符集fdset中，通常配合select函数使用，
//       select函数成功返回时会将未准备好的描述符位清零。
//       当描述符fd在描述符集fdset中返回非零值，否则，返回零。

int main(int argc, char const *argv[])
{
    fd_set fs;
    FD_ZERO(&fs);
    FD_SET(STDIN_FILENO, &fs);
    struct timeval tv = {.tv_sec = 5, .tv_usec = 0};

    int const BUFFER_LEN = 1 << 12;
    char buffer[BUFFER_LEN];
    int read_bytes;

    for (;;)
    {
        int ready_cnt = select(STDIN_FILENO + 1, &fs, NULL, NULL, &tv);
        // TODO: FD_CLR(STDIN_FILENO, &fs);
        if (ready_cnt < 0)
        {
            fprintf(stderr, "select failed: %s\n", strerror(errno));
            FD_CLR(STDIN_FILENO, &fs);
            return errno;
        }
        else if (ready_cnt == 0)
        {
            fprintf(stderr, "select timeout\n");
        }
        else
        {
            if (FD_ISSET(STDIN_FILENO, &fs) != 0)
            {
                if ((read_bytes = read(STDIN_FILENO, buffer, sizeof(char) * BUFFER_LEN)) > 0)
                {
                    if ((write(STDOUT_FILENO, buffer, read_bytes)) != read_bytes)
                    {
                        fprintf(stderr, "write failed: %s\n", strerror(errno));
                        FD_CLR(STDIN_FILENO, &fs);
                        return errno;
                    }
                }
            }
        }

        tv.tv_sec = 5;
        tv.tv_usec = 0;
        FD_ZERO(&fs);
        FD_SET(STDIN_FILENO, &fs);
    }
    FD_CLR(STDIN_FILENO, &fs);
    return EXIT_SUCCESS;
}