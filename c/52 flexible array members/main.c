// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
flexible array members (柔性数组成员)
    (1) 结构中的最后一个元素允许是未知大小的数组，称为柔性数组成员
    (2) 结构中的柔性数组成员前面必须至少一个其他成员
    (3) 柔性数组成员允许结构中包含一个大小可变的数组
    (4) 不占用内存空间，只作为一个符号地址存在, sizeof返回的这种结构大小不包括柔性数组的内存
    (5) 必须是结构体的最后一个成员
    (6) 包含柔性数组成员的结构体用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。
*/

typedef struct
{
    int8_t a;  // 1
    int16_t b; // 2
    int32_t c; // 4
    int64_t d; // 8
    char name[];
} demo;

int main(int argc, char const *argv[])
{
    demo *d = (demo *)malloc(sizeof(demo) + 16 * sizeof(char));
    printf("d: size=%lu\n", sizeof(d));
    printf("*d: size=%lu\n", sizeof(*d));
    d->a = 1;
    d->b = 1 << 10;
    char *name = "dev-go";
    strcpy(d->name, name);
    printf("d: a=%hhd, b=%hd, c=%d, d=%ld, name=%s\n", d->a, d->b, d->c, d->d, d->name);
    free(d);

    return EXIT_SUCCESS;
}