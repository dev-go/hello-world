// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "demo.h"

/*
(1) 普通局部变量
    在任何一个函数内部定义的变量（不加static修饰符）都属于这个范畴。
    编译器一般不对普通局部变量进行初始化，也就是说它的值在初始时是不确定的，除非对其显式赋值。
    普通局部变量存储于进程栈空间，使用完毕会立即释放。
(2) 静态局部变量
    静态局部变量使用static修饰符定义，即使在声明时未赋初值，编译器也会把它初始化为0。
    静态局部变量存储于进程的全局数据区，即使函数返回，它的值也会保持不变。
(3) 静态全局变量
    全局变量定义在函数体外部，在全局数据区分配存储空间，且编译器会自动对其初始化。
    普通全局变量对整个工程可见，其他文件可以使用extern外部声明后直接使用。也就是说其他文件不能再定义一个与其相同名字的变量了（否则编译器会认为它们是同一个变量）。
    静态全局变量仅对当前文件可见，其他文件不可访问，其他文件可以定义与其同名的变量，两者互不影响。
(4) 静态函数
    函数的使用方式与全局变量类似，在函数的返回类型前加上static，就是静态函数。
    静态函数只能在声明它的文件中可见，其他文件不能引用该函数；不同的文件可以使用相同名字的静态函数，互不影响
(5) 在头文件中定义static变量会造成变量多次定义，造成内存空间的浪费，而且也不是真正的全局变量。应该避免使用这种定义方式。
*/

void f3();

int main(int argc, char const *argv[])
{
    // f1(); // undefined reference to `f1'

    printf("n1 = %ld, n2 = %ld\n", n1, n2);
    f2();
    n1 = 1199;
    n2 = 1188;
    // n3 = 1166; // error: 'n3' undeclared (first use in this function);
    set_n3(1166);
    printf("n1 = %ld, n2 = %ld\n", n1, n2);
    printf("n1_addr=%p\n", &n1);
    f2();

    f3();
    f3();
    f3();
    f3();
    // printf("counter = %ld\n", counter); // error: 'counter' undeclared (first use in this function)

    return EXIT_SUCCESS;
}

void f3()
{
    int64_t static counter = 0;
    ++counter;
    printf("counter=%ld\n", counter);
    return;
}