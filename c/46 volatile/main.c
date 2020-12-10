// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
(1) 因为访问寄存器要比访问内存单元快的多,所以编译器一般都会作减少存取内存的优化，但有可能会读脏数据。
    当要求使用volatile声明变量值的时候，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。
(2) 作用1： 告诉compiler不能做任何优化
(3) 作用2： 用volatile定义的变量会在程序外被改变,每次都必须从内存中读取，而不能重复使用放在cache或寄存器中的备份
*/

int64_t volatile num = 99;

int main(int argc, char const *argv[])
{
    printf("num = %ld\n", num);

    return EXIT_SUCCESS;
}