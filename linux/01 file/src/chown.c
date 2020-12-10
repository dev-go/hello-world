// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
int chown(const char *path, uid_t owner, gid_t group);
//通过传入path的方式，改变和文件的拥有关系，如果他是一个符号链接，则跟踪它

int fchown(int fd, uid_t owner, gid_t group);
//通过文件描述的方式进行修改用户所有组等的情况

int lchown(const char *path, uid_t owner, gid_t group);
//和chown不同的是它不跟踪符号链接

(1) 更改文件的用户ID和组ID，如果参数owner或group中的任意一个是-1,则对应的ID不变
*/

int main(int argc, char const *argv[])
{

    system("id");
    printf("============================\n");
    system("ls -l a.txt");
    printf("============================\n");
    if (chown("a.txt", -1, 115) < 0)
    {
        fprintf(stderr, "change gid failed: %s\n", strerror(errno));
        return errno;
    }
    else
    {
        fprintf(stdout, "change gid success\n");
    }
    printf("============================\n");
    system("ls -l a.txt");
    printf("============================\n");
}