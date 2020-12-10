// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <errno.h>
#include <stdalign.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  (1) void *aligned_alloc( size_t alignment, size_t size );
      分配size字节未初始化的存储空间，按照alignment指定对齐
      size参数必须是alignment的整数倍。
  (2) size_t alignof(type)
      返回由类型标识所指示的类型的任何实例所要求的对齐字节数
      该类型可以为完整类型、数组类型
      若类型为数组类型，则返回元素类型的对齐要求
  (3) alignas (expression)	
      设置内存的对其方式
*/

#define NAME_LEN (128)

typedef struct
{
    int32_t len;
    char str[];
} string;

typedef struct
{
    int8_t id;
    _Alignas(string) char name[sizeof(string) + NAME_LEN * sizeof(char)];
} user;

typedef struct
{
    int8_t id;
    char name[sizeof(string) + NAME_LEN * sizeof(char)];
} user2;

int main(int argc, char const *argv[])
{
    printf("string: size=%lu, align=%lu\n", sizeof(string), alignof(string));
    printf("string *: size=%lu, align=%lu\n", sizeof(string *), alignof(string *));
    printf("user: size=%lu, align=%lu\n", sizeof(user), alignof(user));
    printf("user *: size=%lu, align=%lu\n", sizeof(user *), alignof(user *));
    printf("user2: size=%lu, align=%lu\n", sizeof(user2), alignof(user2));
    printf("user2 *: size=%lu, align=%lu\n", sizeof(user2 *), alignof(user2 *));

    user us[2];
    printf("us: size=%lu, align=%lu\n", sizeof(us), alignof(us));

    user u1 = {.id = 1};
    ((string *)(u1.name))->len = NAME_LEN;
    strcpy(((string *)(u1.name))->str, "你好");
    printf("u1: id=%hhd, name={id=%d, str=%s}\n", u1.id, ((string *)(u1.name))->len, ((string *)(u1.name))->str);

    string *p1 = (string *)aligned_alloc(alignof(string), sizeof(string) + NAME_LEN * sizeof(char));
    if (NULL == p1)
    {
        printf("aligned_alloc failed: %s", strerror(errno));
        return EXIT_FAILURE;
    }
    p1->len = NAME_LEN;
    strcpy(p1->str, "dev-go");
    printf("*p1: len=%d, str=%s\n", p1->len, p1->str);
    free(p1);

    return EXIT_SUCCESS;
}
