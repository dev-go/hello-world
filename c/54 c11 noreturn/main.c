// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

/*
  noreturn function_declaration
    (1) 函数修饰符，位置在函数返回类型的前面，声明函数无返回值
    (2) noreturn关键词出现于函数声明中，指定函数不会由于执行到return语句或抵达函数体结尾而返回（可通过执行longjmp返回）
    (3) 若声明noreturn的函数返回，则行为未定义
    (4) 下列标准库的函数为noreturn ：
        abort()
        exit()
        _Exit()
        quick_exit()
        thrd_exit()
        longjmp()
*/

noreturn void demo(int32_t code)
{
    printf("demo: code=%d\n", code);
    exit(code);
}

int main(int argc, char const *argv[])
{
    demo(3);
    puts("------ ------");
    demo(1);
    return EXIT_SUCCESS;
}