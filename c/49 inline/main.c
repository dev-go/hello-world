// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
(1) 关键字inline 必须与函数定义体放在一起才能使函数成为内联，仅将inline 放在函数声明前面不起任何作用。
(2) inline只适合涵数体内代码简单的函数数使用，不能包含复杂的结构控制语句例如while、switch，并且内联函数本身不能是直接递归函数
(3) 内联是以代码膨胀（复制）为代价
*/

char *bool_to_string(_Bool b);

int main(int argc, char const *argv[])
{
    _Bool b = 99;
    printf("b = %s\n", bool_to_string(b));

    return EXIT_SUCCESS;
}

inline char *bool_to_string(_Bool b)
{
    return b ? "true" : "false";
}