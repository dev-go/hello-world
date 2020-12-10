// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

/*
(1) auto用于在函数中修饰变量为自动变量，且可省略。
(2) 当省略数据类型，只使用auto修饰变量，在C语言中默认变量为int型
(3) 在函数中没有被声明为其他类型的变量默认都是自动变量，因此auto算是C语言中应用最广泛的一种类型。
(4) auto不能修饰全局变量，因为自动变量只能存在于函数内。
(5) 自动变量属于动态存储类型，只存在于函数内。其存储单元在函数被调用时分配，在函数调用结束后被释放。
    这个过程是通过一个堆栈的机制来实现的。为自动变量分配内存就压栈，而函数返回时就退栈。
    自动变量如果不赋值，则变量的值是不确定的。这是因为在函数被调用时，会为该变量随机分配一个存储空间，该存储空间的值和地址都是不确定的。
*/

// auto n; // error: file-scope declaration of 'n' specifies 'auto'

int main(int argc, char const *argv[])
{
    double f1 = 3.33;
    double f2 = 9.78;
    printf("f1=%lf, f2=%lf\n", f1, f2);

    auto n1 = 5; // warning: type defaults to 'int' in declaration of 'n1'
    printf("n1: val=%d, size=%lu\n", n1, sizeof(n1));

    n1 = (int)(f1 + f2);
    printf("n1: val=%d, size=%lu\n", n1, sizeof(n1));

    double auto f3 = f1 + f2;
    printf("f3: val=%lf\n", f3);

    return EXIT_SUCCESS;
}