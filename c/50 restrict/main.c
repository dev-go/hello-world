// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
    (1) restrict是c99标准引入的，它只可以用于限定和约束指针，并表明指针是访问一个数据对象的唯一且初始的方式.
    (2) 它告诉编译器，所有修改该指针所指向内存中内容的操作都必须通过该指针来修改,而不能通过其它途径(其它变量或指针)来修改
    (3) 这样做的好处是,能帮助编译器进行更好的优化代码,生成更有效率的汇编代码.
*/

int8_t demo(int8_t *restrict n1, int8_t *restrict n2);

int main(int argc, char const *argv[])
{
    int64_t const LEN = 10;
    int64_t *restrict p1 = (int64_t *)malloc(LEN * sizeof(int64_t));
    for (int64_t i = 0; i < LEN; i++)
    {
        *(p1 + i) = (i + 1) * 100;
    }
    for (int64_t i = 0; i < LEN; i++)
    {
        printf("i = %ld, e = %ld\n", i, p1[i]);
    }
    free(p1);

    int8_t n1 = 100;
    printf("demo(&n1, &n1) = %d\n", demo(&n1, &n1));

    int8_t n2 = 200;
    printf("demo(&n1, &n2) = %d\n", demo(&n1, &n2));

    return EXIT_SUCCESS;
}

int8_t demo(int8_t *restrict n1, int8_t *restrict n2)
{
    *n1 = 5;
    *n2 = 6;
    return *n1 + *n2;
}
