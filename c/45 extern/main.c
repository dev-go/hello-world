// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "demo.h"

/*
(1) extern关键字可以用来声明变量和函数作为外部变量或者函数供其它文件使用。
(2) 关键字extern的存在标志着这是一个引用声明，而非定义声明，非定义声明不能进行初始化
(3) 声明分为两种：
        int num = 1;        //这种声明称为定义声明(defining declaration)
        extern int num;     //这种声明称为引用声明(referencing declaration)
*/

int main(int argc, char const *argv[])
{
    printf("num: val=%ld, addr=%p\n", num, &num);

    func();

    printf("num: val=%ld, addr=%p\n", num, &num);

    func();

    printf("num: val=%ld, addr=%p\n", num, &num);

    return EXIT_SUCCESS;
}